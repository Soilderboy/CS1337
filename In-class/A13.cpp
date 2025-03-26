/*
Three files to submit:
ItemToPurchase.h //where the class is defined - class, private variables, functions prototypes
ItemToPurchase.cpp //function definitions
main.cpp //program that uses the class

It's a shopping cart program

ItemToPurchase class with 
default constructor
Public class functions  
    SetName
    SetPrice
    SetQuantity 

    and a get function for each

Private data members
    string itemName
    int itemPrice
    int itemQuantity

in main
    prompt user for two items and create two objects of ItemToPurchase class
    before prompting for second item, call cin.ignore to input a new string

    add the costs of the two items and output the total cost
*/

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
    //prompt user for two items, create two objects, add costs, output total costs
    ItemToPurchase item1;
    ItemToPurchase item2;
    
    string name;
    int price;
    int quantity;

    //get info for both items: name, price, quantity

    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item1.SetName(name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;

    item1.SetPrice(price);
    item1.SetQuantity(quantity);

    cin.ignore();
    cout << endl; //clear buffer and new line
    cout << "Item 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);
    item2.SetName(name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;

    item2.SetPrice(price);
    item2.SetQuantity(quantity);

    cout << endl; //new line
    //output total cost and individual costs
    int totalCost = item1.GetPrice() * item1.GetQuantity() + item2.GetPrice() * item2.GetQuantity();
    cout << "TOTAL COST" << endl;

    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetPrice() * item1.GetQuantity() << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetPrice() * item2.GetQuantity() << endl;

    cout << endl; //new line
    cout << "Total: $" << totalCost << endl;

    return 0;
}