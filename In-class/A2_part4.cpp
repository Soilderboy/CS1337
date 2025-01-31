/*
Details: 
Call a function to calculate the sum of all numbers in both diagonals

Main:
    declare a 4x4 array
    initialize values from 0 to 49 using random generator (so %50)
    take seed as input from user and use srand(seed)
    call sumMajorDiagonal
        display the sum
    call sumOtherDiagonal
        display the sum

sumMajorDiagonal:
    sum the elements going from top left to bottom right
        when doing the loop, use same index for row and col
        and just increment that
    return sum
sumMinorDiagonal:
    sum going from top right to bottom left
        use row as index and col as 3 - row and increment index
    return sum
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
const int MAXROWS = 4;
const int MAXCOLS = 4;

// write the prototypes for the two functions
int sumMajorDiagonal(int m[MAXROWS][MAXCOLS]);
int sumOtherDiagonal(int m[MAXROWS][MAXCOLS]);

int main()
{
   // code here
   //declare 4x4 array
   int A[MAXROWS][MAXCOLS];
   int seed;
   cout << "Enter a seed value: ";
   cin >> seed;
   srand(seed);
   cout << endl;
   //initialize values from 0 to 49 using rand
   for(int i = 0; i < MAXROWS; i++){
        for(int j = 0; j < MAXCOLS; j++){
            A[i][j] = rand() % 50;
        }
   }
   //display array
   for(int i = 0; i < MAXROWS; i++){
        for(int j = 0; j < MAXCOLS; j++){
            cout << setw(4) << A[i][j];
        }
        cout << endl;
   }
   cout << endl;
  
    cout << "Sum of the elements in the major diagonal is "
        << sumMajorDiagonal(A) << endl;

    cout << "Sum of the elements in the other diagonal is "
        << sumOtherDiagonal(A) << endl;
}

int sumMajorDiagonal(int m[MAXROWS][MAXCOLS]) {
   
    //use same index for row and col
    int sum = 0;
    for(int i = 0; i < MAXROWS; i++){
        sum += m[i][i];
    }
    return sum;
    
  }

  int sumOtherDiagonal(int m[MAXROWS][MAXCOLS]) {
    
    //use MAXCOL - 1 for col (starting index) and then row is 0
    //col then decreases by 1 and row increases by 1
    //going from top right to bottom left
    int sum = 0;
    for(int i = MAXCOLS - 1; i >= 0; i--){
        sum+= m[MAXCOLS - 1 - i][i];
    }
    return sum;
      
  }
