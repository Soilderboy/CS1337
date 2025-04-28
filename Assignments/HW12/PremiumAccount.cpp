#include "PremiumAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

//static const
const double PremiumAccount::MIN_BALANCE = 1000.0;

//constructor by calling base class constructor
PremiumAccount::PremiumAccount(string nam, double amnt, Date d)
     : Account(nam, amnt, d){
}
//withdraw function, check if balance is greater than min balance
bool PremiumAccount::withdraw(double amnt, Date d){
    (void) d; 
    if(balance - amnt >= MIN_BALANCE){
        balance -= amnt;
        cout << "Withdraw executed: " << endl;
        //create a transaction struct and populate it
        Transaction t;
        t.date = d;
        t.transactionType = 2; //2 for withdrawal
        t.amount = amnt;
        //record transaction into transactionHistory
        recordTransaction(t);
        return true;
    }
    else{
        cout << "Insufficient balance, withdrawal not executed" << endl;
        return false;
    }
}

//get min balance
double PremiumAccount::getMinBalance(){
    return MIN_BALANCE;
}
//print function, add on to base class print
void PremiumAccount::print() const{
    cout << "Premium account, ";
    this->Account::print();
}