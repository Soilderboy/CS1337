/*
Details:
Calculate the number of occurrences of each element in the array
Array is size 100
Assume elements are 0-29

Output:

(0-29#) occurs (freq) times

Psuedocode:
take input for seed
generate random numbers for array
call freq function on array
print out frequency of each element

freq function:
take in array, size, and count array
count array keeps track of frequency of each element
data array has all the numbers
for each element in data array, increment corresponding index in count[]

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void freq(int[], int, int[]);

int main()
{
    //input seed
    int seed;
    cin >> seed;
    srand(seed);
    const int MAX_SIZE = 100;
    const int MAX_NUM = 30;

    int data[MAX_SIZE];
    int cnt[MAX_NUM] = {0};
    int i;
    
    /* 
   
   Enter Code
   
   */
    //generate random numbers for array
    for(i = 0; i < MAX_SIZE; i++){
        data[i] = rand() % MAX_NUM;
    }

    //call freq function on array
    freq(data, MAX_SIZE, cnt);

    //print frequency of each element using cnt array
    //only print if frequency is greater than 0

    for(int i = 0; i < MAX_NUM; i++){
        if(cnt[i] > 0)
            cout << i << " occurs " << cnt[i] << " times" << endl;
    }

    
}


void freq(int data[], int sz, int cnt[])
{
   /* 
   
   Enter Code
   
   */
    //for each element in data array, increment corresponding index in count[]
    for(int i = 0; i < sz; i++){
        cnt[data[i]]++;
    }


}