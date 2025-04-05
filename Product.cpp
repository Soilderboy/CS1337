#include "Product.h"

void Product::setProductAttributes(string PLU, string name, int type, double price, int inventory) {
    this->PLU = PLU;
    this->name = name;
    this->type = type;
    this->price = price;
    this->inventory = inventory;
}

void Product::setInventory(int inventory){
    this->inventory = inventory;
}

string Product::getPLU() const {
    return PLU;
}

string Product::getName() const {
    return name;
}

int Product::getType() const {
    return type;
}

double Product::getPrice() const{
    return price;
}

int Product::getInventory() const {
    return inventory;
}

