#include <iostream>
#include <cstring>
#include "hashTable.h"
using namespace std;

int main() {
    Hashtable<int> price_menu;

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Pizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);

    price_menu.print();

    int *price = price_menu.search("Noodles");
    (price == NULL) ? cout << "Nope" : cout << "Price is " << *price << endl;

}