/**
 * Contains functions for shelf class
 */
#include <iostream>
#include "shelf.h"

using namespace std;

/**
 * populates pharmacy shelf with drugs
 */
void shelf::stockShelf(char name[25], float price, int quantity)
{
    drug newDrug;
    
    strcpy(newDrug.name, name);
    newDrug.quantity = quantity;
    newDrug.price = price;
    
    // populate list
    inStock.populateList(newDrug);
}