#include "Headers/Menu.h"
#include <fstream>
#include <vector>

void Menu::AddItem() {

    std::ofstream file("Data/Menu.CSV", std::ios::app);
    if (!file.is_open()){
        std::cout << "File has not been created\n";
        return;
    }

    std::vector<Menu> menu;

    std::cout << "Select which Item you want to add\n";

}

void Menu::EditItem() {

}

void Menu::RemoveItem() {

}

void Menu::ViewItem() {

}