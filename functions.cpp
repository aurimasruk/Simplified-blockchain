#include "functions.hpp"

int random_num(int x, int y){ return ((rand() % y) + x); }

string merkle_root(vector<transactions> transactions){

    if(transactions.empty()) throw std::runtime_error("empty transactions");

    vector<string> tr;  // copy of transactions

    for(int i = 0; i < transactions.size(); i++){
        tr.push_back(transactions[i].transaction_id_hash);
    }


    while(tr.size() > 1){
        vector<string> temp_tr;

        if(tr.size() % 2 != 0 ){ tr.push_back(tr.back()); };    // if odd num add last el

        for(int i = 0; i < tr.size() / 2; i++){
            temp_tr.push_back( hashing(tr[i] + tr[i+1]) );      // hashing
        }
        tr = temp_tr;
    }

    return tr[0];
}


vector<users> gen_users(int size){
    vector<users> vartotojai;

    for(int i = 0; i < size; i++){
        users naujas_vartotojas;
        naujas_vartotojas.name = "Vartotojas_" + to_string(i);
        naujas_vartotojas.public_key = hashing(naujas_vartotojas.name);
        naujas_vartotojas.balance = random_num(100, 1000000);
        vartotojai.push_back(naujas_vartotojas);
    }
    return vartotojai;
}

// finding id for validation

int find_user(vector<users> users, string public_key){
    for(int i = 0; i < users.size(); i++){
        if(users.at(i).public_key == public_key){
            return i;
        }
    }
    return -11;
};


vector<transactions> gen_transactions(int size, vector<users> users){
    vector<transactions> transakcijos;

    for(int i = 0; i < size; i++){
        transactions nauja_transakcija;
        int sender_id = random_num(0, 999);
        nauja_transakcija.sender_public_key = users[sender_id].public_key;
        nauja_transakcija.recipient_public_key = users[random_num(0, 999)].public_key;
        
        while(nauja_transakcija.sender_public_key == nauja_transakcija.recipient_public_key){
            nauja_transakcija.recipient_public_key = users[random_num(0, 999)].public_key;
        }
        nauja_transakcija.total = users[sender_id].balance / 10;

        nauja_transakcija.transaction_id_hash = hashing(nauja_transakcija.sender_public_key + nauja_transakcija.recipient_public_key + to_string(nauja_transakcija.total));

        transakcijos.push_back(nauja_transakcija);
    }

    //verifying transaction

    for(int i = 0; i < size; i++){

        int sender_id = find_user(users, transakcijos.at(i).sender_public_key);
        int receiver_id = find_user(users, transakcijos.at(i).recipient_public_key);

        if(sender_id == -11 || receiver_id == -11)  // error with transaction
        transakcijos.erase( transakcijos.begin() + i );

        
        else if(transakcijos.at(i).total <= users[sender_id].balance 
        || hashing(transakcijos.at(i).sender_public_key + transakcijos.at(i).recipient_public_key + to_string(transakcijos.at(i).total)) == transakcijos.at(i).transaction_id_hash)
            {
                users[sender_id].balance -= transakcijos.at(i).total;          // sender 
                users[receiver_id].balance += transakcijos.at(i).total;          // receiver
            }

        else transakcijos.erase( transakcijos.begin() + i );

    }



    return transakcijos;
}

block_header gen_block(int difficulty, int nonce, vector<transactions> &transaction, int blocknum){
    block_header block;

    //for v0.2
    string all_transactions = "";

    for(int i = 0; i < 100; i++){
        int transaction_id = random_num(0, transaction.size() - 1);
        block.transactions.push_back(transaction[transaction_id]);
        all_transactions += block.transactions.back().transaction_id_hash;
        transaction.erase(transaction.begin() + transaction_id);        // deleting from transaction pool
    }
    


    block.difficulty_target = difficulty;

    if(blocknum == 0) block.prev_block_hash = "-";
    else block.prev_block_hash = block.block_hash;

    block.timestamp = time(0);
    block.version = "v0.2";

    block.merkel_root_hash = //hashing(all_transactions); 
    hashing(merkle_root(block.transactions));
    block.nonce = nonce;
    block.block_hash = hashing(to_string(nonce));

    

    return block;
}

// Igyvendinta transaction generavime
// void verify_transactions(vector<transactions> &transakcijos, vector<users> &naudotojai, vector<block_header> &blokai){

//     // verifying hash

//     for(int i = 0; i < blokai[i].transactions.size(); i++){
//         // i need somehow to find sender and receiver
        
//     }


//     // verifying balance


// }

// Igyvendinta main()
// void mine_block(int difficulty_target, vector<users> &naudotojai, vector<transactions> &transakcijos, block_header &blocks){
    
//     int block_num = 5;
//     vector<block_header> pasirinkti_blokai;

//     // for(int i = 0; i < block_num; i++){
//     //     pasirinkti_blokai.push_back(gen_block(difficulty_target, ))
//     // }


// }

//--- printing ---

void print_bc_info(vector<block_header> blockchain, int j){

    ofstream out;
    out.open("bc_info.txt", fstream::app);

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);


    // for(int i = 1; i <= j; i++){

        int i = 0;

        out << "Block " << j + 1 << ": " << endl
        << endl
        << "Hash: " << blockchain.back().block_hash << endl
        << "Timestamp: " << std::ctime(&end_time)
        << "Version: " << blockchain.back().version << endl
        << "Merkel Root Hash: " << blockchain.back().merkel_root_hash << endl
        << "Number of transactions: " << blockchain.back().transactions.size() << endl
        << "Nonce: " << blockchain.back().nonce << endl
        << "Difficulty: " << blockchain.back().difficulty_target << endl << endl
        << "Block " << j + 1 << " transactions: " << endl;

        // for(int i = 0; i < blockchain.back().transactions.size())
        // cout << blockchain.at(j).transactions.size();

        // validating transactions
        // while(blockchain.at(j).transactions.size() >= 0 && i <= blockchain.at(j).transactions.size()){
            // for(int i = 0; i < ){}

            // if(blockchain.back().transactions.at(i).
            // && hashing(blockchain.back().transactions.at(i).sender_public_key + blockchain.back().transactions.at(i).recipient_public_key + to_string(blockchain.back().transactions.at(i).total)) )
            // {
            //     out << blockchain.back().transactions.at(i).sender_public_key << "  ->  " << blockchain.back().transactions.at(i).recipient_public_key;
                
            // }

            for(int i = 0; i < blockchain.at(j).transactions.size(); i++)
            out << blockchain.at(j).transactions.at(i).sender_public_key << "  -->  " << blockchain.at(j).transactions.at(i).recipient_public_key << endl;
            
        //     i++;
        // };

        out << "---------------------------------" << endl << endl;
    // }
    
    out.close();
}