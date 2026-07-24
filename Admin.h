#ifndef BACKEND_00P_ADMIN_H
#define BACKEND_00P_ADMIN_H
#include "Users.h"


class Admin : public Users {
public:
    void rolesdashboard() {
        std::cout << "Welcome to Admin Dashboard" << std::endl;
    }
};

#endif //BACKEND_00P_ADMIN_H