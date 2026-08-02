#include "Orders_Sales.h"
#include "sqlite3.h"
#include "Menu.h"
#include "Staff.h"


void Orders() {
    Database_Check();
}

void sales() {
    Database_Check();

}

void AdjustOrders() {

}

void Database_Check() {
    sqlite3 *db;
    int rc = sqlite3_open("Sales_And_Orders", &db);
    if (rc == SQLITE_OK) {
       std::cout << "Database has been created" << std::endl;
    }else{
        std::cout << "Database hasn't been created: " << sqlite3_errmsg(db) << std::endl;
    }
    sqlite3_close(db);
}