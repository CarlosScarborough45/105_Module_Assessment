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
            std::cout << "+  Welcome to Eats and Treats Admin    +\n";
            std::cout << "+======================================+\n";
            std::cout << "[1] Account Management\n";
            std::cout << "[2] Sales\n";
            std::cout << "[3] Reports\n";
            std::cout << "[4] Return to Main Menu\n";
            std::cout << "+======================================+\n";
            std::cout << "Enter your Choice\n";
            std::cin >> choice;

            switch (choice){
                case 1: {Admin::AccountManagement(); break;}
                case 2: {Admin::Sales();             break;}
                case 3: {Admin::reports();           break;}
                case 4: {
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
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Staffing to Edit\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string name;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter the staff\n";
    std::cin >> name;

    std::vector<Users::UserRecord> users = Users::check_File();

    bool found = false;
        for (const auto &u : users){
            if (name == u.Name){
                found = true;
                break;
            }
        }

        if (!found){
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "No Staff has been found\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return;
        }

        if (found){
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Staff has been found\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
        }

        std::string part;
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Which Part you want to change\n";
        std::cin >> part;

        int i = -1;
        int index;
        for (i = 0; i < users.size(); i++){
            if (users[i].Email, users[i].Name, users[i].Password, users[i].Username == part ){
            i = index;
            break;
            }
        }

        if (index == -1){
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "No staff in system\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return;
        }

        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Staff\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        
        bool check = false;         
        for (const auto &u :users){
            if (part == "Name" || part == "Email" || part == "Password" || part == "Username"){
                check = true;
                break;
            }
        }
        if (!check){
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Staff Part cannot be found\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return;
        }
        if (check){
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Staff Part been found\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
        }
        
            std::string newvalue;
            std::cout << "Enter the new" << part << std::endl;
            std::getline(std::cin, newvalue);

            if (part == "Name" || part == "name") users[index].Name = newvalue;
            else if (part == "Email" || part == "email") users[index].Email = newvalue;
            else if (part == "password" || part == "Password") users[index].Password = newvalue;
            else if (part == "Username" || part == "username") users[index].Username = newvalue;

        std::cout << "Updated Staff" << users[index].Name << "|"
                  << users[index].Email << "|"
                  << users[index].Password << "|"
                  << users[index].Username << std::endl;

        Users::Save(users);
}

void Admin::RemoveStaff(){

}

void Admin::RaiseStaff(){

}