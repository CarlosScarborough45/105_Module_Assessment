#ifndef BACKEND_00P_TABLES_H
#define BACKEND_00P_TABLES_H
#include "Manager.h"


struct Tables {
    int TableID;
    std::string TableNumber;
    std::string TableName;
    int Capacity;
    std::string Status;
    int CurrentOrderID;
};

void ViewAllTables();
void Available_Table();
void Occupied_Table();
void add_Table();
void Tablestatus();
#endif //BACKEND_00P_TABLES_H