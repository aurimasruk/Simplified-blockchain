#include "functions.hpp"

int random_num(int x, int y){ return ((rand() % y) + x); }

// string merkle_root(vector<transactions> transaction){
    
// }


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
    return transakcijos;
}

block_header gen_block(int difficulty, int nonce, vector<transactions> &transaction, int blocknum){
    block_header block;

    //for v0.1
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
    block.version = "v0.1";

    block.merkel_root_hash = hashing(all_transactions); //hashing(merkle_root(block.transactions));
    block.nonce = nonce;
    block.block_hash = hashing(to_string(nonce));

    

    return block;
}



//--- printing ---

void print_bc_info(vector<block_header> blockchain, int j){
    ofstream out;
    out.open("bc_info.txt", fstream::app);

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);


    // for(int i = 1; i <= j; i++){

        out << "Block " << j + 1 << ": " << endl
        << endl
        << "Hash: " << blockchain.back().block_hash << endl
        << "Timestamp: " << std::ctime(&end_time)
        << "Version: " << blockchain.back().version << endl
        << "Merkel Root Hash: " << blockchain.back().merkel_root_hash << endl
        << "Number of transactions: " << blockchain.back().transactions.size() << endl
        << "Nonce: " << blockchain.back().nonce << endl
        << "Difficulty: " << blockchain.back().difficulty_target << endl
        << "---------------------------------" << endl << endl;
    // }
    
    out.close();
}