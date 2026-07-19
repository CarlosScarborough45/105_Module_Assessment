#ifndef BACKEND_00P_STAFF_H
#define BACKEND_00P_STAFF_H
#include "Users.h"

class Staff : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Staff Dashboard" << std::endl;
    }
};

#endif //BACKEND_00P_STAFF_H