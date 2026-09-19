#include "Headers/Users.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Headers/Admin.h"
#include "Headers/Kitchen.h"
#include "Headers/Manager.h"
#include "Headers/Waitstaff.h"


    std::string RoleToString(roles role)
    {
        switch (role)
        {
        case roles::Admin:
            return "Admin";
        case roles::Manager:
            return "Manager";
        case roles::WaitStaff:
            return "Waitstaff";
        case roles::Kitchen:
            return "Kitchen";
        default:
            return "Admin";
        }
    }


bool checkEmail(const std::string &email)
{
    if (email.empty()) return false;
    std::vector<Users::UserRecord> users = Users::check_File();
    for (const auto &u : users)
    {
        if (u.Email == email) {
            std::cout << "There is already an existing email\n";
            return false;
        }
    }
    return true;
}

bool checkPassword(const std::string &Password)
{
    if (Password.empty()) return false;
    std::vector<Users::UserRecord> users = Users::check_File();
    for (const auto &u : users)
    {
        if (u.Password == Password) {
            std::cout << "There is already an existing password\n";
            return false;
        }
    }
    return true;
}

void Users::Login() {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "\nWelcome to Login\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";

        std::string inputuser, inputPass;
        std::cout << "Enter your Username\n";
        std::cin >> inputuser;

        std::cout << "Enter your password\n";
        std::cin >> inputPass;

        std::vector<UserRecord> users = Users::check_File();

        bool found = false;
        roles roleMatch;

        for (const auto &u : users)
        {
            if (inputuser == u.Username && inputPass == u.Password)
            {
                roleMatch = u.role;
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << "User has not been created. You must register.\n";
            return;
        }

        if (found)
        {
            std::cout << "You have successfully logged in\n";
            std::cout << "Welcome, User: " << inputuser << "\n";
            std::cout << "Resolved role: " << RoleToString(roleMatch) << "\n";

            switch (roleMatch)
            {
                case roles::Admin:
                    Admin::TopBoss();
                    break;
                case roles::Manager:
                {
                    Manager manager;
                    manager.Boss();
                    break;
                }
                case roles::WaitStaff:
                {
                    WaitStaff staff;
                    staff.Waiter();
                    break;
                }
                case roles::Kitchen:
                    kitchen::Cook();
                    break;
                default: {
                    std::cout << "+" << std::string(60, '=') << "+" << "\n";
                    std::cout << "Must have a registered role\n";
                    std::cout << "+" << std::string(60, '=') << "+" << "\n";
                    break;
                }
            }
        }
    }

void Users::registration()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "\nWelcome to Registration\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Users::UserRecord> users;
    UserRecord u;

    std::cout << "Enter your Name\n";
    std::cin >> u.Name;

    
    std::cout << "Enter your Email\n";
    std::cin >> u.Email;
    if (!checkEmail(u.Email)) return;

    std::cout << "Enter Your Password\n";
    std::cin >> u.Password;
    if (!checkPassword(u.Password)) return;

    std::cout << "Enter your Username\n";
    std::cin >> u.Username;

    std::string roleStr;
    std::cout << "Enter your Role (Waitstaff, Manager, Admin, Kitchen)\n";
    std::cin >> roleStr;

    if (roleStr == "Admin")           u.role = roles::Admin;
    else if (roleStr == "Manager")    u.role = roles::Manager;
    else if (roleStr == "Waitstaff")  u.role = roles::WaitStaff;
    else if (roleStr == "Kitchen")    u.role = roles::Kitchen;
    else {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Invalid role. Must be Waitstaff, Manager, Admin, or Kitchen.\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    users.push_back(u);

    Users::Save(users);
    
    std::cout << "User has been created\n";
}

void Users::Save(std::vector<Users::UserRecord> &users)
{
    std::ofstream file("../Data/Users.csv", std::ios::app);
    if (!file)
    {
        std::cout << "File has not been created\n";
        return;
    }

    for (const auto &u : users){
    file << u.Name << "|" << u.Email << "|" << u.Password << "|" << u.Username << "|"
         << RoleToString(u.role) << "|\n";
         }
}

std::vector<Users::UserRecord> Users::check_File()
{
    std::vector<UserRecord> users;
    std::ifstream file("../Data/Users.csv");

    if (!file)
    {
        std::cout << "File has not been created\n";
        return users;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        UserRecord u;
        std::string name, email, password, username, role;

        std::getline(ss, name, '|');
        std::getline(ss, email, '|');
        std::getline(ss, password, '|');
        std::getline(ss, username, '|');
        std::getline(ss, role, '|');

        u.Name     = name;
        u.Email    = email;
        u.Password = password;
        u.Username = username;

        if (role == "Admin")          u.role = roles::Admin;
        else if (role == "Manager")   u.role = roles::Manager;
        else if (role == "Waitstaff") u.role = roles::WaitStaff;
        else if (role == "Kitchen")   u.role = roles::Kitchen;
        else                          u.role = roles::Admin;

        users.push_back(u);
    }
    return users;
}