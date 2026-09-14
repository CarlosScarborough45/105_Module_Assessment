#include "./Headers/Manager.h"
#include <sstream>
#include <fstream>
#include "./Headers/Tables.h"
#include "Headers/Order.h"
#include "./Headers/Menu.h"

std::vector<Orders> Orders::checkOrderFile()
{
    std::ifstream file("Data/Order.csv");
    if (!file.is_open())
    {
        std::cout << "File has not been created\n";
        return {};
    }

    std::vector<Orders> orders;
    const std::vector<Menu> menu = Menu::check_Menu();

    std::string line;
    std::stringstream ss;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        Orders o;
        o.price = 0.0;
        ss.clear();
        ss.str(line);
        std::getline(ss, o.TableID, '|');
        std::getline(ss, o.OrderID, '|');
        std::getline(ss, o.customer, '|');
        std::getline(ss, o.Product, '|');
        std::string people;
        std::getline(ss, people, '|');
        o.people = std::stoi(people);
        std::getline(ss, o.status, '|');

        for (const auto &menuItem : menu)
        {
            if (menuItem.Name == o.Product)
            {
                o.price = menuItem.price;
                break;
            }
        }

        orders.push_back(o);
    }
    file.close();

    return orders;
}

bool Tables::CheckTable(const std::string &tableNumber)
{
    const std::vector<Tables> tables = checkTableFile();
    bool found = false;

    for (const Tables &table : tables)
    {
        if (table.TableID == tableNumber)
        {
            found = true;
            if (table.avalible == "Occupied")
            {
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "This Table is Occupied. Please select one that is Avalible\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                return false;
            }

            return true;
        }
    }

    if (!found)
    {
        std::cout << "Table " << tableNumber << " was not found\n";
        return false;
    }

    return false;
}

void Manager::AddOrders()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Want to Order\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Menu> menu = Menu::check_Menu();

    std::string OrderID, Table, product;
    std::cout << "Enter Table Number\n";
    std::cin >> Table;

    if (!Tables::CheckTable(Table))
    {
        return;
    }

    if (!Tables::SetAvailability(Table, "Occupied"))
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Unable to mark table as Occupied\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "Enter OrderID\n";
    std::cin >> OrderID;

    std::cout << "Enter product\n";
    std::cin >> product;

    bool found = false;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Selected Product\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &M : menu)
    {
        if (product == M.Name)
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Product has been found\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            found = true;
        }

        if (found)
        {
            std::cout << "Name: " << M.Name << "\n"
                      << "Price: " << "$" << M.price << "\n";
        }
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Cannot Find product\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    int people = 0;
    std::cout << "Enter number of people\n";
    std::cin >> people;
    if (!Orders::automate_people(people))
    {
        std::cout << "The number of people must be between 1 and 10\n";
        return;
    }

    // Only write header when the file is empty or doesn't exist
    bool writeHeader = false;
    {
        std::ifstream checkIn("Data/Order.csv");
        if (!checkIn.is_open())
        {
            writeHeader = true;
        }
        else
        {
            // If file exists but is empty, write header
            if (checkIn.peek() == std::ifstream::traits_type::eof())
            {
                writeHeader = true;
            }
        }
    }

    std::ofstream file("Data/Order.csv", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "File has not been created\n";
        return;
    }

    if (writeHeader)
    {
        file << "|TableNumber|OrderID|Product|People|Status\n";
    }

    // Write a status field (empty) to keep columns consistent
    file << "|" << Table << "|" << OrderID << "|" << product << "|" << people << "|" << "" << "\n";
    file.close();
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "New order has been issued go to kitchen for processing\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
};

void Manager::RemoveOrders()
{
    std::string table;
    std::cout << "Enter the finished table number\n";
    std::cin >> table;

    auto tables = Tables::checkTableFile();

    bool found = false;
    for (const auto &t : tables)
    {
        if (table == t.TableID)
        {
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Table has not been found\n";
        return;
    }
    else if (found)
    {
        std::cout << "Table has been found\n";

        std::string ID;
        std::cout << "select OrderID\n";
        std::cin >> ID;

        bool order = false;
        Orders selectedOrder;
        std::vector<Orders> orders = Orders::checkOrderFile();

        for (const auto &o : orders)
        {
            if (ID == o.OrderID)
            {
                std::cout << "Order has been found\n";
                order = true;
                selectedOrder = o;
                break;
            }
        }

        if (!order)
        {
            std::cout << "Order Cannot be found\n";
            return;
        }

        if (order)
        {
            std::cout << "+=========================================+\n";
            std::cout << "+             Selected Order              +\n";
            std::cout << "+=========================================+\n";
            std::vector<Menu> menu = Menu::check_Menu();
            std::cout << "Order ID:" << selectedOrder.OrderID << "\n"
                      << " Products: " << selectedOrder.Product << "\n";
            for (const auto &m : menu)
            {
                if (m.Name == selectedOrder.Product)
                {
                    std::cout << " Price: $" << m.price << "\n";
                    break;
                }
            }
            std::cout << "+=========================================+\n";

            std::string status;
            std::cout << "enter status\n";
            std::cin >> status;

            if (status == "Completed" || status == "completed" || status == "complete")
            {
                for (auto &currentOrder : orders)
                {
                    if (currentOrder.OrderID == ID && currentOrder.TableID == table)
                    {
                        currentOrder.status = "Completed";
                    }
                }

                std::ofstream file("Data/Order.csv");
                if (!file.is_open())
                {
                    std::cout << "file has not been created\n";
                    return;
                }
                file << "|TableNumber|OrderID|Product|People|Status\n";
                for (const auto &currentOrder : orders)
                {
                    file << "|" << currentOrder.TableID << "|" << currentOrder.OrderID << "|"
                         << currentOrder.Product << "|" << currentOrder.people << "|"
                         << currentOrder.status << "\n";
                }
                std::cout << "Order has been updated\n";

                if (Tables::SetAvailability(table, "Avalible"))
                {
                    std::cout << "Table " << table << " is now Avalible\n";
                }
                else
                {
                    std::cout << "Unable to update table status\n";
                }
            }
            else
            {
                std::cout << "Enter complete, completed, or Completed to finish the order\n";
            }
        }
    }
}

void Manager::EditOrders()
{
}