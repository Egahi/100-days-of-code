/**
 * Contains functions for cart class
 */
#include <iostream>
#include <iomanip>
#include "list.h"

using namespace std;

/**
 * initialises member variables of list class
 */
list::list()
{
    for (int i = 0; i < 50; i++)
    {
        enlistedDrug[i].price = 0.00;
    }
    
    howMany = 0; whichDrug = 0;
}

/**
 * adds a new drug to a list
 */
void list::populateList(drug &newDrug)
{
    strcpy(enlistedDrug[howMany].name, newDrug.name);
    enlistedDrug[howMany].quantity = newDrug.quantity;
    enlistedDrug[howMany].price = newDrug.price; 
    howMany++;
}

/**
 * sets the prices for the drugs
 */
void list::setPrice(float price, float &total)
{
    enlistedDrug[whichDrug].price = price;
    total += price * enlistedDrug[whichDrug].quantity;
    whichDrug++;
}

/**
 * displays drugs on list
 */
void list::showList()
{
    for (int i = 0; i < howMany; i++)
    {
        // drug instock
        if (enlistedDrug[i].price != 0.00)
        {
            cout << "* " << setw(2) << i + 1 << "."
                 << setw(25) << enlistedDrug[i].name
                 << setw(6)<< "#" << setw(12)
                 << enlistedDrug[i].price << setw(8)
                 << enlistedDrug[i].quantity << setw(4)
                 << "*"<< endl;
        }

        // out of stock
        else
        {
            cout << "* " << setw(2) << i + 1 << "."
                 << setw(25) << enlistedDrug[i].name
                 << setw(18) << "out of stock" << setw(12)
                 << "*"<< endl;
        }
    }
}