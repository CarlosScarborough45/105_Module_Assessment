#ifndef INC_105MODULE_ORDERS_H
#define INC_105MODULE_ORDERS_H
#include <string>

class Order {
    public:
        std::string orderID;
        std::string TableNumber;
        std::string Items;
        std::string Price;
        std::string Status;
        std::string Time;
};

void place_new_orders();
void order_Menu();

#endif //INC_105MODULE_ORDERS_H