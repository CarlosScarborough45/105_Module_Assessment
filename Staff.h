#ifndef BACKEND_00P_STAFF_H
#define BACKEND_00P_STAFF_H
#include "Users.h"
#include <fstream>

class Staff : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Staff Dashboard" << std::endl;

    }
};

class WaitStaff : public Staff {
    public:
        void rolesdashboard() override {
            std::cout << "WaitStaff Display\n";

        }
};

class Kitchen : public Staff {
    public:
        void rolesdashboard() override {
            std::cout << "KitchenStaff Display\n";

        }
};

class Host : public Staff  {
    public:
            void rolesdashboard() override{
                std::cout << "This is Hosts Display\n";

            }
};







#endif //BACKEND_00P_STAFF_H