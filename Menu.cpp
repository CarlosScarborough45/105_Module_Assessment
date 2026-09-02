#include "Headers/Menu.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;

#include <limits>

// worth putting in a utils header — you'll want this in every input function
static void clearLine() {
    std::cin.clear();  // wake cin back up if it failed
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::AddItem() {
    Menu m;

    std::cout << "Enter the Id\n";
    while (!(std::cin >> m.menuID)) {
        std::cout << "Numbers only. Try again\n";
        clearLine();
    }
    clearLine();  // eat the newline so getline doesn't grab it

    std::cout << "Enter the Name\n";
    std::getline(std::cin, m.Name);

    std::cout << "Enter the Price\n";
    while (!(std::cin >> m.price)) {
        std::cout << "Numbers only. Try again\n";
        clearLine();
    }
    clearLine();

    std::cout << "Enter Status (Available, Out of stock, Pending)\n";
    std::getline(std::cin, m.avalability);

    std::ofstream file("Data/Menu.CSV", std::ios::app);
    if (!file.is_open()) {
        std::cout << "Could not open Data/Menu.CSV\n";
        return;
    }

    file << m.menuID << "|" << m.Name << "|" << m.price << "|"
         << m.avalability << "\n";

    std::cout << "New menu item has been added\n";
}

std::vector<Menu> Menu::check_Menu() {
    std::vector<Menu> menus;
    std::ifstream file("Data/Menu.CSV");

    if (!file.is_open()) {
        return menus;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        Menu m;
        std::string idStr, name, priceStr, avail;

        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, priceStr, '|');
        std::getline(ss, avail, '|');

        try {
            m.menuID = std::stoi(idStr);
        } catch (...) {
            m.menuID = 0;
        }
        m.Name = name;
        try {
            m.price = std::stod(priceStr);
        } catch (...) {
            m.price = 0.0;
        }
        m.avalability = avail;

        menus.push_back(m);
    }

    return menus;
}

void Menu::EditItem() {

}

void Menu::RemoveItem() {

}

void Menu::ViewItem() {
    auto menus = check_Menu();

    if (menus.empty()) {
        std::cout << "No menu items found\n";
        return;
    }

            std::cout <<"+==========================================================+\n";
            std::cout << "+                            Avalable Status              +\n";
            std::cout <<"+==========================================================+\n";
        for (const auto &m : menus) {
            if (m.avalability == "Available") {
                std::cout << "ID: " << m.menuID << " | Name: " << m.Name
                << " | Price: " << m.price << " | Availability: " << m.avalability << "\n";
            }

            std::cout <<"+=========================================================+\n";
            std::cout << "+                            Pending Status              +\n";
            std::cout <<"+=========================================================+\n";
            if (m.avalability == "Pending"){
                std::cout << "ID: " << m.menuID << " | Name: " << m.Name
                << " | Price: " << m.price << " | Availability: " << m.avalability << "\n";
            }

            std::cout << "+==========================================================+\n";
            std::cout << "+                         Out of Stock Status              +\n";
            std::cout << "+==========================================================+\n";
            if (m.avalability == "Out of Stock Status"){
                std::cout << "ID: " << m.menuID << " | Name: " << m.Name
                << " | Price: " << m.price << " | Availability: " << m.avalability << "\n";
            }

            std::cout << "+==========================================================+\n";
            std::cout << "+                                Special Status            +\n";
            std::cout << "+==========================================================+\n";
            if (m.avalability == "Special Status"){
                std::cout << "ID: " << m.menuID << " | Name: " << m.Name
                << " | Price: " << m.price << " | Availability: " << m.avalability << "\n";
            }
        }

    }

void Menu::SpecialItem(){

}