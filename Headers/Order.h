#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Orders
{
    public:
    std::string OrderID;
    double      price;
    std::string Customer;
    std::string TableID;
    std::string Product;
    int         people = 0;
    std::string status;

    static bool automaticID(std::string &OrderID);

public:

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

        file << order.TableID << "|" << order.OrderID << "|" << order.Customer << "|" << order.Product << "|" << order.people << "|" << "" << "\n";
        file.close();

        std::cout << std::string(50, '=') << "\n";
        std::cout << "Order Saved\n";
        std::cout << std::string(50, '=') << "\n";
    }

    inline static bool automate_people(int peopleCount)
    {
        return peopleCount >= 1 && peopleCount <= 10;
    }
};