#ifndef BACKEND_00P_USERS_H
#define BACKEND_00P_USERS_H
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

int main();

enum class roles { StaffRole, ManagerRole, CustomerRole, AdminRole, WaitStaff, Kitchen, Host };
bool readUserFile(const std::string& username, const std::string& password, roles& outRole, std::string& outName);
bool checkPassword(const std::string& password);
bool checkUsername(const std::string& username);
class Admin;
class Manager;
class Staff;
class Customer;

static roles stringtorole(const std::string& roleString) {
    if (roleString == "Admin")   return roles::AdminRole;
    if (roleString == "Manager") return roles::ManagerRole;
    if (roleString == "Staff")   return roles::StaffRole;
    if (roleString == "WaitStaff") return roles::WaitStaff;
    if (roleString == "Kitchen") return roles::Kitchen;
    if (roleString == "Host") return roles::Host;
    return roles::CustomerRole;
}

struct UserRecord {
    std::string Name, Address, Number, Username, Password, Role;
};

class Users {
public:
    std::string Name;
    std::string Address;
    std::string Number;
    std::string Password, Username;
    roles role;

    virtual void rolesdashboard() = 0;
    virtual ~Users() = default;

    bool checkRole(roles role);


    static void SaveToFile(const std::vector<UserRecord>& records) {
        std::ofstream file("../Users.CSV", std::ios::trunc);

        UserRecord u;

        for (const auto& r : records) {
            file << r.Name << "|" << r.Address << "|" << r.Number << "|"
                 << r.Username << "|" << r.Password << "|" << r.Role << std::endl;
        }

        file.close();

        std::cout << "User has been saved" << std::endl;
    }

    static std::vector<UserRecord> UserFile() {
        std::vector<UserRecord> records;
        std::ifstream file("../Users.CSV");
        if (!file.is_open()) {
            std::cout << "[X] File has not been created\n";
            return records;
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            UserRecord r;
            std::getline(ss, r.Name, '|');
            std::getline(ss, r.Address, '|');
            std::getline(ss, r.Number, '|');
            std::getline(ss, r.Username, '|');
            std::getline(ss, r.Password, '|');
            std::getline(ss, r.Role, '|');
            records.push_back(r);
        }
        return records;
    }

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
        std::cin.ignore();


        std::string roleinput;

        do {
            std::cout << "Enter your role (Staff / Manager / Customer / Admin)" << std::endl;
            std::cin >> roleinput;

            if (roleinput != "Staff" && roleinput != "Manager" &&
                roleinput != "Customer" && roleinput != "Admin") {
                std::cout << "Invalid role, please try again.\n";
                }

        } while (roleinput != "Staff" && roleinput != "Manager" &&
                 roleinput != "Customer" && roleinput != "Admin");

        file << Name << "|" << Address << "|" << Number << "|"
             << Username << "|" << Password << "|" << roleinput << std::endl;

        file.close();
        std::cout << "[ok] User has been created!!" << std::endl;
    }
};

Users* signin();

#endif