#ifndef BACKEND_00P_TABLES_H
#define BACKEND_00P_TABLES_H
#include "Manager.h"


struct Tables {
    int TableID;
    int TableNumber;
    int Capacity;
    std::string Status;
    int CurrentOrderID;
};

void ViewAllTables();
void Available_Table();
void Occupied_Table();
#endif //BACKEND_00P_TABLES_H