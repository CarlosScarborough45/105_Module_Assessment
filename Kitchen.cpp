#include "Global.h"

void kitchen() {

    int kitchen;
    std::cout << "+==================================================+\n";
    std::cout << "|                                                  |\n";
    std::cout << "|           Welcome to Kitchen Display             |\n";
    std::cout << "|                                                  |\n";
    std::cout << "+==================================================+\n";

    std::cout << "+==================================================+\n";
    std::cout << "|                      |                           |\n";
    std::cout << "| 1. Order in progress |  2. Pending orders        |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "|  3. Order as ready   |  4. Return to Menu        |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "+==================================================+\n";
    std::cin >> kitchen;

    switch (kitchen) {

        case 1: {break;}
        case 2: {break;}
        case 3: {break;}
        case 4: {std::cout << "+======================================+\n"
                          << "|                                      |\n"
                          << "|	You are Returning to Staff display   |\n"
                          << "|                                      |\n"
                          << "+======================================+\n"; staff(); break;}

        default:{std::cout << "[X] Must choose between 1 - 4"; break;}
    }

}