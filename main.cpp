#include <iostream>
#include <memory>

#include "Customer.h"
#include "Users.h"

int main() {
    int login;
    std::cout << "Welcome to Eat and treats" << std::endl;

    while (true){
    std::cout << "1. Login\n";
    std::cout << "2. Registration\n";
    std::cout << "3. Exit" << std::endl;
    std::cin >> login;

    switch (login) {
        case 1: {
            std::unique_ptr<Users> currentUser = signin();
            if (currentUser != nullptr) {
                currentUser->rolesdashboard();
            }
            break;
        }
        case 2: {
            Customer temp;
            temp.Signup();
            break;
        }
        case 3: {
            std::cout << "You are Exiting the program" << std::endl;
            exit(0);
        }
        default: {
            std::cout << "Choose between 1 - 3" << std::endl;
            break;
        }
    }
    }
}