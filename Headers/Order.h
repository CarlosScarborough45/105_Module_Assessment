#pragma once
#include <string>
#include <vector>

class Orders
{
public:
    static std::string OrderID;
    static std::string TableID;
    double price;
    static std::string Product;
    static std::string people;
    static std::string status;

    static std::vector<Orders> checkOrderFile();
};