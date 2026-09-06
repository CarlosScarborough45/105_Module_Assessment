#include "Headers/Waitstaff.h"
#include <iostream>

void WaitStaff::Waiter() {

    std::cout << "+====================================================+\n";
    std::cout << "+         You are logged in as Waiter                +\n";
    std::cout << "+====================================================+\n";

    int choice;
    std::cout << "+====================================================+\n";
    std::cout << "+         Welcome to Eats and Treats Waiter System   +\n";
    std::cout << "+====================================================+\n";
    std::cout << "[1] View All Tables\n";
    std::cout << "[2] View Avalible Menu\n";
    std::cout << "[3] Order Customization\n";
    std::cout << "[4] Return to menu\n";
    std::cout << "+====================================================+\n";
    std::cout << "Enter your Choice\n";
    std::cin >> choice;

    switch(choice){
        case 1: {WaitStaff::table();        break;}
        case 2: {WaitStaff::menu();         break;}
        case 3: {WaitStaff::Order;          break;}
        case 4: { 
                  std::cout << "+===================================================+\n";
                  std::cout << "+            You are Returning to Menu              +\n";
                  std::cout << "+===================================================+\n";
                  return;
                }
    }
}
