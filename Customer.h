#ifndef BACKEND_00P_CUSTOMER_H
#define BACKEND_00P_CUSTOMER_H
#include "Users.h"

class Customer : public Users {
public:
    void rolesdashboard() {
        std::cout << "Welcome to Customer Dashboard" << std::endl;
    }
};

#endif //BACKEND_00P_CUSTOMER_H