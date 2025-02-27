/*
Details:
Read menu of restaurant along with code, item name, and price

Display menu
choose items in menu to find out the total cost of the items

lstringstream to read/parse the diferent codes //parse means break down string to smaller parts
if item code available, print item name and cost
if invalid code, print invalid statement and skip to read the next item
calculate the toal cost of the items

Output:
enter string:

item name and price

total: $total




*/

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
//read configuration from file, store in arrays
void readConfiguration() {
   // Code here to Read the values into arrays
    ifstream file("menu.txt");
    if(!file){
        cout << "File not found\n";
        return;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line); 
        ss >> codes[numProducts] >> names[numProducts] >> prices[numProducts];
        numProducts++;
    }
    //testing
    file.close();
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
    for(int i = 0; i < numProducts; i++){
        cout << left << setw(8) << codes[i] << setw(25) << names[i] << setw(4) << fixed << setprecision(2) << prices[i] << endl;
    }
    //Print the values from their respective arrays
}
//return valid index if the item is found, return -1 otherwise.
//inputCode is the item code
int findItem(string inputCode) {
    //code here!
    for(int i = 0; i < numProducts; i++){
        if(codes[i] == inputCode){
            return i;
        }
    }
    return -1;
}

// read order string like “A1 A2 E1 E2 S1” and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() {
    //code here
    string order;
    cout << "Enter your order string: ";
    getline(cin, order);
    cout << endl;
    stringstream ss(order); //parse string
    string code; //store code per iteration
    double total = 0;
    while(ss >> code){ //rewrites code each time
        int index = findItem(code);
        if(index == -1){
            cout << code << " is invalid. Skipping it." << endl;
        }
        else{
            cout << names[index] << ": $" << prices[index] << endl;
            total += prices[index];
        }
    }
    cout << "Total: $" << total << endl;
}

