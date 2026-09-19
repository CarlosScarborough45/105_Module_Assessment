#include "Headers/Waitstaff.h"
#include "Headers/Tables.h"
#include "Headers/Menu.h"
#include "Headers/Order.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

void WaitStaff::Waiter()
{

    std::cout << "+====================================================+\n";
    std::cout << "+         You are logged in as Waiter                +\n";
    std::cout << "+====================================================+\n";

    int choice;
    std::cout << "+====================================================+\n";
    std::cout << "+      Welcome to Eats and Treats Waiter System      +\n";
    std::cout << "+====================================================+\n";
    std::cout << "[1] View All Tables\n";
    std::cout << "[2] View Avalible Menu\n";
    std::cout << "[3] Order Customization\n";
    std::cout << "[4] Return to menu\n";
    std::cout << "+====================================================+\n";
    std::cout << "Enter your Choice\n";
    std::cin >> choice;

    WaitStaff w;

    switch (choice)
    {
    case 1:
    {
        w.table();
        break;
    }
    case 2:
    {
        w.menu();
        break;
    }
    case 3:
    {
        w.Order();
        break;
    }
    case 4:
    {
        std::cout << "+===================================================+\n";
        std::cout << "+            You are Returning to Menu              +\n";
        std::cout << "+===================================================+\n";
        Waiter();
    }
    }
}

void WaitStaff::table()
{

    std::cout << "+====================================================+\n";
    std::cout << "+             Welcome to Table View                  +\n";
    std::cout << "+====================================================+\n";

    std::vector<Tables> table = Tables::checkTableFile();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "+        View all Avalible Tables    +\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << std::left << std::setw(20) << "ID" << "|" << std::setw(20) << "Avalibility" << "|" << std::setw(20) << "Capacity" << "|" << "\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    for (const auto &t : table)
    {
        if (t.avalible == "Avalible")
        {
            std::cout << std::left << std::setw(20) << t.TableID << "|" << std::setw(20) << t.avalible << "|" << std::setw(20) << t.capacity << "|" << "\n";
        }
        else if (t.avalible == "Occupied")
        {
            std::cout << std::left << std::setw(20) << t.TableID << "|" << std::setw(20) << t.avalible << "|" << std::setw(20) << t.capacity << "|" << "\n";
        }
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    WaitStaff::Waiter();
}

void WaitStaff::menu()
{

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "+         Welcome to Menu View       +\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Menu> menus = Menu::check_Menu();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "+         View Avalable Menu   +" << "\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &m : menus)
    {
        std::cout << std::left << std::setw(10) << "ID:" << m.menuID << "|" << std::setw(10) << " Name:" << m.Name << "|"
                  << std::setw(10) << " Price:" << "$" << m.price << "|" << std::setw(10) << " Quantity:" << m.Quantity << "|"
                  << std::setw(10) << " Availability:" << m.avalability << "|" << "\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    WaitStaff::Waiter();
}

void WaitStaff::Order()
{

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Order Menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    int order;
    std::cout << "[1] Add New Order\n";
    std::cout << "[2] View all orders\n";
    std::cout << "[3] View Kitchen status\n";
    std::cout << "[4] Return to menu\n";
    std::cout << "+" << std::string(40, '=') << "+" << "\n";
    std::cout << "Enter your Choice\n";
    std::cin >> order;

    switch (order)
    {
    case 1:
    {
        WaitStaff::Add_Order();
        break;
    }
    case 2:
    {
        WaitStaff::View_Order();
        break;
    }
    case 3:
    {
        WaitStaff::View_Kitchen_Status();
        break;
    }
    case 4:
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Returning back to Waiter Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        WaitStaff::Waiter();
    }
    }
}

void WaitStaff::Add_Order()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Order Menu \n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> order = Orders::checkOrderFile();
    Orders o;
    const std::vector<Menu> menu = Menu::check_Menu();

    std::cout << "Enter Table ID: \n";
    std::cin >> o.TableID;

    bool tableFound = false;
    const std::vector<Tables> tables = Tables::checkTableFile();
    for (const auto &table : tables)
    {
        if (o.TableID == table.TableID)
        {
            tableFound = true;
            if (table.avalible == "Occupied")
            {
                std::cout << "Cannot take an occupied table\n";
                return;
            }
            else
            {
                std::cout << "Table is Avalible\n";
            }
            break;
        }
    }

    if (!tableFound)
    {
        std::cout << "Table ID cannot be found\n";
        return;
    }

    std::cout << "Enter Order ID: \n";
    std::cin >> o.OrderID;

    for (const auto &Orders : order)
    {
        if (o.OrderID == Orders.OrderID)
        {
            std::cout << "Order ID already exists\n";
            continue;
        }
    }
    std::cout << "Order ID cannot be found\n";

    std::cout << "Enter Customer Name: \n";
    std::cin >> o.Customer;
    bool customerFound = false;
    const std::vector<Users::UserRecord> users = Users::check_File();
    for (const auto &user : users)
    {
        if (o.Customer == user.Name)
        {
            std::cout << "Customer has been found\n";
            customerFound = true;
            break;
        }
    }

    if (!customerFound)
    {
        std::cout << "Customer cannot be found\n";
    }

    std::cout << "Enter Product: \n";
    std::cin >> o.Product;

    bool productFound = false;
    for (const auto &menuItem : menu)
    {
        if (o.Product == menuItem.Name)
        {
            productFound = true;
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Product has been found\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";

            std::cout << std::left << std::setw(10) << "Product: " << o.Product << "|"
                      << std::setw(10) << "Price: " << "$" << std::fixed << std::setprecision(2)
                      << menuItem.price << "|" << "\n";
            break;
        }
    }

    if (!productFound)
    {
        std::cout << "Product cannot be found\n";
        return;
    }

    std::cout << "Enter how many People\n";
    std::cin >> o.people;

    int peopleCount = o.people;
    for (const auto &Status : tables)
    {
        if (Status.TableID != o.TableID)
        {
            continue;
        }

        int capacity = std::stoi(Status.capacity);
        if (peopleCount > capacity)
        {
            std::cout << "Table is maxed out please go to another table\n"
                      << "Table: " << o.TableID << "\n";
            return;
        }
        else if (peopleCount == 0)
        {
            std::cout << "Table has not been filled out yet\n";
        }
        break;
    }

    std::cout << "Enter current Status\n";
    std::cin >> o.status;
    order.push_back(o);

    std::ofstream file("Data/Order.csv", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File has not been Created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }
    else if (file.is_open())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File has been Created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }

    file << o.TableID << "|" << o.OrderID << "|" << o.Customer << "|" << o.Product << "|"
         << o.people << "|" << o.status << "|" << "\n";

    file.close();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << " Order has been Created\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Returning to Waiter Menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    WaitStaff::Waiter();
}

void WaitStaff::View_Order()
{
    int order;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to View Order\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "[1] View All Orders\n";
    std::cout << "[2] View Table Orders\n";
    std::cout << "[3] View Customer Order\n";
    std::cout << "[4] Return to Menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter your Choice\n";
    std::cin >> order;

    switch (order)
    {
    case 1:
    {
        WaitStaff::View_Order();
        break;
    }
    case 2:
    {
        WaitStaff::View_Selected_TableOrder();
        break;
    }
    case 3:
    {
        WaitStaff::ViewCustomerOrder();
        break;
    }
    case 4:
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Returning to Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        WaitStaff::Waiter();
    }
    }
}

void WaitStaff::View_Kitchen_Status()
{
    int kitchen;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Kitchen Status\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "[1] check Order Status\n";
    std::cout << "[2] Return to menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter Your choice\n";
    std::cin >> kitchen;

    switch (kitchen)
    {
    case 1:
    {
        WaitStaff::PendingOrder();
        break;
    }
    case 2:
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Return To Waiter Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        WaitStaff::Waiter();
    }
    }
}

void WaitStaff::PendingOrder()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Pending Status\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "+                     Pending Orders                 +\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &o : orders)
    {
        if (o.status == "Pending")
        {
            std::cout << std::left << std::setw(10) << "Order ID: " << o.OrderID << "|" << "\n"
                      << std::setw(10) << "Table: " << o.TableID << "|" << "\n"
                      << std::setw(10) << "Product: " << o.Product << "|" << "\n"
                      << std::setw(10) << "Price: " << "$" << std::fixed << std::setprecision(2) << o.price << "|" << "\n"
                      << std::setw(10) << "Status: " << o.status << "\n";
        }
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void WaitStaff::View_Selected_TableOrder()
{
}

void WaitStaff::ViewCustomerOrder()
{
}