#pragma once
#include <string>
#include <vector>

class Orders
{
public:
    std::string OrderID;
    std::string TableID;
    std::string Customer;
    double price;
    std::string Product;
    std::string people;
    std::string status;

    static std::vector<Orders> checkOrderFile();
};