//Write code to determine if the matrix is symmetric

/*Details:
A matrix is symmetric if A = A^T

Transpose = change rows to columns and columns to rows
*/

#include <iostream>
using namespace std;

int main()
{
    int mrow, mcol;
   cout <<  "Enter the number of rows and columns: ";
   cin >> mrow >> mcol;
    while (mrow != mcol)// check if number of columns and rows are same ) // input validation
    {
        cout << "The number of rows and columns must be same." << endl;
        /*
        Enter your code
        */
        cout <<  "Enter the number of rows and columns: ";
        cin >> mrow >> mcol; //repeats input until correct input is given
        
        

    }
    cout << "Enter the values for the matrix: \n";
    int A[mrow][mcol];


    for (int i = 0; i < mrow; i++){
        for(int j = 0; j < mcol; j++){
            cin >> A[i][j];
        }
    }
    
     /*
        Enter your code
        */

    // code to find if matrix is symmetrical
    //if switching the rows and columns doesnt result in the same matrix, then its not symmetrical
    bool symmetrical = true;
    for(int i = 0; i < mrow; i++){
        for(int j = 0; j < mcol; j++){
            if(A[i][j] != A[j][i]){
                symmetrical = false;
                
                break;
            }
        }
    }
                
    if(symmetrical)
        cout << "The matrix is symmetrical." << endl;
    else
        cout << "The matrix is not symmetrical." << endl;
    return 0;

}
