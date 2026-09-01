#include "Headers/Users.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Headers/Admin.h"
#include "Headers/Kitchen.h"
#include "Headers/Manager.h"
#include "Headers/Waitstaff.h"

namespace
{
    roles ParseRole(const std::string &roleName)
    {
        if (roleName == "Admin")
            return roles::Admin;
        if (roleName == "Manager")
            return roles::Manager;
        if (roleName == "Waitstaff")
            return roles::WaitStaff;
        if (roleName == "Kitchen")
            return roles::Kitchen;
        return roles::Admin;
    }

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
}

void Users::Login()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+            You are Entering Your Login                  +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    std::string inputuser, inputPass;
    std::cout << "Enter your Username\n";
    std::cin >> inputuser;

    std::cout << "Enter your password\n";
    std::cin >> inputPass;

    std::vector<Users::UserRecord> users = Users::check_File();

    bool found = false;
    roles roleMatch = roles::Admin;

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
    default:
        break;
    }
}

void Users::registration()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+            You are Entering Your Registration           +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    UserRecord u;

    std::cout << "Enter your Name\n";
    std::cin >> u.Name;

    std::cout << "Enter your Email\n";
    std::cin >> u.Email;

    std::cout << "Enter Your Password\n";
    std::cin >> u.Password;

    std::cout << "Enter your Username\n";
    std::cin >> u.Username;

    std::string roleInput;
    std::cout << "Enter your Role (Waitstaff, Manager, Admin, Kitchen)\n";
    std::cin >> roleInput;

    u.role = ParseRole(roleInput);
    Users::Save(u);
    std::cout << "User has been created\n";
}

void Users::Save(const UserRecord &user)
{
    std::ofstream file("Data/Users.csv", std::ios::app);
    if (!file)
    {
        std::cout << "File has not been created\n";
        return;
    }

    file << user.Name << "|" << user.Email << "|" << user.Password << "|" << user.Username << "|"
         << RoleToString(user.role) << "|\n";
}

std::vector<Users::UserRecord> Users::check_File()
{
    std::vector<UserRecord> users;
    std::ifstream file("Data/Users.csv");

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

        u.Name = name;
        u.Email = email;
        u.Password = password;
        u.Username = username;
        u.role = ParseRole(role);

        users.push_back(u);
    }

    return users;
}