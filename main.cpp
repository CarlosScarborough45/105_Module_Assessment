#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

#include "Global.h"

// ─────────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────────
int main()
{
    int choice = 0;

    while (choice != 3 && loggedin == false)
    {
        std::cout << "+==================================================+" << std::endl;
        std::cout << "|                                                  |" << std::endl;
        std::cout << "|             Welcome to Eat && Treats             |" << std::endl;
        std::cout << "|                                                  |" << std::endl;
        std::cout << "+==================================================+" << std::endl;
        std::cout << "|  1. Login    |  2. Register  |  3. Exit         |" << std::endl;
        std::cout << "+==================================================+" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
            case 1: { login();  break; }
            case 2: { Signup(); break; }
            case 3: { exit(0); }
            default:
            {
                std::cout << "\n| Must choose between 1 - 3 |\n" << std::endl;
            }
        }
    }

    if (loggedin == true)
    {
        switch (currentUser.role)
        {
            case Roles::Staff:   { staff();   break; }
            case Roles::Manager: { Manager(); break; }
            case Roles::Admin:   { Admin();   break; }
        }
    }

    return 0;
}

// ─────────────────────────────────────────────
//  SIGNUP
// ─────────────────────────────────────────────
void Signup()
{
    User u;
    std::string roleStr;

    std::cout << "+====================================================+" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|              Welcome to Registration               |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "+====================================================+" << std::endl;

    std::cout << "Enter your Name: ";
    std::cin  >> u.fullname;

    std::cout << "Enter your Age: ";
    std::cin  >> u.age;

    std::cout << "Enter your Email: ";
    std::cin  >> u.email;

    std::cin.ignore();

    do{
        std::cout << "Enter your Password: ";
        std::getline(std::cin, u.password);

        if (!isvalidpassword(u.password)) {
            std::cout << "!invalid password try again" << std::endl;
        }
    }while (!isvalidpassword(u.password));

    std::cout << "Enter your Number: ";
    std::cin  >> u.number;

    std::cout << "Enter your Address: ";
    std::cin  >> u.address;

    int role = 0;
    std::cout << "Select your Role > 1. Staff  2. Manager  3. Admin: ";
    std::cin  >> role;

    switch (role)
    {
        case 1: { u.role = Roles::Staff;   roleStr = "Staff";   break; }
        case 2: { u.role = Roles::Manager; roleStr = "Manager"; break; }
        case 3: { u.role = Roles::Admin;   roleStr = "Admin";   break; }
        default:
        {
            std::cout << "\n| Must select between 1 - 3. Defaulting to Staff. |\n";
            u.role  = Roles::Staff;
            roleStr = "Staff";
            break;
        }
    }

    // Check if the file is empty so we only write the header once
    bool needsHeader = false;
    {
        std::ifstream check("../Users.CSV");
        if (!check.good() || check.peek() == std::ifstream::traits_type::eof())
            needsHeader = true;
        check.close();
    }

    std::ofstream file("../Users.CSV", std::ios::app);

    if (!file.is_open())
    {
        std::cout << "\n+==========================================+" << std::endl;
        std::cout << "|   Error: could not open or create file.  |" << std::endl;
        std::cout << "+==========================================+\n" << std::endl;
        return;
    }

    if (needsHeader)
        file << "FullName,Age,Email,Password,Number,Address,Role" << std::endl;

    file << u.fullname << ","
         << u.age      << ","
         << u.email    << ","
         << u.password << ","
         << u.number   << ","
         << u.address  << ","
         << roleStr    << std::endl;

    file.close();

    std::cout << "\n+==========================================+" << std::endl;
    std::cout << "|     New user has been created!           |" << std::endl;
    std::cout << "+==========================================+\n" << std::endl;
}

// ─────────────────────────────────────────────
//  LOGIN
// ─────────────────────────────────────────────
void login()
{
    std::string InputUsername, InputPassword;
    std::vector<User> users;

    std::cout << "+====================================================+" << std::endl;
    std::cout << "|               Welcome to your Login                |" << std::endl;
    std::cout << "+====================================================+" << std::endl;

    std::cout << "Enter your Email: ";
    std::cin  >> InputUsername;

    std::cout << "Enter your Password: ";
    std::cin  >> InputPassword;

    // Read CSV into vector
    std::string line;
    std::fstream file("../Users.CSV");
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (firstLine) { firstLine = false; continue; } // skip header row

        User u;
        std::string roleStr;
        std::stringstream ss(line);

        std::getline(ss, u.fullname, ',');
        std::getline(ss, u.age,      ',');
        std::getline(ss, u.email,    ',');
        std::getline(ss, u.password, ',');
        std::getline(ss, u.number,   ',');
        std::getline(ss, u.address,  ',');
        std::getline(ss, roleStr,    ',');

        // Trim leading space from role string if present
        if (!roleStr.empty() && roleStr.front() == ' ') roleStr.erase(0, 1);

        if      (roleStr == "Staff")   u.role = Roles::Staff;
        else if (roleStr == "Manager") u.role = Roles::Manager;
        else if (roleStr == "Admin")   u.role = Roles::Admin;

        users.push_back(u);
    }
    file.close();

    // Search for matching credentials
    for (const User& u : users)
    {
        if (InputUsername == u.email && InputPassword == u.password)
        {
            currentUser = u;
            loggedin    = true;
            found       = true;
            break;
        }
    }

    if (loggedin)
    {
        std::cout << "\n+==========================================+" << std::endl;
        std::cout << "|  Login successful! Welcome, " << currentUser.fullname << std::endl;
        std::cout << "+==========================================+\n" << std::endl;
    }
    else
    {
        std::cout << "\n+==========================================+" << std::endl;
        std::cout << "|  Incorrect email or password. Try again. |" << std::endl;
        std::cout << "+==========================================+\n" << std::endl;
    }
}