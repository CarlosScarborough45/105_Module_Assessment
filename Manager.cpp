#include "Manager.h"
#include "Tables.h"
#include "Menu.h"

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
            case 1: {Menulist::ml.load_Menu(); break;}
            case 2: {break;}
            case 3: {break;}
            case 4: {std::cout << "Returning to the menu display\n"; return;}
            default:{std::cout << "Must choose between 1 - 4" << std::endl; break;}
        }
}

void reports() {
    int reports;
    std::cout << "Welcome to Report display\n";
    std::cout << "1. Have a daily sales report\n";
    std::cout << "2. Have a weekly sales report\n";
    std::cout << "3. Most ordered items\n";
    std::cout << "4. View all Totals orders\n";
    std::cout << "5. Return to menu\n";
    std::cin >> reports;

    switch (reports) {
        case 1: {break;}
        case 2: {break;}
        case 3: {break;}
        case 4: {break;}
        case 5: {std::cout << "User is returning to menu, Thank you." << std::endl; return;}
        default:{std::cout << "[X] Must choose between 1 - 5" << std::endl; break;}
    }
}

void Table() {
    int table;
    std::cout << "Welcome to table display\n";
    std::cout << "1. View Available Tables\n";
    std::cout << "2. View Occupied Tables\n";
    std::cout << "3. View Reserved Tables\n";
    std::cout << "4. Add Tables\n";
    std::cout << "5. Remove Tables\n";
    std::cout << "6. View all Tables\n";
    std::cout << "7. Return to menu\n";
    std::cin >> table;

    switch (table) {
        case 1: {Available_Table(); break;}
        case 2: {Occupied_Table();  break;}
        case 3: {break;}
        case 4: {add_Table(); break;}
        case 5: {break;}
        case 6: {ViewAllTables(); break;}
        case 7: {std::cout << "Returning to menu, Thankyou.\n"; return;}
        default:{std::cout << "Must choose between 1 - 7" << std::endl; break;}
    }
}