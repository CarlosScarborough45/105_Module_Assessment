#ifndef BACKEND_00P_USERS_H
#define BACKEND_00P_USERS_H
#include <string>
#include <fstream>
#include <iostream>
#include <memory>

int main();

enum class roles { StaffRole, ManagerRole, CustomerRole, AdminRole, WaitStaff, Kitchen, Host };

class Admin;
class Manager;
class Staff;
class Customer;

inline roles stringtorole(const std::string& roleString) {
    if (roleString == "Admin")   return roles::AdminRole;
    if (roleString == "Manager") return roles::ManagerRole;
    if (roleString == "Staff")   return roles::StaffRole;
    if (roleString == "WaitStaff") return roles::WaitStaff;
    if (roleString == "Kitchen") return roles::Kitchen;
    if (roleString == "Host") return roles::Host;
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
   void rolesdashboard();
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

Users* signin();

#endif