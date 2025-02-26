/*
Details:
autogenerate random passwords

parameters (min len, max len, min lowercase letters, min uppercase, min # of digits, min # of special characters)

if requirements are not possible, return "invalid"
*/
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

const string specials = "!@#$%^&*+:;";

//returns a random character from all allowed ones.
char randomChar() {
        int r = rand() % (26+26+10+specials.length());
        if (r < 26)
            return (char) (r + 'a'); //lower case
        if (r < 52)
            return (char) (r - 26 + 'A'); //upper case
        if (r < 62)
            return (char) (r - 52 + '0'); //digit

        return specials[r-62]; //special char
}
string generatePassword(int minLength, int maxLength, int minLower, int minUpper, int minDigits, int minSpecial);
int main() {
   
    int minL, maxL, lower, upper, digits, specials;
    cout << "Enter minL, maxL, lower, upper, digits, specials values: ";
    cin >> minL>> maxL>> lower>> upper>> digits>> specials;
    cout  <<  generatePassword(minL, maxL, lower, upper, digits, specials) << endl;
    cout <<  generatePassword(8, 10, 2, 2, 2, 2);
}

string generatePassword(int minLength, int maxLength, int minLower, int minUpper, int minDigits, int minSpecial){
    string password = "";

    int minRequired = minLower + minUpper + minDigits + minSpecial;
    //check if requireements are possible, here because a negative modulus results in errors
    if(maxLength < minRequired) return "invalid";
    //figure out length using randomness 
    //+1 for inclusive
    int length = rand() % (maxLength - minRequired + 1) + minRequired; //minRequired is minimum length of password
    //figure out how many lowercase, uppercase, digits, and special characters
    int lower = minLower;
    int upper = minUpper;
    int digits = minDigits;
    int special = minSpecial;

    //remaining
    int remaining = length - minRequired;

    //distribute the remaining characters randomly among all categories
    while(remaining > 0){
        int choice = rand() % 4;
        if(choice == 0) lower++;
        else if(choice == 1) upper++;
        else if(choice == 2) digits++;
        else special++;
        remaining--;
    }

    //validate conditions
    if(remaining < 0 || lower + upper + digits + special != length || minLength > maxLength){
        return "invalid";
    }
    //generate password
    for(int i = 0; i < lower; i++) password += (rand() % 26 + 'a');
    for(int i = 0; i < upper; i++) password += (rand() % 26 + 'A');
    for(int i = 0; i < digits; i++) password += (rand() % 10 + '0');
    for(int i = 0; i < special; i++) password += specials[rand() % specials.length()];
    
    //shuffle
    for(int i = password.length() - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(password[i], password[j]);
    }

    return password;

}