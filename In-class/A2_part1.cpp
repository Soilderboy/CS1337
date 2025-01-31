/*
Given a sorted array, insert new ids

If there is a duplicate, don't insert the id - just print a message
*/
#include <iostream>

using namespace std;

int findId(int, int [], int);
void insertId(int, int [], int);

int main()
{
    const int MAX_SIZE = 100;

    int sid[MAX_SIZE] = { 1, 3, 6, 8, 10};
    int index, id;
 

    // To insert more numbers
      int num, size = 5;
      cout << "How many numbers do you want to insert? ";
      cin >> num;
      cout << "Enter the student ids: ";
        cout << endl;

     /*
     Enter your code
     */
    for(int i = 0; i < num; i++){
        cin >> id;
        size++;
        insertId(id, sid, size);
    }

   cout << "The array with all the elements inserted are: ";
   /*
     Enter your code
     */
    for(int i = 0;  i < size + num; i++){
        cout << sid[i] << " "; 
    }
}

// should return the index of val if it is present in the array
// otherwise return -1
int findId(int val, int arrId[], int sz)
{
   /*
     Enter your code
     */
    //returns index if finds a duplicate
    for(int i = 0; i < sz; i++){
        if(arrId[i] == val){
            return i;
        }
    }
    cout << val << " not found " << endl;
    return -1;
}

void insertId(int val, int arrId[], int sz)
{
   /*
     Enter your code
     */

    int index = findId(val, arrId, sz);
    if(index == -1){
        for(int i = 0; i < sz; i++){
            //if the current element is greater than val then we shift all to the right and output a message after assigning val to that index
            if(arrId[i] > val){
                //shift all elements to the right 1
                for(int j = sz-1; j > i; j--){
                    arrId[j] = arrId[j-1];
                }
                //insert val at index i
                arrId[i] = val;
                cout << val << " inserted into the array" << endl;
                //after inserting, break out of the loop
                break;
            }
            //if it's the last element, then we insert val
            if(i == sz-1){
                arrId[sz-1] = val;
                cout << val << " inserted into the array" << endl;
                break;
            }
        }
    }
    else{
        cout << arrId[index] << " found at position " << index << endl;
    }
   
}
