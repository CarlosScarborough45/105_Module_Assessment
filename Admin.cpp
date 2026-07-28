#include "Admin.h"
#include <iostream>

void Admindisplay() {

    int Admin;
    std::cout << "1. Create/edit/delete staff accounts\n";
    std::cout << "2. Full menu control\n";
    std::cout << "3. Full table configuration\n";
    std::cout << "4. View all reports, all history\n";
    std::cout << "5. Override/cancel any order or reservation\n";
    std::cout << "6. Return to menu\n";
    std::cin >> Admin;

    switch (Admin) {
        case 1: {StaffAccounts();   break;}
        case 2: {MenuControl();     break;}
        case 3: {TableControl();    break;}
        case 4: {Reports();         break;}
        case 5: {Orders();          break;}
        case 6: {break;}
        default: {std::cout << "Must choose between 1 - 6" << std::endl; break;}
    }
}

void StaffAccounts(){}

void MenuControl(){}

void TableControl(){}

void Reports(){}

void Orders(){}