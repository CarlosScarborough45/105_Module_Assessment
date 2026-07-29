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

void StaffAccounts() {
    int staff;
    while (true) {
        std::cout << "Welcome to staff accounts\n";
        std::cout << "1. View all Staff accounts\n";
        std::cout << "2. Add Staff Account\n";
        std::cout << "3. Edit selected Staff account\n";
        std::cout << "4. Delete selected Staff account\n";
        std::cout << "5. Return to Admin Display\n";
        std::cin >> staff;

        switch (staff) {
            case 1: {ViewStaff();   break;}
            case 2: {AddStaff();    break;}
            case 3: {EditStaff();   break;}
            case 4: {DeleteStaff(); break;}
            case 5: {std::cout << "We are returning back to display\n"; return;}
            default:{std::cout << "Must choose between 1 - 5\n";    break;}
        }
    }
}

void ViewStaff() {
    int staff;
    while (true){
        std::cout << "View All Staff Account Menu\n";
        std::cout << "1. View Manager Accounts\n";
        std::cout << "2. View Staff Accounts\n";
        std::cout << "3. Return to Menu Display\n";
        std::cin >> staff;

        switch (staff) {
            case 1: {ManagerAccount();    break;}
            case 2: {ViewStaffAccounts(); break;}
            case 3: {std::cout << "Returning to Menu\n"; return;}
        }
    }
}

void ManagerAccount(){}

void ViewStaffAccounts(){}

void AddStaff(){}

void EditStaff(){}

void MenuControl(){}

void DeleteStaff(){}

void TableControl(){}

void Reports(){}

void Orders(){}