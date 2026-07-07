#include "Global.h"
#include "Orders.h"
#include <fstream>
#include <sstream>
#include <vector>

void kitchen() {

    int kitchen;
    while (true){
    std::cout << "+==================================================+\n";
    std::cout << "|                                                  |\n";
    std::cout << "|           Welcome to Kitchen Display             |\n";
    std::cout << "|                                                  |\n";
    std::cout << "+==================================================+\n";

    std::cout << "+==================================================+\n";
    std::cout << "|                      |                           |\n";
    std::cout << "| 1. Order in progress |  2. View Pending orders   |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "|  3. Order as ready   |  4. Return to Menu        |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "|                      |                           |\n";
    std::cout << "+==================================================+\n";
    std::cin >> kitchen;

    switch (kitchen) {

        case 1: {break;}
        case 2: {order_is_Pending(); break;}
        case 3: {break;}
        case 4: {std::cout << "+======================================+\n"
                          << "|                                      |\n"
                          << "|	You are Returning to Staff display   |\n"
                          << "|                                      |\n"
                          << "+======================================+\n"; staff(); return;}

        default:{std::cout << "[X] Must choose between 1 - 4"; break;}
    }
    }

}

void order_is_Pending() {
    std::ifstream file("../Orders.CSV");

    if (!file.is_open()) {
        std::cout << "[X] Error cannot open file" << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    std::vector<Order> orders;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        Order O;
        std::stringstream ss(line);

        std::getline(ss, O.orderID, '|');
        std::getline(ss, O.TableNumber, '|');
        std::getline(ss, O.Items, '|');
        std::getline(ss, O.Price, '|');
        std::getline(ss, O.Status, '|');

        orders.push_back(O);
    }
    file.close();

    std::cout << "________________________________________" << std::endl;
    std::cout << "_______   Orders Pending  ______________" << std::endl;
    std::cout << "________________________________________" << std::endl;
        for (const Order& O : orders) {
            std::cout << "  orderID:     [" << O.orderID     << "]" << std::endl;
            std::cout << "  TableNumber: [" << O.TableNumber << "]" << std::endl;
            std::cout << "  Items:       [" << O.Items       << "]" << std::endl;
            std::cout << "  Price:       [" << O.Price       << "]" << std::endl;
            std::cout << "  Status:      [" << O.Status      << "]" << std::endl;
            std::cout << "________________________________________" << std::endl;
        }
}

void order_as_Ready() {

}