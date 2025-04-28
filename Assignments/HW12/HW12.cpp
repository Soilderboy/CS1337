/*
Create a way to create a bank account with either regular or premium, allow options to deposit, withdraw, print info, and quit

Bank account needs:
    owner name (e.g. R2-D2)
    Date in mm/dd/yyyy/hh format
    Amount
    And that will create an account
    Which will display the type of account, #: account number, owner name, balance in galactic units

    Same thing for 2 but it is a premium account

That's about it - everything else is just to do this

What are the different classes for?
    Account - base class
    Regular - derived class
    Premium - derived class
    Date - class to hold date
    extra credit - implement recordTransaction, a member function of Account
        takes argument of type Transaction class
        Transaction history is an array of Transaction structs
        initially the history is empty, no array is allocated
        To have the first transaction recorded, we do dynamic memory and populate it

Note:
    no need for input validation
    all data items do not contain whitespace and thus cin works for all data

In main:
    while true
        print menu

        switch choice
            //max number of accounts is 5
            case 1: create regular account
            case 2: create premium account (premium accounts have a min balance of 1000)
            case 3: deposit (must fail if amount is negative or zero)
            case 4: withdraw (must fail gracefully)
            case 5: print info for ALL accounts
            case 6: quit

call destructor for all accounts
return 0;


Extra credit:
    It's a transaction history addition
    Record when account is created, deposits, withdrawals
    Need to implement recordTransaction and printTransactions in ACcount class

    Dynamically allocate an array of Transaction structs with a size of 1 and populating it

    recordTransaction(Transaction t) add t to the transactionHistory, returns void

    printTransactions() accessor that prints the array of transactions and is called by main function when user chooses "print info for all accounts"

Extra credit account class:
    Account constructor will 
        accountNumber set to numberAccounts+1000
        numberAccounts is incremented
        transactionHistory set to nullptr
        numberTransactions set to zero
        Transaction struct is statiscally created and populated 
        recordTransaction function is called to record account creation
        numberTransactions is incremented

    Withdraw (in account)
        Transaction struct is statiscally created and populated,
        recordTransaction function is called to record withdraw
        numberTransactions is incremented

    Deposit (in account)
        same logic as withdraw

    Same for PremiumAccount's withdraw which will override the base class withdraw
*/
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"
#include "Date.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

//set up the menu by dynamically allocating account objects and putting them in an array when created
//then call appropriate functions to deposit, withdraw, print info, and quit
const int MAX_NUM_ACCOUNTS = 5;
Account * accountArray[MAX_NUM_ACCOUNTS] = {nullptr};

int numAccounts = 0;

//function prototypes for reading input
string readName();
Date readDate();
double readAmount();
int readAccountNumber();

//function prototypes for menu options
//comments about each function are located in the function definitions if not self-explanatory
void createRegularAccount();
void createPremiumAccount();
void deposit();
void withdraw();
void printInfo();
void printMenu();

int main()
{
    int choice;
    do{
        cout << endl;
        printMenu();
        cin >> choice;
        if(cin.fail()){
            cin.clear(); //clear fail state
            cin.ignore(1000, '\n');
            choice = -1; //force invalid choice
        }

        switch(choice){
            case 1:
                createRegularAccount();
                break;
            case 2:
                createPremiumAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printInfo();
                break;
            case 6:
                break; //exit loop
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while(choice != 6);
    //exit
    /*
    for(int i = 0; i < numAccounts; i++){
        delete accountArray[i]; //delete all accounts (will delete if not nullptr)
        accountArray[i] = nullptr;
    }
    */
    //delete all accounts - will worry about this later
    //clear leftover input
    return 0;
}
string readName(){
    string name;
    cout << "Enter owner's name: " << flush;
    cin >> name;
    return name;
}

Date readDate(){
    Date date;
    cout << "Enter date, in the mm/dd/yyyy/hh format: " << flush;
    int month, day, year, hour;
    char slash1, slash2, slash3; //to read slashes
    cin >> month >> slash1 >> day >> slash2 >> year >> slash3 >> hour;
    date.set(month, day, year, hour);
    return date;
}

double readAmount(){
    double amount;
    cout << "Enter amount: " << flush;
    cin >> amount;
    return amount;
}

int readAccountNumber(){
    int accountNumber;
    cout << "Enter account number: " << flush;
    cin >> accountNumber;
    return accountNumber;
}
void createRegularAccount(){
    if(numAccounts >= MAX_NUM_ACCOUNTS){
        cout << "Max number of accounts reached, cannot add a new account" << endl;
        return;
    }
    string name;
    double amount;
    Date date;

    name = readName();
    date = readDate();
    amount = readAmount();
    if(amount < 0){
        cout << "Amount cannot be negative, account creation not executed" << endl;
        return;
    }

    accountArray[numAccounts] = new RegularAccount(name, amount, date);
    numAccounts++;
    cout << "Account created: " << endl;
    accountArray[numAccounts-1]->print(); //since numAccounts is incremented, we print the -1
}

void createPremiumAccount(){
    if(numAccounts >= MAX_NUM_ACCOUNTS){
        cout << "Max number of accounts reached, cannot add a new account" << endl;
        return;
    }
    string name;
    double amount;
    Date date;

    name = readName();
    date = readDate();
    amount = readAmount();
    if(amount < 0){
        cout << "Amount cannot be negative, account creation not executed" << endl;
        return;
    } else if(amount < PremiumAccount::getMinBalance()){
        cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account" << endl;
        return;
    }

    accountArray[numAccounts] = new PremiumAccount(name, amount, date);
    numAccounts++;
    cout << "Account created: " << endl;
    accountArray[numAccounts-1]->print(); //since numAccounts is incremented, we print the -1
}

void deposit(){
    int accountNumber;
    double amount;
    Date date;

    //read account number, if it exists, then read date and amount
    accountNumber = readAccountNumber();

    for(int i = 0; i < numAccounts; i++){
        if(accountArray[i]->getAccountNumber() == accountNumber){
            date = readDate();
            amount = readAmount();        
            bool success = accountArray[i]->deposit(amount, date);
            //print out account info after deposit
            if(success){
                accountArray[i]->print();
            }
            return;
        }
    }
    //if it doesn't exist, print out error message
    cout << "No such account" << endl;
}

void withdraw(){
    int accountNumber;
    double amount;
    Date date;
    //read account number, if it exists, then read date and amount
    accountNumber = readAccountNumber();

    for(int i = 0; i < numAccounts; i++){
        if(accountArray[i]->getAccountNumber() == accountNumber){
            date = readDate();
            amount = readAmount();
            bool success = accountArray[i]->withdraw(amount, date);
            //print out account info after withdraw
            if(success){
                accountArray[i]->print();
            }
            return;
        }
    }
    //if it doesn't exist, print out error message
    cout << "No such account" << endl;
}
//print info for all accounts
void printInfo(){
    cout << "Accounts" << endl;
    cout << "========" << endl;
    cout << endl;
    for(int i = 0; i < numAccounts; i++){
        accountArray[i]->print();

        //print out transaction history if extra credit is implemented
        #ifdef EXTRA_CREDIT
        accountArray[i]->printTransactions();
        #endif

        //if it's the last account, don't endl
        if(i != numAccounts - 1){
            cout << endl;
        }
    }
}
//print menu but leave the choice for main function
void printMenu(){
    cout << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl;
    cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
}
