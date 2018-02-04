#ifndef _SHELF_H_
#define _SHELF_H_
#include <iostream>
#include "list.h"

using namespace std;

class shelf
{
private:
public:
    list inStock;
    void stockShelf(char name[25], float price, int quantity = 50);
};

#endif