/*
Details:
Practice file i/o, sorting/searching, parallel arrays, functions with array arguments, and reference variables

Manage student records:
    netID
    major
    GPA

    maintained all in parallel arrays

main:
    read students' data from a file
        read netID, major, and GPA

    initialize array by reading from a file
    program prompts user for file name

        file is a text file
        it consists of student's netID, major, then GPA in that order.

        1001 CS 3.8

        number of records on file is at most NUM_ELMTS

    

    loop on displaying these three choices
        display top n students
            if chosen,
                ask for n
                netID
                major
                GPA

                and then display the top n students with descending GPA
        search for a student
            if chosen,
                ask for netID
                
                    if NETID is found, display array index, major, and GPA of the student
                    if not, display "Student not found"
        exit the program
            print "Exiting\n"
            terminate

    repeat loop until exit is chosen
    close file
    return 0


When choice 2 happens,
    Perform a linear and binary search and display the result from both.
    netID is not sorted.

    The original array will be done on linear search while the copy on binary.
    Copy the netID array to a temporary array called sortedNETIDbyID and do a binary search on it

    To display the major and GPA for the student,
    we make parallel arrays sortedMajorbyID and sortedGPAbyID

    meaning the index works for all three arrays for the same student

    Use either bubble sort or selection sort to sort the arrays (so we can do a binary search) [we'll choose selection sort]
    To maintain parallelism, whenever you swap elements of sortedNetIDbyID, swap the same indices of sortedMajorbyID and sortedGPAbyID

    Keep track of how many iterations the search went through and the main function should display # of iterations for both linear and binary search

To list top n students:

    Sort the GPA array by GPA. 
    Preserve the original GPA array and sort a copy of GPA called sortedGPAbyGPA.

    To display the netID and major, maintain arrays parallel called
        sortedMajorbyGPA
        sortedNetIDbyGPA

    Use one of the sorting algorithms mentioned [use bubble sort this time]
    Make sure to maintain parallelism by swapping same indices of the other two arrays

    Assume user will always type a positive integer and only check if n >  than number of students
    Display all the students sorted by GPA in descending order (GPA is 2 decimal places)

(Wow they just gave us psuedocode like that. I already kind of typed it out though.)

From here on out, I just copy pasted what was given to me. This gross, wordy, psuedocode...

Outline of main
    Prompt the user for a file name.  

    Open the file and read the data to initialize the netID, major and GPA arrays. If the file cannot be opened, print “Could not open file” and “Exiting\n” and terminate.   

    Copy netID to sortedNetIDbyGPA, copy GPA to sortedGPAbyGPA and copy major to sortedMajorbyGPA. Sort sortedGPAbyGPA by GPA, while maintaining the parallelism of sortedNetIDbyGPA and sortedMajorbyGPA  

    Copy netID to sortedNetIDbyID, copy GPA to sortedGPAbyID and copy major to sortedMajorbyID. Sort sortedNetIDbyID by ID, while maintaining the parallelism of sortedGPAbyID and sortedMajorbyID  

    Display the contents of all the arrays. use space of setw(7) between all the different variable

    Display the menu of choices, and perform the action selected by the user on the menu (search, list the top n students, or quit). If the user chooses “search”, the main function should call both the linear search and binary search functions, and display the result of both searches, along with the number of iterations.  

    The  main  function should loop on displaying the menu as long as the user does not choose to quit. If the user chooses to quit,  the program  should print “Exiting\n” and terminate.



Implement the following functions. You must use the same function name, parameter list and return type to pass the unit tests.

 This function implements linear search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found

int linearSearchID(int arr[], int numElems, int value, int &nIter)
{
    // Function body 
}

 This function implements binary search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found

int binarySearchID(int arr[], int numElems, int value, int &nIter)
{
    // Function body
}

Implement the following functions. You must use the same function name, parameter list and return type to pass the unit tests.

 This function sorts array1 and maintains the parallelism
of array2, and array3
Whenever elements of array1 are swapped, the elements of array 2
and array3 at the same indices are also swapped

void modifiedSortGPA(double array1[], int array2[], string array3[], int size)
{
   // Function body
}

 This function sorts array2 and maintains the parallelism
of array1 and array3
Whenever elements of array2 are swapped, the elements of array 1
and array3 at the same indices are also swapped

void modifiedSortID(int array2[], double array1[], string array3[], int size)
{
   // Function body
}
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <climits>


using namespace std;


const int NUM_ELMTS = 18;

// function prototypes
int linearSearchID(int arr[], int numElems, int value, int &nIter);
int binarySearchID(int arr[], int numElems, int value, int &nIter);
void modifiedSortGPA(double array1[], int array2[], string array3[], int size);
void modifiedSortID(double array1[], int array2[], string array3[], int size);

int main(){

    // netID, major and GPA are parallel arrays
    int netID[NUM_ELMTS]; // Original netID array
    string major[NUM_ELMTS]; // Original major array
    double GPA[NUM_ELMTS]; // Original GPA array

    // sortedNetIDbyID is sorted by netID, and sortedMajorbyID and sortedGPAbyID are parallel arrays 
    int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
    string sortedMajorbyID[NUM_ELMTS]; 
    double sortedGPAbyID[NUM_ELMTS];
        
    // sortedGPAbyGPA is sorted by GPA, and sortedNetIDbyGPA and sortedMajorbyGPA are parallel arrays
    double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
    int sortedNetIDbyGPA[NUM_ELMTS]; 
    string sortedMajorbyGPA[NUM_ELMTS]; 

    //int is for netID, double is for GPA, string is for major

    string filename;
    ifstream file;

    cout << "Enter file name: ";
    cin >> filename;

    if(!file){
        cout << "Could not open file\n";
        cout << "Exiting\n";
        return 1;
    }

    for(int i = 0; i < NUM_ELMTS; i++){
        file >> netID[i] >> major[i] >> GPA[i];
    }

    //loop and display three choices
    int choice;
    do{
        cout << "***************" << endl;
        cout << "Menu of choices" << endl;
        cout << "***************" << endl;
        cout << "1 - List top n students" << endl;
        cout << "2 - Search on a netID" << endl;
        cout << "3 - Quit" << endl;
        cin >> choice;

        //eventually add a input validation here
        //list top n students
        if(choice == 1){
            int n;
            cout << "Enter n: ";
            cin >> n;

            //display top n students with descending GPA

            //sort GPA array by GPA using modifiedSortGPA

        }
    } while(choice != 3); //exit loop


}
//linearSearchID means take the original array, numElems is max size, 
//value is element we're looking for, nIter is number of itereations
int linearSearchID(int arr[], int numElems, int value, int &nIter){
    for(int i = 0; i < numElems; i++){
        nIter++;
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}
//given a sorted array, find the value, return index
int binarySearchID(int arr[], int numElems, int value, int &nIter){
    int low = 0;
    int high = numElems - 1;
    while(low <= high){
        int mid = (low + high)/2;
        nIter++;
        if(arr[mid] == value){
            return mid;
        }
        else if(arr[mid] < value){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;

}

//swap functon for the sorting
void swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}
//given an arra, sort it, maintain parallelism between arr1 arr2, and arr3
//sort it by GPA let's do a selection sort
//array1 is GPA, array2 is netID, array3 is major
void modifiedSortGPA(double array1[], int array2[], string array3[], int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(array1[j] < array1[minIndex]){
                minIndex = j;
            }
        }
        //swap
        swap(array1[i], array1[minIndex]);
        swap(array2[i], array2[minIndex]);
        swap(array3[i], array3[minIndex]);
    }
}

//sort by ID, using bubble sort - maintain parallelism like above
//array1 is GPA, array2 is netID, array3 is major
//I swapped array1 and array2's data types from the function prototypes given
void modifiedSortID(double array1[], int array2[], string array3[], int size){
    for(int i = 0; i < size - 1; i++){
        //size - 1 - i might go overbound
        for(int j = 0; j < size - 1 - i; j++){
            //if current element is greater than the next, swap
            if(array2[j] > array2[j + 1]){
                swap(array1[j], array1[j + 1]);
                swap(array2[j], array2[j + 1]);
                swap(array3[j], array3[j + 1]);
            }
        }
    }
}

