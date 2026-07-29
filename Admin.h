#ifndef BACKEND_00P_ADMIN_H
#define BACKEND_00P_ADMIN_H
#include "Users.h"
void StaffAccounts();
void Admindisplay();
void MenuControl();
void TableControl();
void Reports();
void AdjustOrders();
void ViewStaff();
void AddStaff();
void EditStaff();
void DeleteStaff();
void ManagerAccount();
void ViewStaffAccounts();

class Admin : public Users {
public:
    void rolesdashboard() {
        std::cout << "Welcome to Admin Dashboard" << std::endl;
        Admindisplay();
    }
};

#endif //BACKEND_00P_ADMIN_H