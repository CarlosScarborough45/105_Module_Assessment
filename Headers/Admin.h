#include "Users.h"
#include <iostream>

class Admin : public Users
{
public:
    static void TopBoss();
    static void AccountManagement();
    static void AddStaff();
    static void RemoveStaff();
    static void EditStaff();
    static void RaiseStaff();

    public:
        static void Sales();
        static void reports();
        static void BestSales();
        static void TotalSales();
        static void WorstSales();
        static void SalesCategory();
        static void TableOccupancy();
        static void OrderCount();
        static void ItemOrder();
};

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

}

void Admin::WorstSales(){

}

void Admin::SalesCategory(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Sales By Category\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

}

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

void Admin::TableOccupancy(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Which Table You want to view\n";
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

}