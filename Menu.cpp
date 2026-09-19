#include "Headers/Menu.h"
#include "Headers/Stock.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include <limits>
#include <algorithm>

double Menu::price = 0.0;

// worth putting in a utils header — you'll want this in every input function
static void clearLine()
{
    std::cin.clear(); // wake cin back up if it failed
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::AddItem()
{
    Menu m;

    std::cout << "Enter the Id\n";
    while (!(std::cin >> m.menuID))
    {
        std::cout << "Numbers only. Try again\n";
        clearLine();
    }
    clearLine(); // eat the newline so getline doesn't grab it

    std::cout << "Enter the Name\n";
    std::getline(std::cin, m.Name);

    std::cout << "Enter the Price\n";
    while (!(std::cin >> m.price))
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Numbers only. Try again\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        clearLine();
    }
    clearLine();

    std::cout << "Quantity: " << stock::CheckStock(m.Quantity) << "\n";

    bool needsNewline = false;
    std::ifstream existingFile("../Data/Menu.CSV", std::ios::binary);
    if (existingFile)
    {
        existingFile.seekg(0, std::ios::end);
        if (existingFile.tellg() > 0)
        {
            existingFile.seekg(-1, std::ios::end);
            needsNewline = existingFile.peek() != '\n';
        }
    }

    std::ofstream file("../Data/Menu.CSV", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "Could not open Data/Menu.CSV\n";
        return;
    }

    file.seekp(0, std::ios::end);
    if (file.tellp() == 0)
    {
        file << "ID|Name|Price|Quantity|Availability\n";
    }
    else if (needsNewline)
    {
        file << '\n';
    }

    file << m.menuID << "|" << m.Name << "|" << m.price << "|" << m.Quantity << "|"
         << m.avalability << "\n";

    std::cout << "New menu item has been added\n";
}

std::vector<Menu> Menu::check_Menu()
{
    std::vector<Menu> menus;
    std::ifstream file("../Data/Menu.CSV");

    if (!file.is_open())
    {
        return menus;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        Menu m;
        std::string idStr, name, priceStr, field4, field5;

        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, priceStr, '|');

        try
        {
            m.menuID = std::stoi(idStr);
        }
        catch (...)
        {
            continue;
        }

        std::getline(ss, field4, '|');
        std::getline(ss, field5, '|');

        m.Name = name;
        try
        {
            m.price = std::stod(priceStr);
        }
        catch (...)
        {
            m.price = 0.0;
        }

        if (field5.empty())
        {
            // Support rows written before Quantity was added.
            m.Quantity = 0;
            m.avalability = field4;
        }
        else
        {
            try
            {
                m.Quantity = std::stoi(field4);
            }
            catch (...)
            {
                m.Quantity = 0;
            }
            m.avalability = field5;
        }

        menus.push_back(m);
    }

    return menus;
}

void Menu::save_Menu(const std::vector<Menu> &menus)
{
    std::ofstream file("../Data/Menu.CSV");
    if (!file.is_open())
    {
        std::cout << "Could not update Data/Menu.CSV\n";
        return;
    }

    file << "ID|Name|Price|Quantity|Availability\n";
    for (const auto &menu : menus)
    {
        file << menu.menuID << "|" << menu.Name << "|" << menu.price << "|"
             << menu.Quantity << "|" << menu.avalability << "\n";
    }
}

void Menu::EditItem()
{
    std::vector<Menu> menus = check_Menu();

    if (menus.empty())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "No menu items found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << std::left << std::setw(6) << "ID" << "|" << std::setw(25) << "Name" << "|"
              << std::setw(10) << "Price" << "|" << std::setw(10) << "Quantity" << "|\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &m : menus)
    {
        std::cout << std::left << std::setw(6) << m.menuID << "|" << std::setw(25) << m.Name << "|"
                  << std::setw(10) << m.price << "|" << std::setw(10) << m.Quantity << "|\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    int id;
    std::cout << "Enter ID of item to edit\n";
    while (!(std::cin >> id)) { clearLine(); std::cout << "Numbers only. Try again\n"; }

    bool found = false;
    for (const auto &m : menus)
    {
        if (m.menuID == id) { found = true; break; }
    }

    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Item not found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter which field to change (Name, Price, Quantity, Availability)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::string field;
    clearLine();
    std::getline(std::cin, field);

    if (field != "Name" && field != "Price" && field != "Quantity" && field != "Availability")
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Invalid field name\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "Enter new value\n";
    std::string newValue;
    std::getline(std::cin, newValue);

    for (auto &m : menus)
    {
        if (m.menuID == id)
        {
            if (field == "Name")         m.Name       = newValue;
            else if (field == "Price")   { try { m.price    = std::stod(newValue); } catch (...) { std::cout << "Invalid number\n"; return; } }
            else if (field == "Quantity"){ try { m.Quantity = std::stoi(newValue); } catch (...) { std::cout << "Invalid number\n"; return; } }
            else if (field == "Availability") m.avalability = newValue;
            break;
        }
    }

    save_Menu(menus);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Menu item updated\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Menu::RemoveItem()
{
    std::vector<Menu> menus = check_Menu();

    if (menus.empty())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "No menu items found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << std::left << std::setw(6) << "ID" << "|" << std::setw(25) << "Name" << "|"
              << std::setw(10) << "Price" << "|\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &m : menus)
    {
        std::cout << std::left << std::setw(6) << m.menuID << "|" << std::setw(25) << m.Name << "|"
                  << std::setw(10) << m.price << "|\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    int id;
    std::cout << "Enter ID of item to remove\n";
    while (!(std::cin >> id)) { clearLine(); std::cout << "Numbers only. Try again\n"; }

    bool found = false;
    std::string itemName;
    for (const auto &m : menus)
    {
        if (m.menuID == id) { found = true; itemName = m.Name; break; }
    }

    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Item not found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Remove " << itemName << "? (Yes/No)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::string confirm;
    std::cin >> confirm;

    if (confirm != "Yes" && confirm != "yes")
    {
        std::cout << "Removal cancelled\n";
        return;
    }

    menus.erase(std::remove_if(menus.begin(), menus.end(),
        [id](const Menu &m) { return m.menuID == id; }), menus.end());

    save_Menu(menus);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << itemName << " has been removed\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Menu::ViewItem()
{
    auto menus = check_Menu();

    if (menus.empty())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "No menu items found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "|" << "ID" << "|" << "Name" << "|" << "Price" << "|" << "Availability" << "|\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &m : menus)
    {
        stock::CheckStock(m.Quantity);
        std::cout << "| " << std::left << std::setw(4) << m.menuID
                  << " | " << std::setw(28) << m.Name
                  << " | " << std::right
                  << std::setw(6) << "$" << m.price
                  << " | " << std::left << std::setw(19) << stock::status
                  << " |\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Menu::SpecialItem()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Special Item\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Menu> menu = Menu::check_Menu();

    Menu m;

    std::string item;
    int NewPrice;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Which Menu you want to update?\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cin >> item;

    bool found = false;

    for (auto &menuItem : menu)
    {
        if (menuItem.Name == item)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Cannot Find Item\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
    else if (found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Item found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << "Item: " << m.Name << "|" << std::setw(20) << "Price: " << m.price << "\n";
        std::cout << std::string(50, '=') << "\n";
    }

    std::cout << "Enter new Price: \n";
    std::cin >> NewPrice;

    std::ofstream file("../Data/Menu.CSV");
    if (!file)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File has not been created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }
    else if (file)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "file has been created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }

    file << "ID" << "|" << "Name" << "|" << "Price" << "|" << "Quantity" << "|" << "Avalibility" << "|" << "\n";

    for (const auto &menuItem : menu)
    {
        file << menuItem.menuID << "|" << menuItem.Name << "|" << menuItem.price << "|" << menuItem.Quantity << "|"
             << menuItem.avalability << "|" << "\n";
    }

    std::cout << "Menu Item has been changed\n";
    std::cout << m.Name << m.price << "\n";
    return;
}