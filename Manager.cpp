#include "Manager.h"

void orders() {
    int orders;
    std::cout << "Welcome to order Customisation\n";
    std::cout << "1. View all pending Orders\n";
    std::cout << "2. View all Complete Orders\n";
    std::cout << "3. View all no Complete Orders\n";
    std::cout << "4. Return to menu\n";
    std::cin >> orders;

    switch (orders) {
        case 1: {break;}
        case 2: {break;}
        case 3: {break;}
        case 4: {std::cout << "Returning back to menu, Thank you!!!!\n"; return;}
        default:{std::cout << "Choose between 1 - 4" << std::endl;}
    }
}

void menu() {
    int menu;
        std::cout << "Welcome to Menu Customisation\n";
        std::cout << "1. Full Menu Display\n";
        std::cout << "2. Edit the Menu Display\n";
        std::cout << "3. Add Specials\n";
        std::cout << "4. Return Manager Menu\n";
        std::cin >> menu;

        switch (menu) {
            case 1: {break;}
            case 2: {break;}
            case 3: {break;}
            case 4: {std::cout << "Returning to the menu display\n"; return;}
            default:{std::cout << "Must choose between 1 - 4" << std::endl; break;}
        }
}

void reports(){}

void Table(){}