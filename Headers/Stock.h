#include <string>
#include <iostream>
#include "Order.h"
#include <vector>

class stock
{
public:
    int price;
    inline static int Quantity = 0;
    inline static std::string status; // Available, Out of Stock, Need to Order
    std::string Product;

    static bool CheckStock(int quantity);

    static std::vector<stock> OrderFile();
};

bool stock::CheckStock(int quantity)
{
    if (quantity <= 0)
    {
        stock::status = "Out of Stock";
        return false;
    }
    else if (quantity <= 5)
    {
        stock::status = "Nearly out of stock";
        return false;
    }
    else if (quantity <= 20)
    {
        stock::status = "Available but still low";
        return true;
    }
    
    stock::status = "Available and ready for purchase";
    return true;
};