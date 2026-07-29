#include <sstream>

#include "Admin.h"
#include "Customer.h"
#include "Users.h"
#include "Staff.h"

Users* buildUser(roles r);
roles check(const std::string &roleString);
std::string username, password;
std::string line, Name, Address, Number, csvUsername, csvPassword, roleString;

Users* signin() {
    std::cout << "Welcome to login" << std::endl;
    std::string uname, pass;
    std::cout << "Enter your Username" << std::endl;
    std::cin >> uname;
    std::cout << "Enter your Password" << std::endl;
    std::cin >> pass;

    roles matchedRole;
    std::string name;
    if (readUserFile(uname, pass, matchedRole, name)) {
        return buildUser(matchedRole);
    }

    std::cout << "[X] Login has been unsuccessful Register!!" << std::endl;
    return nullptr;
}

bool checkPassword(const std::string& password) {
    std::ifstream file("../Users.CSV");
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string Name, Address, Number, csvUsername, csvPassword, roleString;
        std::getline(ss, Name, '|');
        std::getline(ss, Address, '|');
        std::getline(ss, Number, '|');
        std::getline(ss, csvUsername, '|');
        std::getline(ss, csvPassword, '|');
        std::getline(ss, roleString, '|');

        if (csvPassword == password) {
            return true;
        }
        return false;
    }
    return true;
}

bool checkUsername(const std::string& username) {
    std::ifstream file("../Users.CSV");
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string Name, Address, Number, csvUsername, csvPassword, roleString;
        std::getline(ss, Name, '|');
        std::getline(ss, Address, '|');
        std::getline(ss, Number, '|');
        std::getline(ss, csvUsername, '|');
        std::getline(ss, csvPassword, '|');
        std::getline(ss, roleString, '|');
        if (csvUsername == username) {
            return true;
        }
        return false;
    }
    return true;
}


bool Users::checkRole(roles role) {
    std::ifstream file("../Users.CSV");
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string Name, Address, Number, csvUsername, csvPassword, roleString;
        std::getline(ss, Name, '|');
        std::getline(ss, Address, '|');
        std::getline(ss, Number, '|');
        std::getline(ss, csvUsername, '|');
        std::getline(ss, csvPassword, '|');
        std::getline(ss, roleString, '|');

        if (stringtorole(roleString) == role) {
            std::cout << "Role is already assigned\n";
            return true;
        }
    }
    return false;
}


bool readUserFile(const std::string& username, const std::string& password, roles& outRole, std::string& outName) {
    std::ifstream file("../Users.CSV");
    if (!file.is_open()) {
        std::cout << "[X] File has not been created" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string Name, Address, Number, csvUsername, csvPassword, roleString;
        std::getline(ss, Name, '|');
        std::getline(ss, Address, '|');
        std::getline(ss, Number, '|');
        std::getline(ss, csvUsername, '|');
        std::getline(ss, csvPassword, '|');
        std::getline(ss, roleString, '|');

        if (csvUsername == username && csvPassword == password) {
            outRole = stringtorole(roleString);
            outName = Name;
            std::cout << "Login successful\nWelcome User [" << Name << "]" << std::endl;
            return true;
        }
    }
    return false;
}

Users* buildUser(roles r) {
    switch (r) {
        case roles::AdminRole: return new Admin();
        case roles::ManagerRole: return new Manager();
        case roles::StaffRole: return new Staff();
        case roles::CustomerRole: return new Customer();
        case roles::WaitStaff: return new WaitStaff();
        case roles::Host: return new Host();
        case roles::Kitchen: return new Kitchen();
        default: return nullptr;
    }
}

roles check(const std::string &roleString) {
    return stringtorole(roleString);
}
