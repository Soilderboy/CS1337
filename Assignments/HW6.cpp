/*
Manage student records - netID, major, GPA in a struct

Read student data from a file and loop on displayign three choices

It's possible to swap structures like
Student temp = struct1;
struct1 = struct2;
struct2 = temp;

Notes:
When choosing choice 2, perform both linear and binary search and display result from both

    Linear search on the original array studArray[NUM_ELMTS]
    Binary on sorted array, so we make a copy of original array and sort it called studArraysortedbyID and sort the copy by netID

    Binary search will be performed on studArraysortedbyID

    Use of the sorting algorithms (bubble sort or selection sort) 

    Code should keep track of iterations

To list top n students, sort by GPA
    preserve original array and copy using studArraysortedbyGPA and sort the copy
    
    same as above, use bubble or selection sort


*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student{
    int netID;
    string major;
    double GPA;
};

//function prototypes
//sorts the array of Student structs according to GPA
void modifiedSortGPA(Student array1[], int size);
//sorts according to netID
void modifiedSortID(Student array2[], int size);

//implements linear search with following arguments - array of Student structs, numElems, value, nIter (as reference) to pass # of iterations back to calling function
//return index of where the mathc is found, otherwise -1
int linearSearchID(Student arr[], int numElems, int value, int &nIter);

//implements binary search with following args - Student struct array, numElems, value, &nIter 
//returns index of where match is found, otherwise -1
int binarySearchID(Student arr[], int numElems, int value, int &nIter);

int main(){
    //no need for input validation on file reading
    string filename;
    cout << "Enter file name: " << endl;
    cin >> filename;

    ifstream file(filename);
    if(!file){
        cout << "Could not open file" << endl;
        cout << "Exiting\n";
        return 1;
    }

    //count # of elements in file
    int NUM_ELMTS = 0;
    string line;
    while(getline(file, line)){
        NUM_ELMTS++;
    }

    //reset file pointer
    file.clear();
    file.seekg(0, ios::beg);

    //create dynamic array of Student structs
    Student *studArray = new Student[NUM_ELMTS];
    Student *studArraysortedbyGPA = new Student[NUM_ELMTS];
    Student *studArraysortedbyID = new Student[NUM_ELMTS];
    
    //read from file
    for(int i = 0; i < NUM_ELMTS; i++){
        file >> studArray[i].netID >> studArray[i].major >> studArray[i].GPA;
    }

    //copy original array to sorted arrays
    for(int i = 0; i < NUM_ELMTS; i++){
        studArraysortedbyGPA[i] = studArray[i];
        studArraysortedbyID[i] = studArray[i];
    }

    //sort the arrays
    modifiedSortGPA(studArraysortedbyGPA, NUM_ELMTS);
    modifiedSortID(studArraysortedbyID, NUM_ELMTS);

    //output original array and sorted arrays

    cout << "Original array: " << endl;
    cout << "---------------" << endl;
    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
    for(int i = 0; i < NUM_ELMTS; i++){
        if(i % 2 == 0){
            cout << setw(5) << right << i << setw(7) << studArray[i].netID << setw(7) << studArray[i].major << setw(6) << fixed << setprecision(2) << studArray[i].GPA;
        } else if(i % 2 == 1){
            cout << setw(8) << right << i << setw(7) << studArray[i].netID << setw(7) << studArray[i].major << setw(6) << fixed << setprecision(2) << studArray[i].GPA << endl;
        }
    }
    cout << endl;

    cout << "Array sorted by GPA:" << endl;
    cout << "--------------------" << endl;
    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
    for(int i = 0; i < NUM_ELMTS; i++){
        if(i % 2 == 0){
            cout << setw(5) << right << i << setw(7) << studArraysortedbyGPA[i].netID << setw(7) << studArraysortedbyGPA[i].major << setw(6) << fixed << setprecision(2) << studArraysortedbyGPA[i].GPA;
        } else if(i % 2 == 1){
            cout << setw(8) << right << i << setw(7) << studArraysortedbyGPA[i].netID << setw(7) << studArraysortedbyGPA[i].major << setw(6) << fixed << setprecision(2) << studArraysortedbyGPA[i].GPA << endl;
        }
    }
    cout << endl;

    cout << "Array sorted by netID:" << endl;
    cout << "----------------------" << endl;
    cout << "index  netID  major   GPA   index  netID  major   GPA" << endl;
    for(int i = 0; i < NUM_ELMTS; i++){
        if(i % 2 == 0){
            cout << setw(5) << right << i << setw(7) << studArraysortedbyID[i].netID << setw(7) << studArraysortedbyID[i].major << setw(6) << fixed << setprecision(2) << studArraysortedbyID[i].GPA;
        } else if(i % 2 == 1){
            cout << setw(8) << right << i << setw(7) << studArraysortedbyID[i].netID << setw(7) << studArraysortedbyID[i].major << setw(6) << fixed << setprecision(2) << studArraysortedbyID[i].GPA << endl;
        }
    }
    cout << endl;
    cout << endl;
    


    //display choices
    int choice;
    do{
        cout << "***************" << endl;
        cout << "Menu of choices" << endl;
        cout << "***************" << endl;

        cout << "1 - List top n students" << endl;
        cout << "2 - Search on a netID" << endl;
        cout << "3 - Quit" << endl;

        cin >> choice;

        if(choice == 1){
            int n;
            cout << "Enter n: " << endl;
            cin >> n;
            
            //display top n students
            if(n > NUM_ELMTS){
                n = NUM_ELMTS;
            }
            cout << "Top " << n << " students are:" << endl;
            cout << endl;
            for(int i = n-1; i >= 0; i--){
                cout << "netID: " << studArraysortedbyGPA[i].netID << ", major: " << studArraysortedbyGPA[i].major << ", GPA: " << studArraysortedbyGPA[i].GPA << endl;
            }
            cout << endl;

        } else if(choice == 2){
            string netID;
            cout << "Enter netID: " << endl;
            cin >> netID;

            //linear search
            int nIter = 0;
            int netIDasInt = stoi(netID); //convert netID to int
            int index = linearSearchID(studArray, NUM_ELMTS, netIDasInt, nIter);

            cout << "Result of linear search: " << endl;
            cout << "------------------------" << endl;

            if(index == -1){
                cout << "Student not found" << endl;
                cout << "It took " << nIter << " iterations" << endl;
            } else {
                cout << "Student found at index " << index << ", major is " << studArray[index].major << ", GPA is " << studArray[index].GPA << endl;
                cout << "It took " << nIter << " iterations" << endl;
            }
            cout << endl;
            //binary search result
            nIter = 0;
            index = binarySearchID(studArraysortedbyID, NUM_ELMTS, netIDasInt, nIter);

            cout << "Result of binary search: " << endl;
            cout << "------------------------" << endl;

            if(index == -1){
                cout << "Student not found" << endl;
                cout << "It took " << nIter << " iterations" << endl;
            } else {
                cout << "Student found at index " << index << ", major is " << studArraysortedbyID[index].major << ", GPA is " << studArraysortedbyID[index].GPA << endl;
                cout << "It took " << nIter << " iterations" << endl;
            }
            cout << endl;
        }
    } while(choice != 3);

    cout << "Exiting" << endl;
    //close file
    file.close();

    return 0;
    
}

//sorts the array of Student structs according to GPA
void modifiedSortGPA(Student array[], int size){
    //bubble sort, highest number bubbles to the end
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j].GPA > array[j + 1].GPA){
                Student temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//sorts according to netID
void modifiedSortID(Student array[], int size){
    //selection sort practice
    //basically, find smallest element and swap with first element

    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(array[j].netID < array[minIndex].netID){
                minIndex = j;
            }
        }
        //swap the beginning unsorted parts with smallest element
        Student temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}
//implements linear search with following arguments - array of Student structs, numElems, value, nIter (as reference) to pass # of iterations back to calling function
//return index of where the mathc is found, otherwise -1
int linearSearchID(Student arr[], int numElems, int value, int &nIter){
    nIter = 0;
    for(int i = 0; i < numElems; i++){
        nIter++;
        if(arr[i].netID == value){
            return i;
        }
    }
    return -1;
}

//implements binary search with following args - Student struct array, numElems, value, &nIter 
//returns index of where match is found, otherwise -1
int binarySearchID(Student arr[], int numElems, int value, int &nIter){
    int low = 0;
    int high = numElems - 1;
    nIter = 0;

    //binary search operates on two pointers, low and high that update based on middle element
    while(low <= high){
        nIter++;
        int mid = (low + high) / 2;
        if(arr[mid].netID == value){
            return mid;
        } else if(arr[mid].netID < value){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1; //not found
}
