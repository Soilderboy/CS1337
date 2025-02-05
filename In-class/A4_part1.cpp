/*
Details:
Use selection sort

main:
    size of array is 10
    do input validation to check elements are less than 11 and greater than 0
    then cin
    then sort the array
    and display it

selection sort:
    what is it? - find the smallest element and swap it with the first
    then repeat for the rest of the array (meaning the second element)
*/

#include <iostream>
using namespace std;
#define SIZE 10

void SelectionSort(int [], int size );
int main()
{
   // Declare all the variables and arrays
    int numberList[SIZE];
    int elementSize = 0;
    // input validation
    while(elementSize < 1 || elementSize > 10){
        cout << "How many elements? ";
        cin >> elementSize;
        if(elementSize < 1 || elementSize > 10){
            cout << "The number of elements should be less than 11 and greater than 0" << endl;
            continue;
        }

    }

   // Read data from  keyboard and populate arrays
    cout << "Enter the elements: ";
    for(int i = 0; i < elementSize; i++){
        cin >> numberList[i];
    }
   // call the selection sort function
   SelectionSort(numberList, elementSize);
    
    // Display the sorted array
    cout << "The sorted array is : ";
    for(int i = 0; i < elementSize; i++){
        cout << numberList[i] << " ";
    }
}

void SelectionSort(int numbers[], int size)
{
   // body of the function
   //find smallest element and swap it with the first and repeat
    for(int i = 0; i < size - 1; i++){//size needs to be -1 because of j
        int minIndex = i;
        //find smallest element
        for(int j = i + 1; j < size; j++){
            if(numbers[j] < numbers[minIndex]){
                minIndex = j;
            }
        }
        //swap if minIndex is not i
        if(minIndex != i){
            int temp = numbers[i];
            numbers[i] = numbers[minIndex];
            numbers[minIndex] = temp;
        
        }
        
    }
}
