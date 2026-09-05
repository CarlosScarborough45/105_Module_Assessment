#include "Headers/Admin.h"
#include "Headers/Users.h"
#include <iostream>
#include <limits>

void Admin::TopBoss()
{
    std::cout << "+======================================+\n";
    std::cout << "+     You are logged in as Admin       +\n";
    std::cout << "+======================================+\n";

    int choice = 0;
        while (choice != 5){
            std::cout << "+======================================+\n";
            std::cout << "+ Welcome to Eats and Treats Management+\n";
            std::cout << "+======================================+\n";
            std::cout << "[1] Account Management\n";
            std::cout << "[2] Role Assignment\n";
            std::cout << "[3] System Configuration\n";
            std::cout << "[4] Recovery\n";
            std::cout << "[5] Return to Main Menu\n";
            std::cout << "+======================================+\n";
            std::cout << "Enter your Choice\n";
            std::cin >> choice;

            switch (choice){
                case 1: {Admin::AccountManagement(); break;}
                case 2: {break;}
                case 3: {break;}
                case 4: {break;}
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
            std::cout << "+             Welcome to Account Mamagement          +\n";
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
                case 1: {Admin::AddStaff();         break;}
                case 2: {Admin::RemoveStaff();      break;}
                case 3: {Admin::EditStaff();        break;}
                case 4: {Admin::RaiseStaff();       break;}
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

    std::cout << "Enter your Name\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, u.Name);

    bool found = false;
    for (const auto &existingUser : users)
    {
        if (u.Name == existingUser.Name)
        {
            found = true;
            break;
        }
    }
    if (found){
        std::cout << "Name is already created\n";
        return;
    }

    if (!found){
        std::cout << "No Name is Assigned\n";
    }

    std::cout << "Enter your Email\n";
    std::getline(std::cin, u.Email);

    bool email = false;
    for (const auto &Email : users){
        if (u.Email == Email.Email){
        email = true;
        break;
        }
    }

    if (!email){
        std::cout << "No Email is created\n";
    }

    if (email){
        std::cout << "Email has been created\n";
        return; 
    }

    std::cout << "Enter your Password\n";
    std::getline(std::cin, u.Password);

    bool password = false;
    for (const auto &Password : users){
        if (u.Password == Password.Password){
            password = true;
            break;
        }
    }

    if (password){
        std::cout << "Password has been created\n";
        return;
    }
    
    if (!password){
        std::cout << "Password has not been created\n";
    }

    std::cout << "Enter your Username\n";
    std::getline(std::cin, u.Username);

    bool username = false;
    for (const auto &User : users){
        if (User.Username == u.Username){
            username = true;
            break;
        }
    }

    if (!username){
        std::cout << "No Username has been created\n";
    }

    if (username){
        std::cout << "Username has been found\n";
        return;
    }
    std::string roleinput;
    std::cout << "Enter your Role\n";
    std::cin >> roleinput;

    if (roleinput == "Admin" || roleinput == "admin"){
        std::cout << "Cannot Create Admin Roll\n";
        return;
    }

    std::string choice;
    std::cout << "Do you want to continue\n";
    std::cin >> choice;

    

    if (choice == "Yes" || "yes" || "Y" || "y"){
        Users::Save(u);
        std::cout << "Staff Hired\n";
        std::cout << "Welcome New Staff to Eats and Treats" << u.Name << "\n";
    }
    else if (choice == "no" || "No" || "N" || "n"){
        std::cout << "Staff has not been hired\n";
        return;
    }

}

void Admin::EditStaff(){

}

void Admin::RemoveStaff(){

}

void Admin::RaiseStaff(){

}