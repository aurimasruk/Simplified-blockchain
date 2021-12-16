#include "functions.hpp"
using namespace std;
std:: random_device rand_d;

int main(){

    ofstream out;
    out.open("bc_info.txt", fstream::trunc);    //trunc output

    auto rng = default_random_engine{rand_d()};

    //pagrindinis programos veikimas
    
    // // cout << "kuriami vartotojai" << endl;
    vector<users> vartotojai = gen_users(1000);
    // // cout << "kuriamos transakcijos" << endl;
    vector<transactions> transakcijos = gen_transactions(10000, vartotojai);

    vector<int> rnd_num = {0, 1, 2, 3, 4};  // for 5 blocks

    // -------------
    vector<block_header> blocks;

    int difficulty_target = 2;      // takes a long time with 3 or more
    int i = 0;

    if(transakcijos.empty()) throw std::runtime_error("empty transactions");

    while(blocks.size() < 5 ){   // generating 5 blocks
        int diff_0_found = 0;
        unsigned int numonce = random_num(0, INT_MAX);
        string numonce_hash = hashing(to_string(numonce));

        for(int j = 0; j < difficulty_target; j++){
            if(numonce_hash[j] == '0') diff_0_found++;
        }

        shuffle(rnd_num.begin(), rnd_num.end(), rng);


        // cout << "Mining block " << i << endl;
        // clock_t start = clock();
        
        if(diff_0_found == difficulty_target){
            // cout << "test" << endl;


            blocks.push_back(gen_block(difficulty_target, numonce, transakcijos, rnd_num[i]));
            // verify_tr(transakcijos, vartotojai, blocks);
            
            // print_bc_info(blocks, i);

            // if(((clock() - start)/ CLOCKS_PER_SEC ) <= 5) break;

            i++;
        }  
        // else if(diff_0_found == difficulty_target) {cout << "Pereinama prie kito bloko" << endl;}
        
    }
    for(i = 0; i < 5; i++) print_bc_info(blocks, i);

}