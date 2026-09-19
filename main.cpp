#include <iostream>
#include "Headers/Users.h"

int main()
{

    int choice;
    while (true)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "\nWelcome to Eats And Treats Management System\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "1. Login\n";
        std::cout << "2. Registration\n";
        std::cout << "3. Exit\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Users::Login();

            break;
        }
        case 2:
        {
            Users::registration();

            break;
        }

        case 3:
        {
            std::cout << "Exiting the program.\n";
            exit(0);
        }

        default:
        {
            std::cout << "Must choose between 1 - 3\n";
            break;
        }
        }
    }
}