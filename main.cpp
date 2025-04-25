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
        printMenu();
        cin >> choice;

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
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while(choice != 6);
    //choice 6
    for(int i = 0; i < numAccounts; i++){
        delete accountArray[i]; //delete all accounts (will delete if not nullptr)
        accountArray[i] = nullptr;
    }
    return 0;
}
string readName(){
    string name;
    cout << "Enter owner's name: ";
    cin >> name;
    return name;
}

Date readDate(){
    Date date;
    cout << "\nEnter date, in the mm/dd/yyyy/hh format: ";
    int month, day, year, hour;
    char slash1, slash2, slash3; //to read slashes
    cin >> month >> slash1 >> day >> slash2 >> year >> slash3 >> hour;
    date.set(month, day, year, hour);
    return date;
}

double readAmount(){
    double amount;
    cout << "\nEnter amount: ";
    cin >> amount;
    return amount;
}

int readAccountNumber(){
    int accountNumber;
    cout << "\nEnter account number: ";
    cin >> accountNumber;
    return accountNumber;
}
void createRegularAccount(){
    if(numAccounts >= MAX_NUM_ACCOUNTS){
        cout << "Max number of accounts reached." << endl;
        return;
    }
    string name;
    double amount;
    Date date;

    name = readName();
    date = readDate();
    amount = readAmount();

    accountArray[numAccounts] = new RegularAccount(name, amount, date);
    numAccounts++;
    cout << "Account created:" << endl;
    accountArray[numAccounts-1]->print(); //since numAccounts is incremented, we print the -1
}

void createPremiumAccount(){
    if(numAccounts >= MAX_NUM_ACCOUNTS){
        cout << "Max number of accounts reached." << endl;
        return;
    }
    string name;
    double amount;
    Date date;

    name = readName();
    date = readDate();
    amount = readAmount();

    accountArray[numAccounts] = new PremiumAccount(name, amount, date);
    numAccounts++;
    cout << "Account created:" << endl;
    accountArray[numAccounts-1]->print(); //since numAccounts is incremented, we print the -1
}

void deposit(){
    int accountNumber;
    double amount;
    Date date;

    accountNumber = readAccountNumber();
    date = readDate();
    amount = readAmount();

    for(int i = 0; i < numAccounts; i++){
        if(accountArray[i]->getAccountNumber() == accountNumber){
            accountArray[i]->deposit(amount, date);
            return;
        }
    }
    cout << "Account not found." << endl;
}

void withdraw(){
    int accountNumber;
    double amount;
    Date date;

    accountNumber = readAccountNumber();
    date = readDate();
    amount = readAmount();

    for(int i = 0; i < numAccounts; i++){
        if(accountArray[i]->getAccountNumber() == accountNumber){
            accountArray[i]->withdraw(amount, date);
            return;
        }
    }
    cout << "Account not found." << endl;
}
void printInfo(){
    for(int i = 0; i < numAccounts; i++){
        accountArray[i]->print();
    }
}
//print menu but leave the choice for main function
void printMenu(){
    cout << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl;
    cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
}



