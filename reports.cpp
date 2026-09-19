#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
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
            break;
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

    std::vector<Orders> orders = Orders::checkOrderFile();
    std::map<std::string, double> orderTotals;
    for (const auto &o : orders)
        orderTotals[o.OrderID] += o.price;

    std::cout << std::left << std::setw(15) << "Order ID"
              << std::setw(15) << "Total Sales" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    bool any = false;
    for (const auto &entry : orderTotals){
        if (entry.second >= 50.0){
            std::cout << std::left << std::setw(15) << entry.first
                      << "$" << std::fixed << std::setprecision(2) << entry.second << "\n";
            any = true;
        }
    }
    if (!any) std::cout << "No sales at or above $50\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::WorstSales(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Worst Sales (Total <= $20)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();
    std::map<std::string, double> orderTotals;
    for (const auto &o : orders)
        orderTotals[o.OrderID] += o.price;

    std::cout << std::left << std::setw(15) << "Order ID"
              << std::setw(15) << "Total Sales" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    bool any = false;
    for (const auto &entry : orderTotals){
        if (entry.second <= 20.0){
            std::cout << std::left << std::setw(15) << entry.first
                      << "$" << std::fixed << std::setprecision(2) << entry.second << "\n";
            any = true;
        }
    }
    if (!any) std::cout << "No sales at or below $20\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::SalesCategory(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Sales By Category\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();
    std::vector<Menu>   menu   = Menu::check_Menu();

    if (orders.empty()){
        std::cout << "No orders found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::map<std::string, int>    categoryCount;
    std::map<std::string, double> categoryRevenue;

    for (const auto &o : orders){
        categoryCount[o.Product]++;
        for (const auto &m : menu){
            if (m.Name == o.Product){
                categoryRevenue[o.Product] += m.price;
                break;
            }
        }
    }

    std::cout << std::left << std::setw(20) << "Product"
              << std::setw(10) << "Orders"
              << std::setw(15) << "Revenue" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    for (const auto &entry : categoryCount){
        std::cout << std::left << std::setw(20) << entry.first
                  << std::setw(10) << entry.second
                  << "$" << std::fixed << std::setprecision(2)
                  << categoryRevenue[entry.first] << "\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::OrderCount(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Order Count\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    if (orders.empty()){
        std::cout << "No orders found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    int total     = (int)orders.size();
    int completed = 0;
    int pending   = 0;

    std::map<std::string, int> perTable;

    for (const auto &o : orders){
        if (o.status == "Completed" || o.status == "completed" || o.status == "Complete")
            completed++;
        else
            pending++;
        perTable[o.TableID]++;
    }

    std::cout << "Total Orders  : " << total     << "\n";
    std::cout << "Completed     : " << completed << "\n";
    std::cout << "Pending       : " << pending   << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";
    std::cout << std::left << std::setw(15) << "Table ID" << std::setw(10) << "Orders" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    for (const auto &entry : perTable){
        std::cout << std::left << std::setw(15) << entry.first
                  << std::setw(10) << entry.second << "\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::ItemOrder(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Items Ordered\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();
    std::vector<Menu>   menu   = Menu::check_Menu();

    if (orders.empty()){
        std::cout << "No orders found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::map<std::string, int>    itemCount;
    std::map<std::string, double> itemRevenue;

    for (const auto &o : orders){
        itemCount[o.Product]++;
        for (const auto &m : menu){
            if (m.Name == o.Product){
                itemRevenue[o.Product] += m.price;
                break;
            }
        }
    }

    std::vector<std::pair<std::string, int>> sorted(itemCount.begin(), itemCount.end());
    std::sort(sorted.begin(), sorted.end(),
              [](const std::pair<std::string,int> &a, const std::pair<std::string,int> &b){
                  return a.second > b.second;
              });

    std::cout << std::left << std::setw(20) << "Item"
              << std::setw(10) << "Times Ordered"
              << std::setw(15) << "Total Revenue" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    for (const auto &entry : sorted){
        std::cout << std::left << std::setw(20) << entry.first
                  << std::setw(10) << entry.second
                  << "$" << std::fixed << std::setprecision(2)
                  << itemRevenue[entry.first] << "\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Admin::TotalSales(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Total Sales\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    if (orders.empty()){
        std::cout << "No orders found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    // Sum all item prices per order
    std::map<std::string, double> orderTotals;
    for (const auto &o : orders)
        orderTotals[o.OrderID] += o.price;

    std::cout << std::left << std::setw(15) << "Order ID"
              << std::setw(15) << "Total" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    double grandTotal = 0.0;
    for (const auto &entry : orderTotals){
        std::cout << std::left << std::setw(15) << entry.first
                  << "$" << std::fixed << std::setprecision(2) << entry.second << "\n";
        grandTotal += entry.second;
    }

    // Overwrite Sales.csv with correct per-order totals
    std::ofstream salesFile("../Data/Sales.csv");
    if (salesFile.is_open()){
        salesFile << "OrderID|price|Total Sales|\n";
        for (const auto &entry : orderTotals)
            salesFile << entry.first << "|" << std::fixed << std::setprecision(2)
                      << entry.second << "|" << entry.second << "|\n";
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Grand Total: $" << std::fixed << std::setprecision(2) << grandTotal << "\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}