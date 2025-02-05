/*
Details: Create a binary search

array is 17 elements long

Find elemnt to search
Count iterations of binary search
Cout element is at index i
*/

#include <iostream>

using namespace std;

//prototype
int binarySearch(int list[], int key, int low, int high);

// function main begins program execution
int main()
{
    int list[] = { 2, 4, 7, 10, 11, 28, 34, 45, 50, 59, 60, 66, 69, 70, 75, 89, 95 };

    int key, first = 0, last = 16;
    cout <<"Enter the element to search: ";
    cin >> key;

    //index of key
    int i = -1;
    i = binarySearch(list, key, first, last);
    if(i != -1){
        cout << key <<  " is at index " << i << endl;
    }
    /*
    Enter your code for the function call
    if key is found output the following statement
    
    */



}

   // function definition
int binarySearch(int list[], int key, int low, int high){

    int count = 0;
    //while low is less than or equal to high
    while(low <= high){
        count++;
        int mid = (low + high) / 2;
        //if key is found
        if(key == list[mid]){
            cout << "It takes "<< count << " iterations to find the key " << key  << endl;
            return mid;
        }
        //if key is less than mid
        else if(key < list[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    

    // Write your code here and the two cout statements be inserted into your code wherever necessary

   cout << "After  "<< count << " iterations "<< key << " is not found!" << endl;
    
}
