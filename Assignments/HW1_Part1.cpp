#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
    // Initialize left and right indices
    // Enter your code here

    int left = 0, right = str.length() - 1;

    //loop through string and check left and right characters
    //warning from str.length if i is not unsigned
    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;

   
}


int main()
{
    string str;

    cout << "Enter the name of the string: ";

    cin >> str;
    // check if the string is palindrome or not
    if(isPalindrome(str)){
        cout << "The given string is a palindrome. \n";
    }
    else{
        cout << "The given string is not a palindrome. \n";
    }
    
    
    /*
    Enter your code
        cout << "The given string is a palindrome. \n";

        cout << "The given string is not a palindrome. \n";
        
        */
}