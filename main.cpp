#include "functions.hpp"
using namespace std;




int main(){

    //pagrindinis programos veikimas
    
    // // cout << "kuriami vartotojai" << endl;
    vector<users> vartotojai = gen_users(1000);
    // // cout << "kuriamos transakcijos" << endl;
    vector<transactions> transakcijos = gen_transactions(10000, vartotojai);

    //tst
    // cout << vartotojai[110].name << " "
    // << vartotojai[110].public_key << " "
    // << vartotojai[110].balance << endl;
    // --
    // cout << transakcijos[7777].transaction_id_hash << " "
    // << transakcijos[7777].sender_public_key << " "
    // << transakcijos[7777].recipient_public_key << " "
    // << transakcijos[7777].total << endl;






    // -------------
    vector<block_header> blocks;
    // vector blockchain;

    int difficulty_target = 2;
    int i = 1;

    while(transakcijos.size() > 0){

        unsigned int numonce = random_num(0, INT_MAX);
        string numonce_hash = hashing(to_string(numonce));




        cout << "Mining block " << i << endl;

        blocks.push_back(gen_block(difficulty_target, numonce, transakcijos));

        i++;

        if(i > 100){
        print_bc_info(blocks);}
    }

    // cout << blocks.at(3).nonce;
    

    // cout << "tst" << endl;
    // print_bc_info(blocks);

}





// DO TIMESTAMP, FIX PRINT, DIFFICULTY COMPARISON WITH 0, GIT README