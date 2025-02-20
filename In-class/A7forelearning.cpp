/*
Details:
make function dollarFormat

inserts commas where appropriate, has two decimals, and a dollar sign at the beginning

given a string objection modify it to this format
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void dollarFormat(string &s){
    unsigned int pos = s.find('.');
    //finds position where decimal point is and then adds leading zeros
    if(pos == s.size()-1){
        s += ".00";
    }
    else if(pos == s.size() - 2){
        s += "0";
    }
    //add commas
    pos = s.find('.');
    //we reset pos to decimal
    //then go back 3 digits and insert a comma for every 3 digits
    for(int i = pos - 3; i > 0; i -= 3){
        s.insert(i, ","); //insert will push everything to the right
    }
    //add dollar sign
    s.insert(0, "$");
    
}
//test
int main(){
    string s = "1084567.89";
    dollarFormat(s);
    cout << s << endl;
    s = "123.4";
    dollarFormat(s);
    cout << s << endl;
}