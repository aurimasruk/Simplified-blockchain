#include "functions.hpp"

int random_num(int x, int y){ return ((rand() % y) + x); }

vector<users> generate_users(int size){
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


vector<transactions> generate_transactions(int size, vector<users>users){
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