#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Headers/Admin.h"
#include "Headers/Order.h"
#include "Headers/Menu.h"
#include "Headers/Sales.h"

void Admin::Sales(){
    int sales = 0;
    while(sales != 5){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Sales Management" << std::endl;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";   
    std::cout << "[1] Best Sales\n";
    std::cout << "[2] Worst Sales\n";
    std::cout << "[3] Total Sales\n";
    std::cout << "[4] Sales by Category\n";
    std::cout << "[5] Return to Admin Menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter your choice\n";
    std::cin >> sales;

    switch (sales)
    {
    case 1:{Admin::BestSales();    break;}
    case 2:{Admin::WorstSales();   break;}
    case 3:{Admin::TotalSales();   break;}
    case 4:{Admin::SalesCategory();break;}
    case 5:
    {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Returning to Admin Menu\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            Admin::TopBoss();
    }
    
    default: {
              std::cout << "+" << std::string(60, '=') << "+" << "\n";
              std::cout << "Must Choose between 1 - 4\n";
              std::cout << "+" << std::string(60, '=') << "+" << "\n";    
              break;
            }
    }
    }
}

void Admin::BestSales(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Best Sales (Total >= $50)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<struct sales> sale = sales::checkSaleFile();

    std::cout << std::left << std::setw(15) << "ID"
              << std::setw(15) << "Price"
              << std::setw(15) << "Total Sales" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    bool any = false;
    for (const auto &s : sale){
        try {
            if (std::stod(s.TotalSales) >= 50){
                std::cout << std::left << std::setw(15) << s.ID
                          << std::setw(15) << s.Price
                          << std::setw(15) << s.TotalSales << "\n";
                any = true;
            }
        } catch (...) {}
    }
    if (!any) std::cout << "No sales at or above $50\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::WorstSales(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Worst Sales (Total <= $20)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<struct sales> sale = sales::checkSaleFile();

    std::cout << std::left << std::setw(15) << "ID"
              << std::setw(15) << "Price"
              << std::setw(15) << "Total Sales" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    bool any = false;
    for (const auto &s : sale){
        try {
            if (std::stod(s.TotalSales) <= 20){
                std::cout << std::left << std::setw(15) << s.ID
                          << std::setw(15) << s.Price
                          << std::setw(15) << s.TotalSales << "\n";
                any = true;
            }
        } catch (...) {}
    }
    if (!any) std::cout << "No sales at or below $20\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::SalesCategory(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Sales By Category\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

}

void Admin::OrderCount(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "What Order you want to count\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

}

void Admin::ItemOrder(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Items Ordered\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

}

void Admin::TotalSales(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Total Sales\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::ifstream occFile("../Data/Table.occupancy.csv");
    if (!occFile.is_open()){
        std::cout << "Table occupancy file cannot be opened\n";
        return;
    }

    std::vector<Orders> orders = Orders::checkOrderFile();
    std::vector<Menu>   menu   = Menu::check_Menu();

    double grandTotal = 0.0;
    std::ofstream salesFile("../Data/Sales.csv", std::ios::app);

    std::string line;
    while (std::getline(occFile, line)){
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string tableID, capacity, orderID;
        std::getline(ss, tableID,  '|');
        std::getline(ss, capacity, '|');
        std::getline(ss, orderID,  '|');

        if (orderID.empty()) continue;

        double price = 0.0;
        for (const auto &o : orders){
            if (o.OrderID == orderID){
                for (const auto &m : menu){
                    if (m.Name == o.Product){
                        price = m.price;
                        break;
                    }
                }
                break;
            }
        }

        grandTotal += price;

        std::cout << std::left << std::setw(15) << "Order ID:" << orderID
                  << "  Table: " << tableID
                  << "  Price: $" << price << "\n";

        if (salesFile.is_open())
            salesFile << orderID << "|" << price << "|" << price << "\n";
    }

    occFile.close();
    if (salesFile.is_open()) salesFile.close();

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Grand Total: $" << grandTotal << "\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}