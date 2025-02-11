#include <iostream>
using namespace std;

int main()
{
    //size of the array
    int n;

    //Given array of n integers, find the index that stores the sum of all the other elements

    //first input is size of array, following elements are the values

    // Enter your code
    // Get the size of the array from the user
    cin >> n;
    // Get the elements of the array from the user
    int size = n;
    int arr[size];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // Find out the element with the sum
    //sum will be the first element
    //
    int sum = arr[0];
    for(int i = 1; i < n; i++){
        sum += arr[i];
    }
    //check if the sum is in the array
    //we'll subtract the element from the sum and check if the element equals the sum
    for(int i = 0; i < n; i++){
        if(sum - arr[i] == arr[i]){
            // If index is found with the sum
            cout << "Index " << i << " has the sum" << endl;
            return 0;
        }
    }
       // If no index is found with the sum
        cout << "No index has the sum" << endl;

    return 0;
}
