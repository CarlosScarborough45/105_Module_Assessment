#include "Users.h"
#include "Manager.h"

std::unique_ptr<Users> signin() {
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

        if (csvUsername == username && csvPassword == password) {
            roles userRole = stringtorole(roleString);

            std::cout << "Login successful\nWelcome User [" << Name << "]" << std::endl;

            if (userRole == roles::AdminRole)    return std::make_unique<Admin>();
            if (userRole == roles::ManagerRole)  return std::make_unique<Manager>();
            if (userRole == roles::StaffRole)    return std::make_unique<Staff>();
            if (userRole == roles::CustomerRole) return std::make_unique<Customer>();
        }
    }

    std::cout << "[X] Login has been unsuccessful Register!!" << std::endl;
    return nullptr;
}