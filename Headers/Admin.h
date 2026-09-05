#include "Users.h"
#include <iostream>

class Admin : public Users
{
private:
public:
    static void TopBoss();
    static void AccountManagement();
    static void AddStaff();
    static void RemoveStaff();
    static void EditStaff();
    static void RaiseStaff();
};