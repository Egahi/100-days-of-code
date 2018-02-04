/**
 * pharnmacy.cpp
 *
 * this program models a pharmacy store
 *
 * @s_egahi
 *
 * this was pharmacy!
 */

#include <iostream>
#include <iomanip>
#include "patient.h"
#include "cashier.h"
#include "shelf.h"

using namespace std;
    
int main(void)
{
    // drug
    drug newDrug;
    
    // shelf in pharmacy
    shelf firstS;
    
    // stock up shelf with drugs
    firstS.stockShelf("panadol", 50.00, 50);
    firstS.stockShelf("penicillin", 100.00, 50);
    firstS.stockShelf("flagil", 150.00, 50);
    firstS.stockShelf("paracetamol", 10.00, 50);
    firstS.stockShelf("vitaminC", 5.00, 50);
    firstS.stockShelf("chloroquin", 60.00, 50);
    firstS.stockShelf("ibucap", 200.00, 50);
    firstS.stockShelf("allomoBitters", 150.00, 50);
    firstS.stockShelf("amoxicillin", 250.00, 50);
    firstS.stockShelf("cephalexin", 150.00, 50);
    firstS.stockShelf("doxycycline", 1000.00, 50);
    firstS.stockShelf("azithromycin", 1550.00, 50);
    firstS.stockShelf("sulfamethoxazole", 2000.00, 50);
    firstS.stockShelf("ciprofloxacin", 10.00, 50);
    firstS.stockShelf("levofloxacin", 100.00, 50);
    firstS.stockShelf("fluconazole", 155.00, 50);
    firstS.stockShelf("nystatin", 300.00, 50);
    firstS.stockShelf("acyclovir", 500.00, 50);
    firstS.stockShelf("valacyclovir", 650.00, 50);
    firstS.stockShelf("hydroxychloroquine", 350.00, 50);
    firstS.stockShelf("ibuprofen", 250.00, 50);
    firstS.stockShelf("aspirin", 750.00, 50);
    firstS.stockShelf("naproxen", 950.00, 50);
    firstS.stockShelf("meloxicam", 150.00, 50);
    firstS.stockShelf("celecoxib", 1050.00, 50);

    // display available drugs
    cout << "************************************************************\n"
         << "*" << setw(30) << "AVAILABLE DRUGS" << setw(30) << "*\n"
         << "************************************************************\n"
         << "*" << setw(60) << "*\n"     
         << "*" << setw(5) << " S/No." << setw(23) << "DRUG" << setw(15)
         << "UNIT PRICE" << setw(12) << "QUANTITY" << setw(4) << "*\n"
         << "*" << setw(60) << "*\n";
    
    firstS.inStock.showList();

    cout << "************************************************************\n\n\n";

    // first patient
    patient firstP;
    
    // number of drugs to buy
    int number;
    
    // welcome prompt
    cout << "Hello, Welcome to Pharmacy XYZ!\n\n"
         << "How many drugs do you want to purchase?\n"
         << "Number: ";
    cin >> number;
    // clear input stream
    cin.ignore();
    
    // prompt for drugs and their quantity(ies)
    for (int i = 0; i < number; i++)
    {
        // drug name
        cout << "\nDrug Name: ";
        cin.getline(newDrug.name, 25);
        
        // drug quantity
        cout << "Quantity: ";
        cin >> newDrug.quantity;
        cin.ignore();
        
        // price not known to patient
        newDrug.price = 0.00;
        
        // add to patient list
        firstP.myList.populateList(newDrug);
    }

    // cashier
    cashier onDuty;
    
    // total expense
    float total = 0;
    
    // cashier appends unit prices to patient's list
    onDuty.setPrice(firstP.myList, firstS.inStock, total);


    // display patient's bill
    cout << "\n\n************************************************************\n"
         << "*" << setw(60) << "*\n"
         << "* " << " PHARMACY XYZ BILL " << setw(40) << "*\n"
         << "*" << setw(60) << "*\n"     
         << "*" << setw(5) << " S/No." << setw(23) << "DRUG" << setw(15)
         << "PRICE" << setw(12) << "QUANTITY" << setw(4) << "*\n"
         << "*" << setw(60) << "*\n";
    
    firstP.myList.showList();
    
    cout << "*" << setw(60) << "*\n"
         << "* -------------------------------------------------------- *\n"
         << "* TOTAL" << setw(29) << "#" << setw(12) << total << setw(13) << "*\n"
         << "* -------------------------------------------------------- *\n"
         << "*" << setw(60) << "*\n"
         << "************************************************************\n";

    // success
    return 0;
}