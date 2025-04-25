#include "PremiumAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

//static const
const double PremiumAccount::MIN_BALANCE = 1000.0;

//constructor by calling base class constructor
PremiumAccount::PremiumAccount(string nam, double amnt, Date d)
     : Account(nam, amnt, d){
    cout << "PremiumAccount constructor called" << endl; //for debugging
}
//withdraw function, check if balance is greater than min balance
bool PremiumAccount::withdraw(double amnt, Date d){
    if(balance - amnt >= MIN_BALANCE){
        balance -= amnt;
        cout << "Withdraw executed" << endl;
        return true;
    }
    else{
        cout << "Withdraw not executed" << endl;
        return false;
    }
}