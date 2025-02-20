#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXPRODUCTS = 100;
string names[MAXPRODUCTS];
double prices[MAXPRODUCTS];
string codes[MAXPRODUCTS];
int numProducts = 0;

int findItem(string inputCode);
void readConfiguration();
void display();
void process();

int main() {
   readConfiguration();
   display();
   process();
}

void readConfiguration() {
   // Code here to Read the values into arrays
    cout << numProducts << " items loaded.\n";
}

void display()
{
    cout << endl;
    cout << left << setw(8)   <<  "Codes"
                            << setw(25) << "Item Name"
                             << setw(4)  <<  "Prices" << endl;
    cout << "--------------------------------------------------------------------------"  << endl;
    //code here
    //Print the values from their respective arrays
}
//return valid index if the item is found, return -1 otherwise.
int findItem(string inputCode) {
    //code here!
    

    return -1;
}

// read order string like “A1 A2 E1 E2 S1” and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() {
    //code here
    
    cout << "Total: $" << total << endl;
}

