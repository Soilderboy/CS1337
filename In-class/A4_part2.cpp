/*
Details: 
Sort elements using selection sort

Main:
    generate array of size 100
    get # of elements from user
    ensure input is valid

    use rand to populate array

    invoke selection sort

    display

selection sort
    do it from the previous example
    find the smallest element and swap it with the first and repeat for the rest of the array

    for loop
    set minIndex to i
        another for loop to find smallest element
        swap

    voila
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 100

void SelectionSort(int [], int size );
//void SelectionSort(int numbers[], int numbersSize);
int main()
{
    int numberList[SIZE];
    int numberRec;

    cout << "How many elements? ";
    cin >> numberRec;

    // input validation
    while(numberRec < 1 || numberRec > SIZE)
    {
        cout << "The number of elements should be less than " << SIZE+1 << " or greater than 0" << endl;
        //input your code
        cout << "How many elements? ";
        cin >> numberRec;

    }

    int seed;
    cout << "Enter a seed value: ";
    cin >> seed;
    srand(seed);
    cout << "The array after populating value is: " << endl;
// Read data from  keyboard and populate arrays


    for(int i = 0; i < numberRec; i++)
    {
         numberList[i] = (rand()%50);
         cout << setw(3) <<  numberList[i];
    }
    cout << endl;
    // call the selection sort function
    SelectionSort(numberList, numberRec);

    // Display the sorted array
    cout << "The sorted array is : " << endl;
    
    //input your code
    for(int i = 0; i < numberRec; i++){
        cout << setw(3) << numberList[i];
    }
    return 0;
}

void SelectionSort(int numbers[], int size)
{
    for (int i = 0; i < size - 1; i++)//size -1 cuz of j
    {
        //Keep index of the current min and corresponding element as min
        int minIndex = i;
        int min = numbers[i];

        // Find index of smallest remaining element, current MinIndex
        for (int j = i + 1; j < size; j++)
        {
            if(min > numbers[j]){
                min = numbers[j];
                minIndex = j;
            }
        }

        //Swapping if necessary
        if(minIndex != i)
        {
            int temp = numbers[i];
            numbers[i] = numbers[minIndex];
            numbers[minIndex] = temp;
        }
        //input your code

    }
}
