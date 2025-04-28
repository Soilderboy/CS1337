#include "RegularAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructor by calling base class constructor
RegularAccount::RegularAccount(string nam, double amnt, Date d)
     : Account(nam, amnt, d){
}
//print function, add on to base class print
void RegularAccount::print() const{
    cout << "Regular account, ";
    this->Account::print();
}