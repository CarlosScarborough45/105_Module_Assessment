#ifndef BACKEND_00P_CUSTOMER_H
#define BACKEND_00P_CUSTOMER_H
#include "Users.h"

void customerView();
void Make_Order();
void Make_Reservation();
void View_Order_Status();

class Customer : public Users {
public:
    void rolesdashboard() override {
        customerView();
    }
};

#endif //BACKEND_00P_CUSTOMER_H