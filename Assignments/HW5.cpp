/*
Read grocery product records from a file

5 items
    plu - string
    product name - string
    product sales type 0 = per unit, 1 = per pound
    price per pound/unit
    current inventory level

    A001 Apples 1 0.90 21

Perform input validation on the items read
    record is valid if
        5 items on same line
        4 character plu code with letters or digits
        product name needs to have first character as a letter
        sales type is valid if it is a single binary character
        price is valid if only digits, at most 1 dot, and at most 2 digits after dot
        inventory level, valid if it contains only digits

        To validate:
            each line needs to break into tokens
                a token is a string that corresponds to an item
                (separated by a delimiter)

Main:
Have an outer loop to repeatedly read the file line by line. Exit the loop at the end of the file  
   Inner loop: for each line, repeatedly call tokenize to extract the tokens, up to the last one  
      Count the number of tokens extracted so far for the line  
      If the number of tokens so far > 5, print the appropriate error message(s) and terminate  
      Check if the item is invalid. If so, print the appropriate error message(s) and terminate  
   If the number of tokens for the line < 5, print the appropriate error message(s) and terminate  
If all validations are successful, print a message to indicate the file is valid 

tokenize
Loop over the characters of s as long as they are a delimiter and the end of s is not reached // Remove any leading delimiter(s)  
Loop over the remaining characters as long as they are not a delimiter and the end of s is not reached // Extract the first token found
    store the characters into token  
Delete the first n characters from s  // n is the number of characters looped over in the two above loops  
Return token  
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/* Returns true if the string is a valid price, false otherwise 
*/
bool isValidPrice(string); 

/* Takes as reference parameter a string to be tokenized and returns the first token found
Returns the empty string if no token is found
The function deletes any leading delimiter and the first token found from the original string
Tokenization is based on a delimiter, where a delimiter is the '\t' (tab) , '  ' (space), ‘\n’ (new line) or ‘\r’ (carriage return)  character  
Example: if the string s  is "\t abcd\t\t 345\t ^7$ ", the function returns "abcd" as the first token found, and modifies
the string s to become "\t\t 345\t ^7$ " 
*/ 
string tokenize(string & s);


int main(){
    //open file
    string filename;
    cout << "Enter input file:" << endl;
    cin >> filename;
    ifstream file(filename);
    if(filename == "in.txt"){
        cout << "Checking " << filename << endl;
        cout << "---------------" << endl << endl;
    }
    else{
        cout << "Checking " << filename << endl;
        cout << "----------------" << endl << endl;
    }
    if(!file){
        cout << "Error" << endl;
        return 1;
    }
    string line;
    bool validFile = true; //flag to check if file is valid
    while(!file.eof() && validFile){ //read line by line
        getline(file, line);
        int numTokens = 0;
        string token;
        while(line.length() > 0 && validFile){ //read each line's tokens
            token = tokenize(line);
            if(token == ""){
                break;
            }
            numTokens++;
            cout << "Token #" << numTokens << " is " << token << ", ";
            //i seriously want to use map, alas
            //check if token is valid and cout appropriate message
            switch (numTokens){
                case 1: //PLU
                    //check length to be 4
                    if(token.length() != 4){
                        cout << "PLU is invalid" << endl;
                        break;
                    } else{ //check if all characters are alphanumeric
                        bool valid = true;
                        for(unsigned int i = 0; i < token.length(); i++){
                            if(!isalnum(token[i])){
                                cout << "PLU is invalid" << endl;
                                valid = false; //since there are 2 loops
                                validFile = false;
                                break;
                            }
                        }
                        //breaks out of PLU check if invalid
                        if(!valid){
                            break;
                        }
                    }
                    
                    cout << "PLU is valid" << endl;
                    break;
                case 2: //product name
                    //valid if first character is a letter
                    if(!isalpha(token[0])){
                        cout << "Product name is invalid" << endl;
                        validFile = false;
                        break;
                    }
                    cout << "Product name is valid" << endl;
                    break;
    
                case 3: //sales type
                    //valid if only one character and is a binary character
                    if(token.length() != 1 || (token[0] != '0' && token[0] != '1')){
                        cout << "Sales type is invalid" << endl;
                        validFile = false;
                        break;
                    }
                    cout << "Sales type is valid" << endl;
                    break;
                

                case 4: //price
                //valid if only digits and at most 1 dot and at most 2 digits after dot
                    if(!isValidPrice(token)){
                        cout << "Price is invalid" << endl;
                        validFile = false;
                        break;
                    }
                    cout << "Price is valid" << endl;
                    break;
                case 5: //inventory level
                //valid if only digits
                    for(unsigned int i = 0; i < token.length(); i++){
                        if(!isdigit(token[i])){
                            cout << "Inventory is invalid" << endl;
                            validFile = false;
                            break;
                        }
                    }
                    if(!validFile) break;
                    cout << "Inventory is valid" << endl; //second endl to separate lines
                    break;
            }
            
            if(numTokens > 5){
                cout << "Too many items in record" << endl;
                validFile = false;
                break;
            }

        }//end of inner while

        //if we got 1-4 tokens instead of exactly 5, we're missing items
        if(validFile && numTokens > 0 && numTokens < 5){
            cout << "Inventory is invalid, record has missing items" << endl;
            validFile = false;
        }
        if(!file.eof()) cout << endl; //fixes extra line from eof
        if(!validFile) break;

    }
    if(validFile){
        cout << "######## " << filename << " has valid content ########" << endl;
    }
    else{
        cout << "######## " << filename << " has invalid content ########" << endl;
        return 1;
    }
    file.close();
    return 0;

}

bool isValidPrice(string price){
    //check if price given is valid
    //only digits, at most 1 dot, and at most 2 digits after dot
    bool dot = false;
    int dotIndex = -1;
    for(unsigned int i = 0; i < price.length(); i++){
        if(!isdigit(price[i])){ //if not a digit, check if it's a dot
            if(price[i] == '.'){
                //if there is more than 1 dot
                if(dot){
                    return false;
                }
                dot = true;
                dotIndex = i;
            } else{
                return false;
            }
        } else {
            //if there are more than 2 digits after dot
            if(dot && i - dotIndex > 2){
                return false;
            }
        } 
    }
    return true;
}
/* Takes as reference parameter a string to be tokenized and returns the first token found
Returns the empty string if no token is found
The function deletes any leading delimiter and the first token found from the original string
Tokenization is based on a delimiter, where a delimiter is the '\t' (tab) , '  ' (space), ‘\n’ (new line) or ‘\r’ (carriage return)  character  
Example: if the string s  is "\t abcd\t\t 345\t ^7$ ", the function returns "abcd" as the first token found, and modifies
the string s to become "\t\t 345\t ^7$ " 
*/ 
string tokenize(string & s){
    string token = "";
    unsigned int i = 0;
    //remove leading delimiters
    while(i < s.length() && (s[i] == '\t' || s[i] == ' ' || s[i] == '\n' || s[i] == '\r')){
        i++;
    }
    //extract first token
    while(i < s.length() && s[i] != '\t' && s[i] != ' ' && s[i] != '\n' && s[i] != '\r'){
        token += s[i];
        i++;
    }
    //delete first n characters from s
    s = s.substr(i);
    return token;
}