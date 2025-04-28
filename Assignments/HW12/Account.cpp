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
    transactionHistory = nullptr; //first transactionHistory is set to nullptr
    numberTransactions = 0; //placeholder for extra credit will do later

    //record the first transaction (account creation)
    Transaction t;
    t.date = d;
    t.transactionType = 0; //0 for account creation
    t.amount = bal;
    recordTransaction(t); //record the Transaction into an array

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
        //create a transaction struct and populate it
        Transaction t;
        t.date = d;
        t.transactionType = 2; //2 for withdrawal
        t.amount = amnt;
        //record transaction into transactionHistory
        recordTransaction(t);
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
        //create a transaction struct and populate it
        Transaction t;
        t.date = d;
        t.transactionType = 1; //1 for deposit
        t.amount = amnt;
        //record transaction into transactionHistory
        recordTransaction(t);
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

/* This function takes as argument a Transaction structure variable and
adds it to the transaction history. The transaction history
is implemented as an array of Transactions. A new array is dynamically allocated, 
of size equal to (size of old array) + 1, to hold the added transaction.
The values of the old array are copied into the new array, 
and the transaction to be added is copied into the last element of the new array. 
The old array is released through delete. The address returned from dynamic array allocation is assigned  to transactionHistory.
*/
void Account::recordTransaction(Transaction t){   
    //allocate new array of size current size + 1
    Transaction * newTransactionHistory = new Transaction[numberTransactions + 1];
    //copy old array into new array
    for(int i = 0; i < numberTransactions; i++){
        newTransactionHistory[i] = transactionHistory[i];
    }
    //add new transaction at the end
    newTransactionHistory[numberTransactions] = t;
    //delete old array
    delete[] transactionHistory;
    //update transactionHistory pointer
    transactionHistory = newTransactionHistory;
    //increment numberTransactions
    numberTransactions++;

}
#ifdef EXTRA_CREDIT
//print transaction history
//this function is called in the main function when user chooses print info for all accounts
//it prints the transaction history for each account
void Account::printTransactions() const{
    //check if transaction is nullptr
    if(transactionHistory == nullptr){
        return;
    }
    //set up an array of strings for transaction types
    static const string transactionTypes[3] = {"Creation", "Deposit", "Withdrawal"};
    //set up a running balance
    double runningBalance = 0.0;
    cout << "Transaction history:" << endl;
    cout << "-------------------" << endl;
    //formatting for output
    for(int i = 0; i < numberTransactions; i++){
        cout << "Date: ";
        transactionHistory[i].date.print();
        cout << ", "
            << "Amount: " << fixed << setprecision(2) << transactionHistory[i].amount << ", "
            << "type: " << transactionTypes[transactionHistory[i].transactionType] << ", ";

        //update running balance depending on transaction type
        if(transactionHistory[i].transactionType == 0){
            runningBalance = transactionHistory[i].amount;
        }
        else if(transactionHistory[i].transactionType == 1){
            runningBalance += transactionHistory[i].amount;
        }
        else if(transactionHistory[i].transactionType == 2){
            runningBalance -= transactionHistory[i].amount;
        }
        cout << "New balance: " << fixed << setprecision(2) << runningBalance << endl;

    }

}
#endif