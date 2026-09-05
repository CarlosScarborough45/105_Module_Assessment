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
    static void selectedprofile();
    static void Loggedprofile();
    static void AllProfile();
    static void StockManage();

public:
    static void ViewStock();
    static void SelectStock();
    static void Refill();

    public:
    static void sales();
    static void selected_sales();
    static void BestSales();
    static void WorstSales();
    static void TableUsage();
};
void Profile();

class Staff : public Users, public Manager{
    private:

    public:
    static void Add_Staff();
    static void Remove_Staff();
    static void Staff_View();
};