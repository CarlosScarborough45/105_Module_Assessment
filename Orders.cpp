#include "./Headers/Manager.h"
#include <sstream>
#include <fstream>
#include <iomanip>

#include "./Headers/Tables.h"
#include "Headers/Order.h"
#include "./Headers/Menu.h"

std::vector<Orders> Orders::checkOrderFile()
{
    std::ifstream file("../Data/Order.csv");
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
        if (line.empty() || line.find("TableNumber") == 0)
        {
            continue;
        }

        Orders o;
        o.price = 0.0;
        ss.clear();
        ss.str(line);
        std::getline(ss, o.TableID, '|');
        std::getline(ss, o.OrderID, '|');
        std::getline(ss, o.Customer, '|');
        std::getline(ss, o.Product, '|');
        std::string people;
        std::getline(ss, people, '|');
        try { o.people = std::stoi(people); } catch (...) { continue; }
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

bool Orders::automaticID(std::string &OrderID)
{
    std::vector<Orders> existing = checkOrderFile();
    int maxID = 0;
    for (const auto &o : existing)
    {
        try
        {
            int id = std::stoi(o.OrderID);
            if (id > maxID) maxID = id;
        }
        catch (...) {}
    }
    int nextID = maxID + 1;
    std::string idStr = std::to_string(nextID);
    while (idStr.size() < 3) idStr = "0" + idStr;
    OrderID = idStr;
    return true;
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

}

void Manager::AddOrders()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Want to Order\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Menu> menu = Menu::check_Menu();

    std::string Table, product, customer;
    std::string OrderID;
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
    
    Orders::automaticID(OrderID);

    std::cout << "Enter Customer Name\n";
    std::cin >> customer;

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
        std::ifstream checkIn("../Data/Order.csv");
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

    std::ofstream file("../Data/Order.csv", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "File has not been created\n";
        return;
    }

    if (writeHeader)
    {
        file << "TableNumber|OrderID|Customer|Product|People|Status\n";
    }

    file << Table << "|" << OrderID << "|" << customer << "|" << product << "|" << people << "|" << "" << "\n";
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
    if (found)
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

                std::ofstream file("../Data/Order.csv");
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

                if (Tables::SetAvailability(table, "Available"))
                {
                    std::cout << "Table " << table << " is now Available\n";
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
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Which order you like to edit\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << std::left << std::setw(20) << "Order ID" << "|" << std::setw(20) << "Product" << "|"
                           << std::setw(20) << "Table ID" << "|" << std::setw(20) << "Customer" << "|" <<"\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto& o : orders) {
        std::cout << std::left << std::setw(20) << o.OrderID << "|" << std::setw(20) << o.Product << "|"
        << o.TableID << "|" << std::setw(20) << o.Customer << "|" << "\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string id;
    std::cout << "select Order for Edit\n";
    std::cin >> id;

    bool found = false;
    Orders Welcome;
    for (const auto& o : orders) {
        if (id == o.OrderID) {
            found = true;
            Welcome = o;
            break;
        }
    }

    if (found) {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Order Found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << "ID" << "|" << std::setw(15) << "Customer" << "|" << std::setw(20) << "Products" << "|" << "\n";
        std::cout << std::left << std::setw(20) << Welcome.OrderID << "|" << std::setw(15) << Welcome.Customer << "|" << std::setw(20) << Welcome.Product << "|" << "\n";
    }
    else if (!found) {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Order not found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }
    std::string cha;
    std::cout << "Enter Which Part of Order You want to Change\n";
    std::cout << "(OrderID, Customer, Product, TableID, status, people)\n";
    std::cin >> cha;

    if (cha != "OrderID" && cha != "Customer" && cha != "Product" && cha != "TableID" &&
        cha != "status" && cha != "people") {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Invalid field name\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::string newValue;
    std::cout << "Enter New Value\n";
    std::cin >> newValue;

    for (auto &o : orders) {
        if (o.OrderID == id) {
            if (cha == "OrderID")  o.OrderID  = newValue;
            else if (cha == "Customer") o.Customer = newValue;
            else if (cha == "Product")  o.Product  = newValue;
            else if (cha == "TableID")  o.TableID  = newValue;
            else if (cha == "status")   o.status   = newValue;
            else if (cha == "people")   o.people   = std::stoi(newValue);
            break;
        }
    }

    std::ofstream file("../Data/Order.csv");
    if (!file.is_open()) {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File is not open\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    file << "TableNumber|OrderID|Customer|Product|People|Status\n";
    for (const auto &o : orders) {
        file << o.TableID << "|" << o.OrderID << "|" << o.Customer << "|"
             << o.Product << "|" << o.people << "|" << o.status << "\n";
    }
    file.close();
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Order Updated" << "\n" << newValue << "\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}