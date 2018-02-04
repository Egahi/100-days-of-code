#ifndef _CASHIER_H_
#define _CASHIER_H_
#include <iostream>
#include "list.h"
using namespace std;

class cashier
{
private:
public:
    void setPrice(list &pList, list &inStock, float &total);
};

#endif