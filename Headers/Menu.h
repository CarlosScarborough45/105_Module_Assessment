#pragma once
#include "Manager.h"
#include <string>
#include <vector>

class Menu
{

    public:
    int menuID; // numeric id
    std::string Name;
    double price;
    std::string avalability;
    int Quantity = 0;

public:
    static void AddItem();
    static void ViewItem();
    static void EditItem();
    static void RemoveItem();
    static void SpecialItem();
    static std::vector<Menu> check_Menu(); // Declaration of check_Menu
    static void save_Menu(const std::vector<Menu> &menus);
};
