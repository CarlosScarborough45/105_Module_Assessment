#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "Headers/Manager.h"
#include "Headers/OverRides.h"
#include "Headers/Tables.h"
#include "Headers/Order.h"

void Manager::OverRide()
{
    int Override = 0;
    do{
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Welcome to Overide menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "[1] Adjusting orders\n";
        std::cout << "[2] Make Table Avalible\n";
        std::cout << "[3] Make Table Researved\n";
        std::cout << "[4] Reassign Order to another Table\n";
        std::cout << "[5] Reassign Customers to another Table\n";
        std::cout << "[6] Comp an Item(void, comp and discounted)\n";
        std::cout << "[7] Return to Manager Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Enter Choice\n";
        std::cin >> Override;

        switch(Override){

            case 1: {
                OverRide::AdjustOrders();
                break;
            }
            case 2:{
                OverRide::MakeTableAvalible();
                break;
            }
            case 3:{
                OverRide::MakeTableReserved();
                break;
            }
            case 4:{
                OverRide::ReassignOrder();
                break;
            }
            case 5:{
                OverRide::ReassignCustomer();
                break;
            }
            case 6:{
                OverRide::CompanItem();
                break;
            }
            case 7:{
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "Returning to Manager Menu\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                break;
            }

            default: 
            {
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                std::cout << "Invalid choice must choose between 1 - 7\n";
                std::cout << "+" << std::string(60, '=') << "+" << "\n";
                break;
            }
        }

    }while(Override != 7);
}

void OverRide::AdjustOrders(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Reference\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void OverRide::MakeTableAvalible(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Reference\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Tables> tables = Tables::checkTableFile();
    
    std::string ID;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Select a Table\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cin >> ID;

    bool found = false;
    Tables TableFound;
    for (const auto &t : tables){
        if (ID == t.TableID){
            TableFound = t;
            found = true;
            break;
        }
    }

    if (!found){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table ID cannot be found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    if (found){
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table ID has been found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << std::left << std::setw(20) << "Table ID" << "|" << std::setw(20) << "Status" << "|" << std::setw(20) << "Capacity" << "|" << "\n";
        std::cout << std::left << std::setw(20) << TableFound.TableID << "|" << std::setw(20) << TableFound.avalible << "|" << std::setw(20) << TableFound.capacity << "|" << "\n";
    }

    std::string avalible;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Make Table Avalible\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cin >> avalible;

    if (avalible == "Available" || avalible == "available"){
        if (Tables::SetAvailability(TableFound.TableID, "Available")){
            std::cout << "Table Changed to Available\n";
        }
        else{
            std::cout << "Could not update table availability\n";
        }
    }
}

void OverRide::MakeTableReserved(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Reference\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void OverRide::ReassignCustomer(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Reference\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

}

void OverRide::ReassignOrder(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Reference\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    
}

void OverRide::CompanItem(){
    int comp = 0;
    do{  
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Comp menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "[1] Void an Order\n";
    std::cout << "[2] Comp an Item\n";
    std::cout << "[3] Discount an Item\n";
    std::cout << "[4] Return to Manager menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter Choice\n";
    std::cin >> comp;

    switch(comp){
        case 1:
        {
            OverRide::VoidAnOrder();
            break;
        }
        case 2:
        {
            OverRide::CompAnItem();
            break;
        }
        case 3:
        {
            OverRide::DiscountAnItem();
            break;
        }
        case 4:
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Returning to Manager Menu\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            break;
        }
        default:
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Must choose between 1 - 4\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
        }
    }
    }while(comp != 4);
}

static void saveOrders(const std::vector<Orders> &orders)
{
    std::ofstream file("../Data/Order.csv");
    if (!file.is_open()) { std::cout << "Could not open order file\n"; return; }
    file << "TableNumber|OrderID|Customer|Product|People|Status\n";
    for (const auto &o : orders)
        file << o.TableID << "|" << o.OrderID << "|" << o.Customer << "|"
             << o.Product << "|" << o.people << "|" << o.status << "\n";
}

void OverRide::VoidAnOrder(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Void an Order\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    std::string id;
    std::cout << "Enter Order ID to void\n";
    std::cin >> id;

    bool found = false;
    for (const auto &o : orders) { if (o.OrderID == id) { found = true; break; } }

    if (!found){
        std::cout << "Order not found\n";
        return;
    }

    std::string confirm;
    std::cout << "Void order " << id << "? (Yes/No)\n";
    std::cin >> confirm;
    if (confirm != "Yes" && confirm != "yes"){ std::cout << "Cancelled\n"; return; }

    orders.erase(std::remove_if(orders.begin(), orders.end(),
        [&id](const Orders &o){ return o.OrderID == id; }), orders.end());

    saveOrders(orders);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Order " << id << " has been voided\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void OverRide::CompAnItem(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Comp an Item (complimentary - no charge)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    std::string id;
    std::cout << "Enter Order ID to comp\n";
    std::cin >> id;

    bool found = false;
    for (auto &o : orders){
        if (o.OrderID == id){
            o.status = "Comped";
            found = true;
            break;
        }
    }

    if (!found){ std::cout << "Order not found\n"; return; }

    saveOrders(orders);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Order " << id << " marked as Comped\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void OverRide::DiscountAnItem(){
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Discount an Item\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Orders> orders = Orders::checkOrderFile();

    std::string id;
    std::cout << "Enter Order ID to discount\n";
    std::cin >> id;

    bool found = false;
    for (const auto &o : orders){ if (o.OrderID == id){ found = true; break; } }

    if (!found){ std::cout << "Order not found\n"; return; }

    int pct;
    std::cout << "Enter discount percentage (e.g. 10 for 10%)\n";
    std::cin >> pct;
    if (pct <= 0 || pct >= 100){ std::cout << "Discount must be between 1 and 99\n"; return; }

    for (auto &o : orders){
        if (o.OrderID == id){
            o.status = "Discounted-" + std::to_string(pct) + "%";
            break;
        }
    }

    saveOrders(orders);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Order " << id << " discounted by " << pct << "%\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}