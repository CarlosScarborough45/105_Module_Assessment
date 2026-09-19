#include <iostream>
#include <fstream>
#include "Headers/Order.h"
#include "Headers/Admin.h"
#include "Headers/Tables.h"
#include "Headers/Filesystem.h"

void Admin::reports(){
    int report = 0;
    while(report != 6){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Report menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "[1] Table Occupancy\n";
    std::cout << "[2] Order Count\n";
    std::cout << "[3] Item Order\n";
    std::cout << "[4] Sales Total\n";
    std::cout << "[5] Return Admin menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter the choice\n";
    std::cin >> report;

    switch (report){
        case 1: {TableOccupancy();        break;}
        case 2: {OrderCount();            break;}
        case 3: {ItemOrder();             break;}
        case 4: {TotalSales();            break;}
        case 5:
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Returning to Admin Menu\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            break;
        }
            default: {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Must Choose between 1 - 5\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
        }
    }
    }
}

void Admin::TableOccupancy() {
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Select what Table you want to view\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string ID;
    std::cout << "Enter the Table ID\n";
    std::cin >> ID;

    std::vector<Tables> tables = Tables::checkTableFile();

    Tables foundTable;
    
    bool found = false;
    for (const auto &t : tables){
        if (ID == t.TableID){
            found = true;
            foundTable = t;
            break;
        }
    }
    if (!found){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Id Cannot Be found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
    else if (found){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Id found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";

        std::vector<Orders> orders = Orders::checkOrderFile();

        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << "ID" << "|" << std::setw(20) << "Avalability" << "|" << std::setw(20) << "Capacity" << "|" << "\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
            for (const auto &t : tables){
            std::cout << std::left << std::setw(20) << t.TableID << "|" << std::setw(20) << t.avalible << "|" << std::setw(20) << t.capacity << "|" << "\n";
    }

    std::string order;
    std::cout << "Select which Order\n";
    std::cin >> order;

    bool isorder = false;

    for (const auto &o : orders){
        if (order == o.OrderID){
            isorder = true;
            break;
        }
    }

    if (!isorder){
        std::cout << "Order Id not found\n";
        return;
    }

    else {
        std::cout << "Order ID has been found\n";
        std::cout << std::left << std::setw(20) << "Order ID" << "|" << std::setw(20) << "Customer" << "|" << std::setw(20) << "Product" << "|" << std::setw(20) << "price" << "|" << "\n";
        for (const auto &o : orders){
            if (o.OrderID != order) continue;

            std::cout << std::left << std::setw(20) << o.OrderID << "|" << std::setw(20) << o.Customer << "|" << o.Product << "|" << std::setw(20) << o.price << "|" << "\n";

            std::ofstream file("../Data/Table.occupancy.csv", std::ios::app);
            if (!file.is_open()){
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "File cannot be opened or created\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
            }
            else {
                file << foundTable.TableID << "|" << foundTable.capacity << "|" << o.OrderID << "|" << "\n";
                file.close();
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "Table Occupancy has been saved\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
            }

            break;
        }
    }
}
}