#ifndef BACKEND_00P_ADMIN_H
#define BACKEND_00P_ADMIN_H
#include "Users.h"

void Admindisplay();

class Admin : public Users {
public:
    void rolesdashboard() {
        std::cout << "Welcome to Admin Dashboard" << std::endl;
        Admindisplay();
    }
};

#endif //BACKEND_00P_ADMIN_H