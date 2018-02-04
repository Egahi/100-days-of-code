#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

using namespace std;

// drug
struct drug
{
    char name[25];
    float price;
    int quantity;
};

class list
{
private:
    drug enlistedDrug[50];
    int howMany;
    int whichDrug;
public:
    list();
    char* drugName(int index) { return enlistedDrug[index].name; }
    float drugPrice(int index) { return enlistedDrug[index].price; }
    int drugQty(int index) { return enlistedDrug[index].quantity; }
    void resetWhichDrug() { whichDrug++; }
    void resetDrugQty(int index, int qty) {enlistedDrug[index].quantity -= qty;}
    void setPrice(float price, float &total);
    int getHowMany(){return howMany;}
    void populateList(drug &newDrug);
    void showList();
};

#endif