#include "Tables.h"
#include <vector>
#include <iomanip>

void Available_Table() {
    std::fstream file ("../Table.CSV");
    if (!file) {
        std::cout << "[X] File has not been created" << std::endl;
        return;
    }
    std::cout << "File is already been created" << std::endl;
    std::string line, field;

    std::vector<Tables> tables;

    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss (line);
        Tables t;   // moved inside loop, one per row

        std::getline(ss, field, '|');
        t.TableID = std::stoi(field);

        std::getline(ss, field, '|');
        t.TableNumber = std::stoi(field);

        std::getline(ss, field, '|');
        t.Capacity = std::stoi(field);

        std::getline(ss, t.Status, '|');

        std::getline(ss, field, '|');
        t.CurrentOrderID = std::stoi(field);

        tables.push_back(t);
    }
    for (const Tables& t : tables){
        if (t.Status == "Available"){
            std::cout << std::left << std::setw(20) << t.TableID
                      << std::setw(20) << t.TableNumber
                      << std::setw(20) << t.Status << std::endl;
        }
    }
}

void Occupied_Table() {
    std::fstream file ("../Table.CSV");
    if (!file) {
        std::cout << "[X] File has not been created" << std::endl;
        return;
    }
    std::cout << "File is already been created" << std::endl;
    std::string line, field;

    std::vector<Tables> tables;

    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss (line);
        Tables t;   // moved inside loop, one per row

        std::getline(ss, field, '|');
        t.TableID = std::stoi(field);

        std::getline(ss, field, '|');
        t.TableNumber = std::stoi(field);

        std::getline(ss, field, '|');
        t.Capacity = std::stoi(field);

        std::getline(ss, t.Status, '|');

        std::getline(ss, field, '|');
        t.CurrentOrderID = std::stoi(field);

        tables.push_back(t);
    }
    for (const Tables& t : tables){
        if (t.Status == "Occupied"){
            std::cout << std::left << std::setw(20) << t.TableID
                      << std::setw(20) << t.TableNumber
                      << std::setw(20) << t.Status << std::endl;
        }
    }
    std::cout << "Tables are all available\n";
}


void ViewAllTables() {
    std::vector<Tables> tables;

    for (int i = 1; i <= 8; i++) {
        Tables t;
        t.TableID = i;
        t.TableNumber = i;
        t.Capacity = 4;
        t.Status = "Available";
        t.CurrentOrderID = -i;
        tables.push_back(t);
    }

    std::cout << "+=========================================+\n";
    std::cout << "|                     |                 \n|";
    std::cout << "|     1. Table 1      |       2. Table 2\n|";
    std::cout << "|     Available       |        Available\n|";
    std::cout << "|                     |                 \n|";
    std::cout << "|     3. Table 3      |       4. Table 4\n|";
    std::cout << "|     Available       |        Available\n|";
    std::cout << "|                     |                 \n|";
    std::cout << "|     5. Table 5      |       6. Table 6\n|";
    std::cout << "|     Available       |        Available\n|";
    std::cout << "|                     |                 \n|";
    std::cout << "|     7. Table 7      |       8. Table 8\n|";
    std::cout << "|     Available       |        Available\n|";
    std::cout << "|                     |                 \n|";
    std::cout << "+=========================================+\n";

    std::cout << "Welcome this is all tables\n";
    std::ofstream file ("../Table.csv");
    if (!file) {
        std::cout << "[X] File is not available must be created" << std::endl;
        return;
    }
    std::cout << "[ok] File have been available or created" << std::endl;

    file << "Table ID|Table Number|Capacity|Status|CurrentOrderID" << std::endl;

    for (const Tables& t : tables) {
        file << t.TableID << "|" << t.TableNumber << "|" << t.Capacity << "|"
             << t.Status << "|" << t.CurrentOrderID << "|" << std::endl;
    }
    file.close();
}