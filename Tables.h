#ifndef BACKEND_00P_TABLES_H
#define BACKEND_00P_TABLES_H
#include <string>

struct Tables {
    std::string TableID;
    std::string TableNumber;
    std::string TableName;
    std::string Capacity;
    std::string Status;
    std::string CurrentOrderID;
};

void ViewAllTables();
void Available_Table();
void Occupied_Table();
void add_Table();
void Tablestatus();
#endif //BACKEND_00P_TABLES_H