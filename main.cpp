/*

(Below is problem statement)
Prompt the user for a file name. 
Read the file to determine the number of records in the file. If the file open is unsuccessful, print an error message and terminate.
Dynamically allocate an array of Product objects, with a size equal to the number of records, and populate the array with the items read from the file by using the appropriate mutator(s).  Then print the array. For name use setw(17) and left. The remaining parameters are printed right. For price use setw(5) so that your output will match with the testcase.
Loop on displaying the following menu of choices:
1.    Add to inventory
2.    Subtract from inventory
3.    Print info for all products
4.    Exit

(Notes)
Functions I need:
    displayMenu
    displayProducts
    addInventory
    subtractInventory

For the extra credit, we need to add transaction history

Idea for transaction history:
use a struct to hold the transaction history : transaction#, PLU, type, amount

we'll store only the most recent 5
and then update add and subtract inventory to add to the transaction history
*/

#include <iostream>
#include "Product.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
struct Transaction {
    int transactionNumber;
    string PLU;
    int type; //1 for add, 2 for subtract
    int amount;
};

//displays the menu
void displayMenu();

//displays the products: plu, name, type, price, inventory
void displayProducts(Product *products, int size);

//adds to inventory
void addInventory(Product *products, int size, Transaction history[], int &transactionCount);

//subtracts from inventory
void subtractInventory(Product *products, int size, Transaction history[], int &transactionCount);


int main() {
    //input filename and validate file
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);
    if(!file) {
        cout << "Error opening file." << endl;
        return 1;
    }
    //count number of records in file
    int size = 0;
    string line;
    while(getline(file, line)){
        size++;
    }
    //reset file pointer to beg
    file.clear();
    file.seekg(0, ios::beg);

    //create dynamic array of products
    Product *products = new Product[size];

    string PLU, name;
    int type, inventory;
    double price;
    //read file and set product attributes
    for(int i = 0; i < size; i++){
        file >> PLU >> name >> type >> price >> inventory;
        products[i].setProductAttributes(PLU, name, type, price, inventory);
    }

    file.close();


    //display # of records in file and display contents of file
    cout << "There are " << size << " records in the file" << endl;
    cout << endl;
    cout << "Content of object array" << endl;
    cout << "-----------------------" << endl;
    displayProducts(products, size);

    //set up transaction history
    Transaction history[5];
    int transactionCount = 0;


    int choice;
    //menu and the following functions that get activated
    do {
        displayMenu();
        cin >> choice;
        switch(choice) {
            case 1:
                addInventory(products, size, history, transactionCount);
                break;
            case 2:
                subtractInventory(products, size, history, transactionCount);
                break;
            case 3:
                cout << "Current inventory" << endl;
                cout << "-----------------" << endl;
                displayProducts(products, size);
                break;
            case 4:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
    while(choice != 4);
    //display transaction history
    cout << "History of transactions" << endl;
    cout << "-----------------------" << endl;
    //record last 5 transactions
    if(transactionCount > 5){
        transactionCount = 5;
    }
    //most recent transactions first
    for(int i = transactionCount - 1; i >= 0; i--){
        cout << "Transaction #: " << history[i].transactionNumber << ", PLU: " << history[i].PLU << ", type: ";
        if(history[i].type == 1){
            cout << "Add to inventory, ";
        } else {
            cout << "Subtract from inventory, ";
        }
        cout << "amount: " << history[i].amount << endl;
    }

    //delete dynamic array and exit
    delete[] products; 
    return 0;

}

//displays the menu
void displayMenu() {
    cout << endl;
    cout << "Menu" << endl;
    cout << "----" << endl;
    cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
    cout << "3->Print info for all products, 4->Exit" << endl;
}

//displays the products: plu, name, type, price, inventory
void displayProducts(Product *products, int size){
    for(int i = 0; i < size; i++){
        cout << left << "PLU: " << products[i].getPLU() << ", " << setw(17) << products[i].getName() << ", "
        << "type: " << products[i].getType() << ", " << "unit price: " << right << setw(5) << products[i].getPrice() << ", " 
        << "inventory: " << products[i].getInventory() << endl;
    }
}

//adds to inventory - needs input validation for amount
//added transaction history - 
void addInventory(Product *products, int size, Transaction history[], int &transactionCount){
    bool found = false; //if we found PLU
    string PLU;
    int amount = 0;
    cout << "Enter the PLU: ";
    cin >> PLU;
    //check if PLU is valid
    //if not, return
    for(int i = 0; i < size; i++){
        if(products[i].getPLU() == PLU){
            found = true; //found PLU
            break;
        }
    }
    if(!found){
        cout << "PLU not found" << endl;
        return;
    }
    while(amount <= 0){
        cout << "Enter amount to add: ";
        cin >> amount;
        if(amount <= 0){
            cout << "Amount must be > 0" << endl;
        }
    }
    //search for PLU and add to inventory
    for(int i = 0; i < size; i++){
        if(products[i].getPLU() == PLU){
            int newInventory = products[i].getInventory() + amount;
            products[i].setInventory(newInventory);
            found = true; //found PLU

            //log transaction
            if(transactionCount < 5){
                history[transactionCount] = {transactionCount + 1, PLU, 1, amount};
                transactionCount++;
            } else{
                //shift history to the left
                for(int j = 0; j < 4; j++){
                    history[j] = history[j + 1];
                }
                //add new transaction to end
                history[4] = {transactionCount + 1, PLU, 1, amount};
                transactionCount++;
            }

        }
    }
    if(!found){
        cout << "PLU not found." << endl;
    }
}

//subtracts from inventory
//added transaction history
void subtractInventory(Product *products, int size, Transaction history[], int &transactionCount){
    bool found = false; //if we found PLU
    string PLU;
    int amount = 0;
    cout << "Enter the PLU: ";
    cin >> PLU;
    //check if PLU is valid
    //if not, return
    for(int i = 0; i < size; i++){
        if(products[i].getPLU() == PLU){
            found = true; //found PLU
            break;
        }
    }
    if(!found){
        cout << "PLU not found" << endl;
        return;
    }
    while(amount <= 0){
        cout << "Enter amount to subtract: ";
        cin >> amount;
        if(amount <= 0){
            cout << "Amount must be > 0" << endl;
        }
    }
    //search for PLU and subtract from inventory
    for(int i = 0; i < size; i++){
        if(products[i].getPLU() == PLU){
            int newInventory = products[i].getInventory() - amount;
            //if not enough inventory, make it 0
            if(newInventory < 0){
                newInventory = 0;
            }
            products[i].setInventory(newInventory);
            found = true; //found PLU

            //log transaction
            if(transactionCount < 5){
                history[transactionCount] = {transactionCount + 1, PLU, 2, amount};
                transactionCount++;
            } else{
                //shift history to the left
                for(int j = 0; j < 4; j++){
                    history[j] = history[j + 1];
                }
                //add new transaction to end
                history[4] = {transactionCount + 1, PLU, 2, amount};
                transactionCount++;
            }

        }
    }
    if(!found){
        cout << "PLU not found." << endl;
    }
}
