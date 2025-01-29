/*
Details: Given a string s, rotate it by k positions to the right

Get s and k from input

Cut k characters from the beginning and past it to the end

Psuedocode:
get input s and k
create a new string s1
s1 = substring of s from k to end
s1 += substring of s from 0 to k
output s1


*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int k;
    string s1;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    //k for starting position, second parameter is length
    s1 = s.substr(k, s.length() - k);
    s1 += s.substr(0, k);

    cout << s1 << endl;
}