#include <iostream>
#include <fstream>
#include "Headers/Admin.h"
#include "Headers/Tables.h"

void Admin::reports(){
    int report;
    while(report != 5){
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
        case 1: {Admin::TableOccupancy();   break;}
        case 2: {Admin::OrderCount();       break;}
        case 3: {Admin::ItemOrder();        break;}
        case 4: {Admin::TotalSales();       break;}
        case 5:
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Returning to Admin Menu\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            Admin::TopBoss();
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

    bool found = false;
    for (const auto &t : tables){
        if (ID == t.TableID){
            found = true;
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
        

        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << "ID" << "|" << std::setw(20) << "Avalability" << "|" << std::setw(20) << "Capacity" << "|" << "\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
            for (const auto &t : tables){
            std::cout << std::left << std::setw(20) << t.TableID << "|" << std::setw(20) << t.avalible << "|" << std::setw(20) << t.capacity << "|" << "\n";
        }
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }

    std::ofstream file("Data/Table.occupancy.csv", std::ios::app);
    if (!file.is_open()){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File cannot be opened or created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
    else {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File has been opened and created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }

    Tables t;

    tables.push_back(t);

    file << "TableID" << "|" << "Capacity" << "|" << "Sales" << "|" << "\n";
    file << t.TableID << "|" << t.capacity << "|" << "|" << "\n";
    file.close();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Table Occupancy has been saved\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}