/*
Details: 
delete the element in an array
    if not found, print a message
    if found, print index and then print the new array


*/


#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 8;
    int numbers[SIZE] = { 2, 3, 4, 5, 6, 7, 8, 9};
    int index = 0, key ;

    cout << "Which element do you want to delete? ";
    cin >> key;
    cout << endl;
    bool keyFound = false;
    
    //finds the index at which the element we want to delete is found
    for(int i = 0; i < SIZE; i++){
        if(numbers[i] == key){
            keyFound = true;
            index = i;
            break;
        }
    }
    if(keyFound){
        //delete the element by shifting left one
        //total size decreases by 1
        for(int i = index; i < SIZE - 1; i++){
            numbers[i] = numbers[i + 1];
        }
        cout << key << " was found at index " << index << endl;
        cout << "The new array is : ";

        for(int i = 0; i < SIZE - 1; i ++){
            cout << numbers[i] << " ";
        }
    }
    else{
        cout << key << " was not found" << endl;
    }
    /*
    
    Enter code
    
    */
}
