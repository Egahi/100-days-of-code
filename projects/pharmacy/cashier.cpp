/**
 * Contains functions for cashier class
 */
#include <iostream>
#include "cashier.h"
#include "list.h"

using namespace std;

/**
 * appends prices of drugs to a list of drugs
 */
void cashier::setPrice(list &pList, list &inStock, float &total)
{
    // track out of stock senerio 
    bool skip;
    
    for (int i = 0; i < pList.getHowMany(); i++)
    {
        skip = true;
        
        for (int j = 0; j < 26; j++)
        {
            // requested drug is available and in required quantity
            if (strcasecmp(pList.drugName(i), inStock.drugName(j)) == 0
                && inStock.drugQty(j) >= pList.drugQty(i))
            {
                pList.setPrice(inStock.drugPrice(j), total);
                inStock.resetDrugQty(j, pList.drugQty(i));
                skip = false;
                continue;
            }
        }
        
        // skip and move to next drug on list
        if (skip)
            pList.resetWhichDrug();
    }
}