#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/*
ItemToPurchase class with 
default constructor
Public class functions  
    SetName
    SetPrice
    SetQuantity 

    and a get function for each
    */

class ItemToPurchase {
    public:
        ItemToPurchase(); //default constructor
        void SetName(string name);
        void SetPrice(int price);
        void SetQuantity(int quantity);
        string GetName() const;
        int GetPrice() const;
        int GetQuantity() const;
    private:
        string itemName;
        int itemPrice;
        int itemQuantity;
};

#endif