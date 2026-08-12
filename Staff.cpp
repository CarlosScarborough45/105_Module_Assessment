#include "Staff.h"
#include <iomanip>
#include <vector>
#include "Tables.h"
#include <fstream>


void Order_Status() {


}

void Menu_Display() {

}

void Host::Assign() {
    LoadTables();

    int ID;
    std::cout << "Enter Table ID: \n";
    std::cin >> ID;

    bool found = false;
    for (auto& t : tables) {
        if (ID == t.TableID) {
            if (t.Status == "Occupied") {
                std::cout << "Table " << ID << " is already Occupied.\n";
                return;
            }
            t.Status = "Occupied";
            found = true;
            break;
        }
    }

    if (found) {
        SaveTables();
        std::cout << "Table " << ID << " marked as Occupied.\n";
    } else {
        std::cout << "No table found with ID " << ID << "\n";
    }
}

void Host::Available_Tables() {
    LoadTables();
    int ID;
    std::cout << "Enter Table ID: \n";
    std::cin >> ID;

    bool found = false;
    for (auto& t : tables) {
        if (ID == t.TableID) {
            if (t.Status == "Available") {
                std::cout << "Table " << ID << " is already Available.\n";
                return;
            }
            t.Status = "Available";
            found = true;
            break;
        }
    }

    if (found) {
        SaveTables();
        std::cout << "Table " << ID << " marked as Available.\n";
    } else {
        std::cout << "No table found with ID " << ID << "\n";
    }
}

void Host::SaveTables() {
    std::ofstream out(filepath);
    if (!out.is_open()) {
        std::cout << "Could not write to file: " << filepath << "\n";
        return;
    }
    for (const auto& t : tables) {
        out << t.TableID << "|" << t.TableNumber << "|" << t.TableName << "|"
            << t.Capacity << "|" << t.Status << "|" << t.CurrentOrderID << "\n";
    }
}