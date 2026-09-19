#include "Headers/Kitchen.h"
#include "Headers/Order.h"
#include "Headers/Menu.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>

void kitchen::Cook()
{
    int cook;
    std::cout << std::string(50, '=') << "\n";
    std::cout << "You are Logged into Kitchen Dashboard\n";
    std::cout << std::string(50, '=') << "\n";

    std::cout << std::string(50, '=') << "\n";
    std::cout << "Welcome user\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "[1] View all Pending orders\n";
    std::cout << "[2] View Completed Orders\n";
    std::cout << "[3] Make Pending Orders completed\n";
    std::cout << "[4] Return to menu\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "Enter your Choice\n";
    std::cin >> cook;

    switch (cook)
    {
    case 1:
    {
        Pending();
        break;
    }
    case 2:
    {
        Completed();
        break;
    }
    case 3:
    {
       TurnPending();
        break;
    }
    case 4:
    {
        std::cout << std::string(50, '=') << "\n";
        std::cout << "You are Logging out\n";
        std::cout << "You are Exiting the program\n";
        std::cout << std::string(50, '=') << "\n";
        return;
    }
    }
};

void kitchen::Pending()
{
    std::cout << std::string(50, '=') << "\n";
    std::cout << "View all Pending Orders\n";
    std::cout << std::string(50, '=') << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();
    Menu m;

    std::cout << std::string(50, '=') << "\n";
    std::cout << "Pending Orders\n";
    std::cout << std::string(50, '=') << "\n";

    std::cout << std::string(50, '=') << "\n";
    std::cout << std::left << std::setw(10) << "Id" << "|" << std::setw(10) << "Price" << "|" << std::setw(10) << "Status" << "|" << "\n";
    std::cout << std::string(50, '=') << "\n";
    for (const auto &O : orders)
    {
        if (O.status == "Pending")
        {
            std::cout << std::left << std::setw(6) << O.OrderID << "|" << std::setw(6) << "$" << O.price << "|" << std::setw(6) << O.status << "|" << "\n";
        }
    }
    std::cout << std::string(50, '=') << "\n";

    Cook();
}

void kitchen::Completed()
{
    std::vector<Orders> orders = Orders::checkOrderFile();
    Menu m;

    std::cout << std::string(50, '=') << "\n";
    std::cout << "Completed Orders\n";
    std::cout << std::string(50, '=') << "\n";

    std::cout << std::string(50, '=') << "\n";
    std::cout << std::left << std::setw(10) << "Id" << "|" << std::setw(10) << "Price" << "|" << std::setw(10) << "Status" << "|" << "\n";
    std::cout << std::string(50, '=') << "\n";
    for (const auto &O : orders)
    {
        if (O.status == "Completed")
        {
            std::cout << std::left << std::setw(6) << O.OrderID << "|" << std::setw(6) << "$" << m.price << "|" << std::setw(6) << O.status << "|" << "\n";
        }
    }
    std::cout << std::string(50, '=') << "\n";
    Cook();
}

void kitchen::TurnPending()
{
    std::cout << std::string(50, '=') << "\n";
    std::cout << "Which Order You like to Select into Completed\n";
    std::cout << std::string(50, '=') << "\n";

    std::string choice;
    std::cout << "Enter Order ID\n";
    std::cin >> choice;

    std::vector<Orders> orders = Orders::checkOrderFile();
    Menu m;

    bool order = false;
    Orders selectedOrder;

    for (const auto &o : orders)
    {
        if (choice == o.OrderID)
        {
            std::cout << std::string(50, '=') << "\n";
            std::cout << "Order has been found\n";
            std::cout << std::string(50, '=') << "\n";
            order = true;
            selectedOrder = o;
            break;
        }
    }

    if (!order)
    {
        std::cout << std::string(50, '=') << "\n";
        std::cout << "Order Cannot be found\n";
        std::cout << std::string(50, '=') << "\n";
    }

    else if (order)
    {
        std::cout << std::string(50, '=') << "\n";
        std::cout << "Pending Orders\n";
        std::cout << std::string(50, '=') << "\n";

        for (const auto &O : orders)
        {
            std::cout << std::left << std::setw(6) << O.OrderID << "|" << std::setw(6) << "$" << m.price << "|" << std::setw(6) << O.status << "|" << "\n";
        }
        std::cout << std::string(50, '=') << "\n";

        std::cout << std::string(50, '=') << "\n";
        std::cout << "Which order you want to select to be completed\n";
        std::cout << std::string(50, '=') << "\n";

        std::string name;

        std::cout << std::string(50, '=') << "\n";
        std::cout << "Enter the Name\n";
        std::cout << std::string(50, '=') << "\n";
        std::cin >> name;

        bool found = false;

        for (const auto &currentOrder : orders)
        {
            if (choice == currentOrder.OrderID &&
                name == currentOrder.Customer)
            {
                selectedOrder = currentOrder;
                found = true;
                break;
            }
        }

        if (found)
        {
            std::cout << std::string(50, '=') << "\n";
            std::cout << "Customer has been found\n";
            std::cout << std::string(50, '=') << "\n";
            std::cout << std::left << std::setw(6) << selectedOrder.OrderID
                      << "|" << std::setw(6) << "$" << selectedOrder.price
                      << "|" << std::setw(6) << selectedOrder.status << "|" << "\n";
        }

        else if (!found)
        {
            std::cout << std::string(50, '=') << "\n";
            std::cout << "Customer cannot be found\n";
            std::cout << std::string(50, '=') << "\n";
            return;
        }

        std::string status;
        std::cout << std::string(50, '=') << "\n";
        std::cout << "What part of status you want to change\n";
        std::cout << std::string(50, '=') << "\n";
        std::cin >> status;

        bool statusFound = false;
        if (status == "Complete" || status == "complete" ||
            status == "Completed" || status == "completed")
        {
            statusFound = true;
        }
        if (statusFound)
        {
            selectedOrder.status = "Completed";

            for (auto &currentOrder : orders)
            {
                if (currentOrder.OrderID == selectedOrder.OrderID &&
                    currentOrder.TableID == selectedOrder.TableID &&
                    currentOrder.Customer == selectedOrder.Customer &&
                    currentOrder.Product == selectedOrder.Product)
                {
                    currentOrder.status = selectedOrder.status;
                    break;
                }
            }

            std::ofstream file("Data/Order.csv");
            if (!file.is_open())
            {
                std::cout << "Unable to update Data/Order.csv\n";
                return;
            }

            for (const auto &currentOrder : orders)
            {
                file << currentOrder.TableID << "|" << currentOrder.OrderID << "|"
                     << currentOrder.Customer << "|" << currentOrder.Product << "|"
                     << currentOrder.people << "|" << currentOrder.status << "|\n";
            }

            std::cout << "Order status updated to Completed\n";
            std::cout << std::left << std::setw(6) << selectedOrder.OrderID
                      << "|" << std::setw(6) << "$" << selectedOrder.price
                      << "|" << std::setw(6) << selectedOrder.status << "|\n";
        }
        else if (!statusFound)
        {
            std::cout << std::string(50, '=') << "\n";
            std::cout << "Cannot find current status\n";
            std::cout << std::string(50, '=') << "\n";
            return;
        }
    }
    Cook();
}