#pragma once
#include <string>
#include <vector>

class Orders
{
public:
    std::string OrderID;
    std::string TableID;
    double price = 0.0;
    std::string Product;
    std::string people;
    std::string status;

    static std::vector<Orders> checkOrderFile();
};