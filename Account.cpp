#include "Account.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Account::numberAccounts = 0;

//constructor
//accountNumber is numberAccounts+1000 and increment numberAccounts
//date_ is placeholder for extra credit
Account::Account(string nam, double bal, Date d){
    (void) d; //silence unused parameter warnings
    ownerName = nam;
    balance = bal;
    accountNumber = 1000 + numberAccounts;
    numberAccounts++;
    transactionHistory = nullptr; //placeholder for extra credit
    numberTransactions = 0; //placeholder for extra credit will do later
    //date_ = d; //placeholder for extra credit

}

//withdraw function - virtual
//check if there is sufficient balance, then process withdraw and return true, otherwise no withdrawal made and return false
//and make sure to deduct from balance if withdraw goes through
bool Account::withdraw(double amnt, Date d){
    (void) d;
    if(amnt > balance){
        cout << "Insufficient balance, withdrawal not executed" << endl;
    }
    else if(amnt <= 0){
        cout << "Amount cannot be negative, withdraw not executed" << endl;
    }
    else{
        balance -= amnt;
        cout << "Withdraw executed: " << endl;
        return true;
    }
    return false;
}

//deposit function
//check if amount is positive, then process
//otherwise do not process and return false
//if made, add to balance
bool Account::deposit(double amnt, Date d){
    (void) d;
    if(amnt <= 0){
        cout << "Amount cannot be negative, deposit not executed" << endl;
    }
    else{
        balance += amnt;
        cout << "Deposit executed: " << endl;
        return true;
    }
    return false;
}   

//getters
int Account::getAccountNumber() const{
    return accountNumber;
}
double Account::getBalance() const{
    return balance;
}
int Account::getNumberAccounts(){
    return numberAccounts;
}

//print function
//virtual function that prints accountNumber, ownerName, balance (used when user chooses print info for all accounts in menu)
void Account::print() const{
    //since we don't know if it's a reg/premium account, we'll print whatever's in the base class
    cout << "#: " << accountNumber << ", Name: " << ownerName << ", Balance: " << fixed << setprecision(2) << balance << " Galactic units" << endl;
}