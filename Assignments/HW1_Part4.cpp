/*
Details:
Calculate the sum of two matrices
Create 2 2D array of 3*3 and initialize the values from 0 to 49 using a random generator

Take sed as input, then use srand(seed)

main should call addMatrix(matrix1, matrix2, resultMatrix)

Add matrix1 and 2 and store the result in resultMatrix)

call function printResult(matrix1, matrix2, resultMatrix, +) and display result as output
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int ROW = 3;           // Number of divisions
const int COL = 3;
// write the prototypes for the two functions
void addMatrix(int [][COL], int [][COL], int [][COL]);
void printResult(int [][COL], int [][COL], int [][COL], char);

int main()
{
    int seed;
    //cout << "Enter a seed value: ";
    cin >> seed;
    srand(seed);
    
    //code your program here
    //initialize m1 and m2 using random numbers from srand
    int matrix1[ROW][COL] = {0};
    int matrix2[ROW][COL] = {0};
    //initialize m1 with random numbers first then m2
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            //random number from 0 to 49
            matrix1[i][j] = rand() % 50;
        }
    }
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            //random number from 0 to 49
            matrix2[i][j] = rand() % 50;
        }
    }
/*
    //print m1 and m2
    cout << "Matrix1 is : ";
    cout << endl;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "Matrix2 is : ";

    cout << endl;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
*/
    int resultMatrix[ROW][COL] = {0};
     // Add two matrices and print the result
    addMatrix(matrix1, matrix2, resultMatrix);
    cout << "The addition of the matrices is " << endl;
    printResult(matrix1, matrix2, resultMatrix, '+');
}

/** The method for adding two matrices */
 void addMatrix(int m1[ROW][COL], int m2[ROW][COL],int m3[ROW][COL] )
  {

     // code to add matrix1 and 2
     for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
     }


  }

 /** Print result - Follow this logic so that you have a proper display as in test cases*/
   void printResult(int m1[ROW][COL], int m2[ROW][COL], int m3[ROW][COL], char op)
       {
        //one loop to display all three matrices and then we'll put an operator if it's the middle row
        // code to display matrix1, matrix2 and matrix3
        for(int i = 0; i < ROW; i++){
            //first matrix
            for(int j = 0; j < COL; j++){
                cout << setw(4) << m1[i][j];
            }
            if (i == ROW / 2)
                cout << "  " << op <<  "  ";
            else
                cout <<  "     " ;
            //second matrix
            for(int j = 0; j < COL; j++){
                cout << setw(4) << m2[i][j];
            }
            if (i == ROW / 2)
                cout <<  "  =  " ;
            else
                cout <<  "     " ;
            //third matrix
            for(int j = 0; j < COL; j++){
                cout << setw(4) << m3[i][j];
            }
            cout << endl;
        }


      // code to display matrix2


      // code to display matrix3

}