/*
Details:
practice pointers, dynamic memory allocation and file input/output

read grocery product records from a file, then storei n parallel arrays

grocery product record (5 items)
    PLU - string
    product name - string
    product sales type - int (0 = per unit, 1 = per pound)
    price per pound or price per unit - double
    current inventory level (pounds or units) - int

    A001 Apples 1 0.90 21  
    A002 Peaches 1 0.82 11  
    A006 Avocados 0 1.54 27  
    A008 Mangos 0 1.69 19  

general:
    read file to determine # of records in file
    dynamically allocate and populate with parallel arrays
    print inventory as read from file and loops a menu

    menu:
        1 - Checkout
        2 - Print current inventory
        3 - Quit

    checkout:
        user enters PLU and quantity(weight or # of units - dependent on sales type)
        calculate total cost and update inventory
        print total cost
        user can use 0 to indicate end of checkout for PLU

    print current inventory:
        print the updated inventory

    quit:
        exits menu and prints updated inventory
        then cout "Exiting\n" and return 0
    

necessary functions
readInventory - arguments(filename, pointers to parallel arrays, # of records)
    read file and populate parallel arrays

checkout - returns total cost of purchase


Output formatting

Enter the file name: 
There are # records in the file
//line break
Inventory read from file
------------------------
Display inventory
1 - Checkout
2 - Print current inventory
3 - Quit
//middle area - need to know what the problem is
Enter PLU, 0 if done:
Enter quantity:
Quantity must be positive, reenter:
//line break
Enter PLU, 0 if done:
Enter quantity:
PLU not found
//line break
Enter PLU, 0 if done:
Enter quantity:
//line break
Enter PLU, 0 if done: 0
Total is $67.9
//line break
Menu
//end of middle area
Updated inventory
-----------------
Display inventory
Exiting\n
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


//returns true if file opened successfully
//populates parallel arrays
bool readInventory(string fname, int numRecords, string * pluPtr, double * pricePtr,
                   string * namePtr, int * typePtr, int * inventoryPtr); 
                   
int determineNumRecords(string fname); //returns # of records in file

double checkout(int numRecords, string * pluPtr, double * pricePtr,
                int * inventoryPtr); //returns total cost of purchase

int getUserChoice(); //returns user choice
int searchProduct(string plu, string *pluPtr, int numRecords); //returns index of product
//prints inventory
void printInventory(int numRecords, string * pluPtr, double * pricePtr, string * namePtr, int * typePtr, int * inventoryPtr);
int main(){
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    int numRecords = determineNumRecords(filename);
    cout << "There are " << numRecords << " records in the file" << endl;
    //if numRecords is 0, then file is empty and I will put stuff here once I see the file

    string * pluPtr = new string[numRecords];
    double * pricePtr = new double[numRecords];
    string * namePtr = new string[numRecords];
    int * typePtr = new int[numRecords];
    int * inventoryPtr = new int[numRecords];


    //read inventory from file
    cout << endl;
    cout << "Inventory read from file" << endl;
    cout << "------------------------" << endl;
    if(!readInventory(filename, numRecords, pluPtr, pricePtr, namePtr, typePtr, inventoryPtr)){
        cout << "Could not open file\n";
        cout << "Exiting\n";
        return 1;
    }
    //print inventory
    printInventory(numRecords, pluPtr, pricePtr, namePtr, typePtr, inventoryPtr);

    int choice;
    choice = getUserChoice();

    while(choice != 3){
        if(choice == 1){
            //checkout and cost
            double totalCost = checkout(numRecords, pluPtr, pricePtr, inventoryPtr);
            cout << "Total is: $" << totalCost << endl << endl;
            choice = getUserChoice();
        }
        else if(choice == 2){
            //display current inventory
            cout << "Current inventory" << endl; //inventory needs to be lowercase for some reason
            cout << "-----------------" << endl;
            printInventory(numRecords, pluPtr, pricePtr, namePtr, typePtr, inventoryPtr);
            choice = getUserChoice();
        }
    }
//print updated inventory before ending
    cout << "Updated inventory" << endl;
    cout << "-----------------" << endl;
    printInventory(numRecords, pluPtr, pricePtr, namePtr, typePtr, inventoryPtr);
    cout << "Exiting\n";
    delete [] pluPtr;
    delete [] pricePtr;
    delete [] namePtr;
    delete [] typePtr;
    delete [] inventoryPtr;

    return 0;
}
//reads inventory from file and that's it
bool readInventory(string fname, int numRecords, string * pluPtr, double * pricePtr, string*namePtr, int * typePtr, int * inventoryPtr){
    ifstream file;
    file.open(fname);
    if(!file){
        return false;
    }

    for(int i = 0; i < numRecords; i++){
        file >> pluPtr[i] >> namePtr[i] >> typePtr[i] >> pricePtr[i] >> inventoryPtr[i];
    }
    file.close();
    return true;

}
//prints inventory - used it since readInventory needed to be separate from printing
void printInventory(int numRecords, string * pluPtr, double * pricePtr, string * namePtr, int * typePtr, int * inventoryPtr){
    for(int i = 0; i < numRecords; i++){
        cout << "PLU: " << pluPtr[i] << ", " << setw(17) << left << namePtr[i] << ", type: " << typePtr[i]
        << ", unit price: " << setw(5) << right << pricePtr[i] << ", inventory: " << inventoryPtr[i] << endl;
    }
}
//determines number of records in file, not optimal - would've liked to use readInventory for it instead
int determineNumRecords(string fname){
    ifstream file;
    file.open(fname);
    if(!file){
        return 0;
    }
    int count = 0;
    string temp;
    while(getline(file, temp)){
        if(!temp.empty()){ //only count if there's something per line (fixes overestimation)
            count++;
        }
    }
    file.close();
    return count;
}
//checkout, returns total cost of purchase, has input validation for quantity and if plu is found
double checkout(int numRecords, string * pluPtr, double * pricePtr, int * inventoryPtr){
    string plu;
    int quantity;
    double totalCost = 0;
    int index;
    while(true){
        cout << "Enter PLU, 0 if done: ";
        cin >> plu;
        if(plu == "0"){
            break;
        }
        //input validation for plu
        //plu needs to be checked after inputting quantity for some reason

        cout << "Enter quantity: ";
        //quantity input validation
        while(!(cin >> quantity) || quantity <= 0){ //necessary to check for cin failure
            cout << "Quantity must be positive, reenter: ";
            cin.clear();
            cin.ignore(1000, '\n'); //clear buffer
            cout << endl;
        }
        index = searchProduct(plu, pluPtr, numRecords);
        if(index == -1){
            cout << "PLU not found" << endl << endl;
            continue; //restart loop
        }
        //input validation for inventory size
        if(inventoryPtr[index] < quantity){
            quantity = inventoryPtr[index];
        }
        totalCost += pricePtr[index] * quantity;
        inventoryPtr[index] -= quantity;
    }
    return totalCost;
}
//gets user choice, a simple print and cin
int getUserChoice(){
    int choice;
    cout << "1 - Checkout" << endl;
    cout << "2 - Print current inventory" << endl;
    cout << "3 - Quit" << endl;
    cin >> choice;
    while(choice < 1 || choice > 3){
        cout << "Invalid choice, reenter: " << endl;
        cin >> choice;
    }
    return choice;
}
//searches for product from plu, returns index of product
int searchProduct(string plu, string * pluPtr, int numRecords){
    for(int i = 0; i < numRecords; i++){
        if(plu == pluPtr[i]){
            return i;
        }
    }
    return -1;
}