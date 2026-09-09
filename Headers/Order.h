#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Orders
{
public:
    std::string OrderID;
    std::string TableID;
    std::string Customer;
    int price;
    std::string Product;
    std::string people;
    std::string status;

    static std::vector<Orders> checkOrderFile();

    static void savefile(const Orders &order)
    {
        std::ofstream file("Data/Order.csv", std::ios::app);
        if (!file.is_open())
        {
            std::cout << std::string(50, '=') << "\n";
            std::cout << "File has not been created\n";
            std::cout << std::string(50, '=') << "\n";
            return;
        }

        file << "|" << order.TableID << "|" << order.OrderID << "|" << order.Product << "|" << order.people << "|" << "" << "\n";
        file.close();

        std::cout << std::string(50, '=') << "\n";
        std::cout << "Order Saved\n";
        std::cout << std::string(50, '=') << "\n";
    }
};