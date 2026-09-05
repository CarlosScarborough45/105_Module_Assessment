#include "Headers/Users.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

#include "Headers/Admin.h"
#include "Headers/Kitchen.h"
#include "Headers/Manager.h"
#include "Headers/Waitstaff.h"

roles Users::ParseRole(const std::string &roleName)
{
    // Normalise input: trim CR and make lowercase for robust comparisons
    std::string r;
    r.reserve(roleName.size());
    for (char c : roleName)
    {
        if (c == '\r' || c == '\n' || c == ' ')
            continue;
        r.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
    }

    if (r == "admin")
        return roles::Admin;
    if (r == "manager")
        return roles::Manager;
    if (r == "waitstaff")
        return roles::WaitStaff;
    if (r == "waiter")
        return roles::WaitStaff;
    if (r == "kitchen")
        return roles::Kitchen;
    return roles::Admin;
}

namespace
{
    std::string NormaliseUsername(const std::string &username)
    {
        std::string normalised;
        normalised.reserve(username.size());
        for (char c : username)
        {
            normalised.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
        }
        return normalised;
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

// Overload to check whether an email already exists in the users file.
bool checkEmail(const std::string &email)
{
    if (email.empty()){
        return false;
        }
    std::vector<Users::UserRecord> users = Users::check_File();
    for (const auto &u : users)
    {
        if (u.Email == email)
            return false;
            std::cout << "there is an already existing email\n";
    }
    return true;
}

bool checkPassword(const std::string &Password)
{
    if (Password.empty()){
        return false;
        }
    std::vector<Users::UserRecord> users = Users::check_File();
    for (const auto &u : users)
    {
        if (u.Password == Password)
            return false;
            std::cout << "there is an already existing Password\n";
    }
    return true;
}

void Users::Login()
{
    std::cout << "\nLogin\n";

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
        if (NormaliseUsername(inputuser) == NormaliseUsername(u.Username) && inputPass == u.Password)
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
    default:
        break;
    }
    }
    // Pause so user can see role-specific output before returning to main menu
    std::cout << "Press Enter to return to main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Users::registration()
{
    std::cout << "\nRegistration\n";

    UserRecord u;

    std::cout << "Enter your Name\n";
    std::cin >> u.Name;

    
    std::cout << "Enter your Email\n";
    std::cin >> u.Email;
    checkEmail(u.Email);

    std::cout << "Enter Your Password\n";
    std::cin >> u.Password;
    checkPassword(u.Password);

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