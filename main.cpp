#include "functions.hpp"
using namespace std;


int main(){

    ofstream out;
    out.open("bc_info.txt", fstream::trunc);    //trunc output

    //pagrindinis programos veikimas
    
    // // cout << "kuriami vartotojai" << endl;
    vector<users> vartotojai = gen_users(1000);
    // // cout << "kuriamos transakcijos" << endl;
    vector<transactions> transakcijos = gen_transactions(10000, vartotojai);



    // -------------
    vector<block_header> blocks;

    int difficulty_target = 2;
    int i = 0;

    while(transakcijos.size() > 0){
        while(true){
            int diff_0_found = 0;
            unsigned int numonce = random_num(0, INT_MAX);
            string numonce_hash = hashing(to_string(numonce));

            for(int j = 0; j < difficulty_target; j++){
                if(numonce_hash[j] == '0') diff_0_found++;
            }



            // cout << "Mining block " << i << endl;

            if(diff_0_found == difficulty_target){
                blocks.push_back(gen_block(difficulty_target, numonce, transakcijos, i));
                verify_tr(transakcijos, vartotojai, blocks);
                
                print_bc_info(blocks, i);

                i++;
            }
        }
    }
}