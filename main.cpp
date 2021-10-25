#include "functions.hpp"
using namespace std;

int main(){

    vector<users> vartotojai = generate_users(1000);
    vector<transactions> transakcijos = generate_transactions(10000, vartotojai);


    //tst
    // cout << vartotojai[990].name << " "
    // << vartotojai[990].public_key << " "
    // << vartotojai[990].balance << endl;

    // cout << vartotojai[110].name << " "
    // << vartotojai[110].public_key << " "
    // << vartotojai[110].balance << endl;

    // cout << transakcijos[999].transaction_id_hash << " "
    // << transakcijos[999].sender_public_key << " "
    // << transakcijos[999].recipient_public_key << " "
    // << transakcijos[999].total << endl;

    // cout << transakcijos[7777].transaction_id_hash << " "
    // << transakcijos[7777].sender_public_key << " "
    // << transakcijos[7777].recipient_public_key << " "
    // << transakcijos[7777].total << endl;

}