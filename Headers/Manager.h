#pragma once
#include "Users.h"
#include <iostream>

class Manager : public Users
{

public:
    void Boss();
    void MenuCustomization();
    void Reports();
    void Tables();
    void OverRide();

    static void OrderMenu();
    static void EditOrders();
    static void AddOrders();
    static void RemoveOrders();
};