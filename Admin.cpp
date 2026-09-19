#include "Headers/Admin.h"
#include "Headers/Users.h"
#include "Headers/Filemanagement.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

namespace
{
    std::string RoleToString(roles role)
    {
        switch (role)
        {
        case roles::Admin:    return "Admin";
        case roles::Manager:  return "Manager";
        case roles::WaitStaff:return "Waitstaff";
        case roles::Kitchen:  return "Kitchen";
        default:              return "Admin";
        }
    }
}

void Admin::TopBoss()
{
    std::cout << "+======================================+\n";
    std::cout << "+     You are logged in as Admin       +\n";
    std::cout << "+======================================+\n";

    int choice = 0;
        while (choice != 5){
            std::cout << "+======================================+\n";
            std::cout << "+  Welcome to Eats and Treats Admin    +\n";
            std::cout << "+======================================+\n";
            std::cout << "[1] Account Management\n";
            std::cout << "[2] Sales\n";
            std::cout << "[3] Reports\n";
            std::cout << "[4] File Management\n";
            std::cout << "[5] Return to Main Menu\n";
            std::cout << "+======================================+\n";
            std::cout << "Enter your Choice\n";
            std::cin >> choice;

            switch (choice){
                case 1: {AccountManagement(); break;}
                case 2: {Sales();             break;}
                case 3: {reports();           break;}
                case 4: {FileManagement();       break;}
                case 5: {
                        std::cout << "+======================================+\n";
                        std::cout << "+        Returning to Main menu        +\n";
                        std::cout << "+======================================+\n";
                        return;
                    }
        }
    }
}

void Admin::AccountManagement(){
    int choice;
    while(true){
            std::cout << "+====================================================+\n";
            std::cout << "+             Welcome to Account Management          +\n";
            std::cout << "+====================================================+\n";
            std::cout << "[1] Add Staff Account\n";
            std::cout << "[2] Remove Staff Account\n";
            std::cout << "[3] Edit Staff Account\n";
            std::cout << "[4] Raise Staff Account\n";
            std::cout << "[5] Return to Main Menu\n";
            std::cout << "+====================================================+\n";
            std::cout << "Enter your choice:\n";
            std::cin >> choice;

            switch(choice){
                case 1: {AddStaff();         break;}
                case 2: {RemoveStaff();      break;}
                case 3: {EditStaff();        break;}
                case 4: {RaiseStaff();       break;}
                case 5: {
                        std::cout << "+====================================================+\n";
                        std::cout << "+                 Returning to Menu                  +\n ";
                        std::cout << "+====================================================+\n";
                        return;
                    }
            }
    }
}

void Admin::AddStaff(){
    std::cout << "+========================================================+\n";
    std::cout << "+                 Add new Staff                          +\n";
    std::cout << "+========================================================+\n";

    std::vector<UserRecord> users = Users::check_File();
    UserRecord u;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Name\n";
    std::getline(std::cin, u.Name);
    for (const auto &existing : users) {
        if (u.Name == existing.Name) {
            std::cout << "A staff member with that name already exists\n";
            return;
        }
    }

    std::cout << "Enter Email\n";
    std::getline(std::cin, u.Email);
    for (const auto &existing : users) {
        if (u.Email == existing.Email) {
            std::cout << "A staff member with that email already exists\n";
            return;
        }
    }

    std::cout << "Enter Password\n";
    std::getline(std::cin, u.Password);

    std::cout << "Enter Username\n";
    std::getline(std::cin, u.Username);
    for (const auto &existing : users) {
        if (u.Username == existing.Username) {
            std::cout << "A staff member with that username already exists\n";
            return;
        }
    }

    std::string roleinput;
    std::cout << "Enter Role (Waitstaff, Manager, Kitchen)\n";
    std::cin >> roleinput;

    if (roleinput == "Admin" || roleinput == "admin") {
        std::cout << "Cannot create an Admin role\n";
        return;
    }
    if (roleinput == "Manager")        u.role = roles::Manager;
    else if (roleinput == "Waitstaff") u.role = roles::WaitStaff;
    else if (roleinput == "Kitchen")   u.role = roles::Kitchen;
    else {
        std::cout << "Invalid role. Must be Waitstaff, Manager, or Kitchen\n";
        return;
    }

    std::string confirm;
    std::cout << "Do you want to continue? (Yes/No)\n";
    std::cin >> confirm;

    if (confirm == "Yes" || confirm == "yes" || confirm == "Y" || confirm == "y") {
        std::vector<Users::UserRecord> newUser = {u};
        Users::Save(newUser);
        std::cout << "Staff Hired\n";
        std::cout << "Welcome New Staff to Eats and Treats: " << u.Name << "\n";
    }
    else {
        std::cout << "Staff has not been hired\n";
    }
}

void Admin::EditStaff(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Staffing to Edit\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string name;
    std::cout << "Enter the staff name\n";
    std::cin >> name;

    std::vector<Users::UserRecord> users = Users::check_File();

    int index = -1;
    for (int i = 0; i < (int)users.size(); i++){
        if (name == users[i].Name){
            index = i;
            break;
        }
    }
    
    for (const auto &u : users){
        if (name == u.Name){
            if (users[index].role == roles::Admin){
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "Admin cannot change another Admin role\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                return;
            }
        }
    }

    if (index == -1){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "No Staff has been found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Staff has been found\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";


    std::string part;
    std::cout << "Which part do you want to change (Name/Email/Password/Username)\n";
    std::cin >> part;

    if (part != "Name" && part != "name" &&
        part != "Email" && part != "email" &&
        part != "Password" && part != "password" &&
        part != "Username" && part != "username"){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Staff Part cannot be found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::string newvalue;
    std::cout << "Enter the new " << part << "\n";
    std::cin >> newvalue;

    if (part == "Name" || part == "name")           users[index].Name = newvalue;
    else if (part == "Email" || part == "email")    users[index].Email = newvalue;
    else if (part == "Password" || part == "password") users[index].Password = newvalue;
    else if (part == "Username" || part == "username") users[index].Username = newvalue;

    std::cout << "Updated Staff: " << users[index].Name << "|"
              << users[index].Email << "|"
              << users[index].Password << "|"
              << users[index].Username << "\n";

    std::ofstream file("Data/Users.csv");
    if (!file){
        std::cout << "Could not open file for saving\n";
        return;
    }
    for (const auto &u : users){
        file << u.Name << "|" << u.Email << "|" << u.Password << "|"
             << u.Username << "|" << RoleToString(u.role) << "|\n";
    }
    std::cout << "Staff has been updated\n";
}

void Admin::RemoveStaff(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to staff Firing\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string staff;
    std::cout << "Enter the staff you want to be fired\n";
    std::cin >> staff;

    std::vector<UserRecord> users = Users::check_File();

    bool found = false;
    UserRecord fired;
    for (const auto &u : users) {
        if (staff == u.Name) {
            if (u.role == roles::Admin) {
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "Cannot Remove Admin Profiles\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                return;
            }
            std::cout << "User has been found\n";
            fired = u;
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "staff found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << "Name" << "|" << std::setw(20) << "Email"
                  << "|" << std::setw(20) << "Password" << "|" << "roles" << "\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << fired.Name << "|" << std::setw(20) << fired.Email << "|"
                  << std::setw(20) << fired.Password << "|" << RoleToString(fired.role) << "\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }

    else {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "User cannot be found\n";
        std::cout << "Must be a registered users\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::string Fire;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Do you want to Fire this person?\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cin >> Fire;

    if (Fire == "Yes" || Fire == "yes") {
        users.erase(std::remove_if(users.begin(), users.end(),
            [&staff](const UserRecord &u) { return u.Name == staff; }), users.end());

        std::ofstream file("Data/Users.csv");
        if (!file) {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Could not open file for saving\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return;
        }
        if (file) {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "File has been opened\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
        }
        for (const auto &u : users) {
            file << u.Name << "|" << u.Email << "|" << u.Password << "|"
                 << u.Username << "|" << RoleToString(u.role) << "|\n";
        }
        file.close();
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "User has been fired\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
    else if (Fire == "No" || Fire == "no") {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "User has not been fired\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
}

void Admin::RaiseStaff(){

}
