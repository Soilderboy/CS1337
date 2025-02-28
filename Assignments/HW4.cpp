/*
Details: practice pointers to arrays and sorting arrays using pointers

idea: allows us to sort arrays without changing or copying the original array, changing the pointers rather than the positions of the array

Bubble sort:
	1. outer loop index i from n-1 to 1 (inclusive)
	2. inner j runs from 0 to i-1 (inclusive)
	3. compare array[j] and array[j+1]
	4. swap if array[j] > array[j+1]

but we aren't going to swap or change the array,
swap the pointers that point to those array elements using swapIntPtr function

//swap values of two argument pointers, needs to swap pointers to ints


Display:
	display data both in unsorted and sorted form
	10 numbers per line, each number in a 6 byte field

Outline:
	1. initalize int array of 40, load it with random numbers from 0 to 3000
	2. initialize pointer of 40, call it Pointer Array and point to data array such that they should point to int of same index
	3. sort pointer using a modified bubble sort, ascending values
	4. print out data set four times, print data set by traversing data array, 
	then print data in both data and pointer array in unsorted order by traversing pointer array
	third, print sorted order by traversing pointer array
	print data array one more time to demonstrate original order (is unchanged)

functions:
	1. swapIntPtr, swap values of pointer arguments
	2. sorting function - bubble sort
	3. printArray - display function for data array
		10 numbers per line, each in a 6 byte field
	4. printPointerArray - display function for pointer array
		10 numbers per line in a 6 byte field

recommended order of implementation:
	1. initialize data array
	2. printData array function 
	3. then initialize pointer array
	4. printPointerArray function
	5. swapIntPtr
	6. bubbleSort
	7. set up main
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> // contains prototype for function time
using namespace std;

#define SIZE 40

void printArray(int randArray[]);	// Function prototype
void bubbleSort(int* list[]);		// Function prototype
void printPointerArray(int* ptrArray[]);	// Function prototype
void swapIntPtr(int** xptr, int** yptr);	// Function prototype

int main()
{
	int seed ;
	cout << "Enter seed: ";
	cin >> seed;
   	srand(seed);

	int dataArray[SIZE] = { 0 };
	int* pointerArray[SIZE];
	
	// Initializing values in Data Array
	for (int index = 0; index < SIZE; index++)
	{
		dataArray[index] = rand() % 3000;
	}

	// Printing four different data sets
	printf("Before Sorting, values in Data Array: \n");
	printArray(dataArray);
	printf("\n");

	// Initializing Pointer array with the address of each element in data array
	for(int i = 0; i < SIZE; i++){
		pointerArray[i] = &dataArray[i];
	}
	

	printf("Before Sorting, values in Pointer Array and the value it is pointing at: \n");
	printPointerArray(pointerArray);
	printf("\n");

	// Calling function Bubble SOrt
	bubbleSort(pointerArray);

	// After Sorting printing the values
	printf("\n");
	printf("After Sorting, values in Pointer Array and the value it is pointing at:  \n");
	printPointerArray(pointerArray);
	printf("\n");
	

	printf("\n");
	printf("After Sorting, values in Data Array: \n");
	printArray(dataArray);
	printf("\n");
	return 0;
}

void printArray(int randArray[]){
	//10 numbers per line each in a 6 byte field
	//6 byte field means 6 characters so setw(6)

	for(int i = 0; i < SIZE; i++){
		cout << setw(6) << randArray[i];
		if(i % 10 == 9){
			cout << endl;
		}
	}
}

void printPointerArray(int* ptrArray[]){
	for(int i = 0; i < SIZE; i++){
		//output memory and value
		cout << setw(6) << ptrArray[i];
		cout << setw(6) << *ptrArray[i];
		if(i % 10 == 9){
			cout << endl;
		}
	}
}

//swap values of two argument pointers, needs to swap pointers to ints
void swapIntPtr(int** xptr, int** yptr){ //**  needed otherwise we'd swap copies of pointers
	int* temp = *xptr; //store ptr1's address
	*xptr = *yptr; //dereference pointer to get pointer
	*yptr = temp;
}
//only using bubblesort for pointer array
void bubbleSort(int* list[]){
	for(int i = 0; i < SIZE - 1; i++){
		for(int j = 0; j < SIZE - i - 1; j++){
			if(*list[j] > *list[j + 1]){
				swapIntPtr(&list[j], &list[j + 1]);
			}
		}
	}

}

// complete both the print functions and bubbleSort.
//Call the swapIntPrt function from Bubble sort for swapping the 