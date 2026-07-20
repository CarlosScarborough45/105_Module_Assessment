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
            std::cout << "1. Current Menu Display\n";
            std::cout << "2. View all Tables\n";
            std::cout << "3. Create new orders\n";
            std::cout << "4. View order Status (Pending / InProgress / Ready / Served)\n";
            std::cout << "5. Mark Order as Served\n";
            std::cout << "6. Return to menu\n";
        }
};

class Kitchen : public Staff {
    public:
        void rolesdashboard() override {
            std::cout << "KitchenStaff Display\n";
            std::cout << "1. View Incoming Orders (Pending / InProgress)\n";
            std::cout << "2. Change Status (Pending / In Progress / Ready)\n";
            std::cout << "3. Return to menu\n";
        }
};

class Host : public Staff  {
    public:
            void rolesdashboard() override{
                std::cout << "This is Hosts Display\n";
                std::cout << "1. View live tables (Available / Occupied / Reserved)\n";
                std::cout << "2. Assign Guest to Table\n";
                std::cout << "3. Create / Edit / Cancel reservations\n";
                std::cout << "4. Mark Table as Available\n";
                std::cout << "5. Return to Menu\n";
            }
};







#endif //BACKEND_00P_STAFF_H