#include "Admin.h"
#include <iostream>
#include <vector>
#include <iomanip>

bool Is_Admin(const UserRecord& target) {
    if (target.Role == "Admin") {
        std::cout << "Cannot change status for Admin users\n";
        std::cout << "Must have Master Admin permission\n";
        return true;
    }
    return false;
}

void Admindisplay() {

    int AdminDisplay;
    while (true){
        std::cout << "1. Create/edit/delete staff accounts\n";
        std::cout << "2. Full menu control\n";
        std::cout << "3. Full table configuration\n";
        std::cout << "4. View all reports, all history\n";
        std::cout << "5. Override/cancel any order or reservation\n";
        std::cout << "6. Return to menu\n";
        std::cin >> AdminDisplay;

        switch (AdminDisplay) {
            case 1: {StaffAccounts();   break;}
            case 2: {MenuControl();     break;}
            case 3: {TableControl();    break;}
            case 4: {Reports();         break;}
            case 5: {    break;}
            case 6: {std::cout << "We are Returning back to Login\n"; main();}
            default: {std::cout << "Must choose between 1 - 6" << std::endl; break;}


        }
    }
}

void StaffAccounts() {
    int staffAccount;
    while (true) {
        std::cout << "Welcome to staff accounts\n";
        std::cout << "1. View all Staff accounts\n";
        std::cout << "2. Add Staff Account\n";
        std::cout << "3. Edit selected Staff account\n";
        std::cout << "4. Delete selected Staff account\n";
        std::cout << "5. Return to Admin Display\n";
        std::cin >> staffAccount;

        switch (staffAccount) {
            case 1: {ViewStaff();   break;}
            case 2: {AddStaff();    break;}
            case 3: {EditStaff();   break;}
            case 4: {DeleteStaff(); break;}
            case 5: {std::cout << "We are returning back to Admin display\n"; Admindisplay(); break;}
            default:{std::cout << "Must choose between 1 - 5\n"; break;}
        }
    }
}

void ViewStaff() {
    int staff;
    while (true){
        std::cout << "View All Staff Account Menu\n";
        std::cout << "1. View Manager Accounts\n";
        std::cout << "2. View Staff Accounts\n";
        std::cout << "3. Return to Admin Display\n";
        std::cin >> staff;

        switch (staff) {
            case 1: {ManagerAccount();    break;}
            case 2: {ViewStaffAccounts(); break;}
            case 3: {std::cout << "Returning to Menu\n"; Admindisplay();}
        }
    }
}

void ManagerAccount() {
    const std::vector<UserRecord> users = Users::UserFile();

    std::cout << std::string(65, '-') << std::endl;
    std::cout << "Manager Accounts" << std::endl;
    std::cout << std::string(65, '-') << std::endl;

    bool found = false;

    std::cout << std::string(65, '-') << std::endl;
    std::cout << "|" << std::left << std::setw(10) << "Name" << "|"
    << std::setw(10) << "Username" << "|" << std::setw(10) << "Number" << "|" << std::endl;
    for (const auto& u : users) {
        if (u.Role == "Manager") {
            found = true;
            std::cout << std::left << std::setw(10) << "|" << u.Name << "|"
                       << std::setw(10) << u.Username << "|"
                       << std::setw(10) << u.Number << "|" << std::endl;
        }
    }
    std::cout << std::string(65, '-') << std::endl;
    if (!found) {
        std::cout << "No Manager Accounts been Registered\n";
    }
}

void ViewStaffAccounts(){}

void AddStaff() {
    std::cout << "Welcome Which Staff you want to add?\n";

    Users::Signup();

}

void EditStaff() {
    std::cout << "Welcome to editing Staff Account display\n";

    std::string Edit;
    std::cout << "Enter a name to Edit: \n";
    std::cin >> Edit;

    std::vector<UserRecord> users = Users::UserFile();

    int index = -1;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].Name == Edit) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        if (Is_Admin(users[index])) {
            return;
        }
        std::cout << "Staff has been found" << std::endl;
        std::string Field;
        std::cout << "Select which part you want to edit\n";
        std::cin >> Field;

        if (Field == "Name" || Field == "Address" || Field == "Number" ||
            Field == "Username" || Field == "Password" || Field == "Role") {

            std::string Value;
            std::cout << "Enter a new Value\n";
            std::cin >> Value;

            if (Field == "Name") users[index].Name = Value;
            else if (Field == "Address") users[index].Address = Value;
            else if (Field == "Number") users[index].Number = Value;
            else if (Field == "Username") users[index].Username = Value;
            else if (Field == "Password") users[index].Password = Value;
            else if (Field == "Role") users[index].Role = Value;

            Users::SaveToFile(users);
        } else {
            std::cout << "Not a valid field to edit\n";
        }
    }
    else {
        std::cout << "No Staff has been found" << std::endl;
    }
}

void MenuControl(){}

void DeleteStaff(){}

void TableControl(){}

void Reports(){}

