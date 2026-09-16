#include "Users.h"
#include "Tables.h"
#include <iostream>
#include <iomanip>

class Admin : public Users
{
public:
    static void TopBoss();
    static void AccountManagement();
    static void AddStaff();
    static void RemoveStaff();
    static void EditStaff();
    static void RaiseStaff();

    public:
        static void Sales();
        static void reports();
        static void BestSales();
        static void TotalSales();
        static void WorstSales();
        static void SalesCategory();
        static void TableOccupancy();
        static void OrderCount();
        static void ItemOrder();
};