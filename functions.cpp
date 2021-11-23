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

block_header gen_block(int difficulty, int nonce, vector<transactions> &transaction){
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

    // if(blocknum == 0) block.prev_block_hash = "-";
    // else block.prev_block_hash = block.block.back().block_hash;

    block.timestamp = time(0);
    block.version = "v0.1";

    block.merkel_root_hash = hashing(all_transactions); //hashing(merkle_root(block.transactions));
    block.nonce = nonce;
    block.block_hash = hashing(to_string(nonce));

    

    return block;
}



//--- printing ---

void print_bc_info(vector<block_header> blockchain){
    ofstream out;
    out.open("bc_info.txt");

    for(int i = 1; i <= blockchain.size(); i++){

        out << "Block " << i << endl
        << endl
        << "Hash: " << blockchain.at(i).block_hash << endl
        << "Timestamp: " << /*timestampas*/ endl
        << "Version: " << blockchain.at(i).version << endl
        << "Merkel Root Hash: " << blockchain.at(i).merkel_root_hash << endl
        << "Number of transactions: " << blockchain.at(i).transactions.size() << endl
        << "Nonce: " << blockchain.at(i).nonce << endl
        << "Difficulty: " << blockchain.at(i).difficulty_target << endl
        << "---------------------------------" << endl << endl;
    }
    
    out.close();
}