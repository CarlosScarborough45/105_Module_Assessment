#include "Headers/Manager.h"
#include "Headers/Menu.h"
#include "./Headers/Tables.h"

void Manager::Boss()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+            You are Logged in As Manager                 +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    int choice;
    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to then Manager View                  +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Menu         *       2. Reporting               +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3. Table        *       4. OverRides               +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         5. Logout       *       6. Profile                 +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         7. Orders       *                                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";

        std::cout << "Please Enter your choice\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Manager::MenuCustomization();
            break;
        }
        case 2:
        {
            Manager::Reports();
            break;
        }
        case 3:
        {
            Manager::Tables();
            break;
        }
        case 4:
        {
            Manager::OverRide();
            break;
        }
        case 5:
        {
            return;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            Manager::OrderMenu();
            break;
        }
        default:
        {
            std::cout << "Invalid choice\n";
            break;
        }
        }
    }
}

void Manager::MenuCustomization()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+            Welcome to the Menu Manager                  +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    int choice;

    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Menu View                      +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Add Item     *       2. Remove Item             +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3 Special       *       4. Edit Item               +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         5. Return       *       6.  View Menu              +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Menu::AddItem();
            break;
        }
        case 2:
        {
            Menu::RemoveItem();
            break;
        }
        case 3:
        {
            Menu::SpecialItem();
            break;
        }
        case 4:
        {
            Menu::EditItem();
            break;
        }
        case 5:
        {
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            you are returning to Menu Display            +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";
            return;
        }
        case 6:
        {
            Menu::ViewItem();
            break;
        }
        }
    }
}

void Manager::OverRide()
{
}

void Manager::Reports()
{
}

void Manager::OrderMenu()
{
    int Order;
    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Order View                     +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Add Order    *       2. Remove Order            +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3. Edit Order   *       4. Return                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";
        std::cin >> Order;

        switch (Order)
        {
        case 1:
        {
            Manager::AddOrders();
            break;
        }
        case 2:
        {
            Manager::RemoveOrders();
            break;
        }
        case 3:
        {
            Manager::EditOrders();
            break;
        }
        default:
        {
            std::cout << "Must choose between 1 - 4\n";
            return;
        }
        }
    }
}

void Manager::Tables()
{

    int choice;

    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Table Menu                     +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Add Table    *       2. Remove Table            +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3. EditTable    *       4. Return                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         5. ViewTable    *                                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Tables::AddTable();
            break;
        }
        case 2:
        {
            Tables::RemoveTable();
            break;
        }
        case 3:
        {
            Tables::RemoveTable();
            break;
        }
        case 4:
        {
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            You are returning to Manager Display         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";
            return;
        }
        case 5:
        {
            Tables::ViewTable();
            break;
        }
        }
    }
}