#include <iostream>
#include "Headers/Users.h"

int main()
{

    int choice;
    while (true)
    {
        std::cout << "+=========================================================+\n";
        std::cout << "+                     *                                   +\n";
        std::cout << "+                     *                                   +\n";
        std::cout << "+                     *                                   +\n";
        std::cout << "+    1. Login         *       2. Registration             +\n";
        std::cout << "+                     *                                   +\n";
        std::cout << "+                     *                                   +\n";
        std::cout << "+    3. Exit          *                                   +\n";
        std::cout << "+                     *                                   +\n";
        std::cout << "+=========================================================+\n";
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
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            You are Exiting the Program                  +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";
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