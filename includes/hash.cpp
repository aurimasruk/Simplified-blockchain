#include "hash.hpp"

string hashing(string hashInput){
    if(hashInput == " ") return "961b6dd3ede3cb8ecbaacbd68de040cd78eb2ed5889130cceb4c49268ea4d506";

    const int initial_hash_seed = 9464;                 // initial seed
    unsigned int initial_hash = initial_hash_seed;

    for(int i = 0; i <= hashInput.length(); i++){       // random h
        initial_hash = (initial_hash * 47) + int(hashInput[i]) + hashInput.length() * 27;
    }

    string initial_hash_str = to_string(initial_hash);      // 4 choosing char
    int initial_hash_str_size = initial_hash_str.size();
    
    const string hex = "0123456789abcdef";          // hex str
    string hashOutput;

    unsigned int random_var = initial_hash * initial_hash_seed;     // random variable
    int random_num = 17;

    for(int i = 0; i < 64; i++){        // for 64c // randomizing var // creating hashout
        random_var += initial_hash_str[i * random_num % initial_hash_str_size] + initial_hash_seed * i * 3;
        hashOutput += hex[random_var % 16];
        random_num = random_num * 3 - 11;
    }

    return hashOutput;
}