#ifndef BACKEND_00P_USERS_H
#define BACKEND_00P_USERS_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

enum class roles { StaffRole, ManagerRole, CustomerRole, AdminRole };

// Forward declarations - tells the compiler "these classes exist,
// full details come later in this file"
class Admin;
class Manager;
class Staff;
class Customer;

// Translates the role text stored in the CSV into our enum
inline roles stringtorole(const std::string& roleString) {
    if (roleString == "Admin")   return roles::AdminRole;
    if (roleString == "Manager") return roles::ManagerRole;
    if (roleString == "Staff")   return roles::StaffRole;
    return roles::CustomerRole;
}

class Users {
protected:
    std::string Password, Username;
    roles role;

private:
    std::string Name;
    std::string Address;
    std::string Number;

public:
    virtual void rolesdashboard() = 0;
    virtual ~Users() = default;

    void Signup() {
        std::cout << "Welcome To Register" << std::endl;

        std::ofstream file("../Users.CSV", std::ios::app);
        if (!file.is_open()) {
            std::cout << "[X] File cannot be created" << std::endl;
            return;
        }
        std::cout << "[ok] File has been created" << std::endl;

        std::cout << "Enter your Name" << std::endl;
        std::cin >> Name;
        std::cout << "Enter your Address" << std::endl;
        std::cin >> Address;
        std::cout << "Enter your Number" << std::endl;
        std::cin >> Number;
        std::cout << "Enter your Username" << std::endl;
        std::cin >> Username;
        std::cout << "Enter your Password" << std::endl;
        std::cin >> Password;

        std::string roleinput;
        std::cout << "Enter your role (Staff / Manager / Customer / Admin)" << std::endl;
        std::cin >> roleinput;

        file << Name << "|" << Address << "|" << Number << "|"
             << Username << "|" << Password << "|" << roleinput << std::endl;
        file.close();
        std::cout << "[ok] User has been created!!" << std::endl;
    }
};

// Now that Users is fully known, the actual role classes can be defined
class Manager : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Manager Dashboard" << std::endl;
    }
};

class Customer : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Customer Dashboard" << std::endl;
    }
};

class Staff : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Staff Dashboard" << std::endl;
    }
};

class Admin : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Admin Dashboard" << std::endl;
    }
};

inline std::unique_ptr<Users> signin() {
    std::cout << "Welcome to login" << std::endl;

    std::string username, password;
    std::cout << "Enter your Username" << std::endl;
    std::cin >> username;
    std::cout << "Enter your Password" << std::endl;
    std::cin >> password;

    std::ifstream file("../Users.CSV");
    if (!file.is_open()) {
        std::cout << "[X] File has not been created" << std::endl;
        return nullptr;
    }

    std::string line, Name, Address, Number, csvUsername, csvPassword, roleString;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::getline(ss, Name, '|');
        std::getline(ss, Address, '|');
        std::getline(ss, Number, '|');
        std::getline(ss, csvUsername, '|');
        std::getline(ss, csvPassword, '|');
        std::getline(ss, roleString, '|');

        // check THIS row immediately, instead of after the loop finishes
        if (csvUsername == username && csvPassword == password) {
            roles userRole = stringtorole(roleString);

            std::cout << "Login successful\nWelcome User [" << Name << "]" << std::endl;

            if (userRole == roles::AdminRole)    return std::make_unique<Admin>();
            if (userRole == roles::ManagerRole)  return std::make_unique<Manager>();
            if (userRole == roles::StaffRole)    return std::make_unique<Staff>();
            if (userRole == roles::CustomerRole) return std::make_unique<Customer>();
        }
    }

    std::cout << "Login has been unsuccessful Register!!" << std::endl;
    return nullptr; // no matching username/password found in the file
}

#endif