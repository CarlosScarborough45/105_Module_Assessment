#include "Tables.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include "Manager.h"

void add_Table() {
    std::vector<Tables> b = Manager::Table_File();
    std::vector<Tables> tables;

    std::cout << "\n"
          << std::left << std::setw(10) << "ID"
          << std::setw(15) << "Table Number"
          << std::setw(15) << "Table Name"
          << std::setw(10) << "Capacity"
          << std::setw(15) << "Status" << "\n";
    std::cout << std::string(65, '-') << "\n";

    for (const Tables& t : tables){
        if (t.Status == "Available"){
            std::cout << std::left << std::setw(10) << t.TableID
                      << std::setw(15) << t.TableNumber
                      << std::setw(15) << t.TableName
                      << std::setw(10) << t.Capacity
                      << std::setw(15) << t.Status << "\n";
        }
    }
    std::cout << std::string(65, '-') << std::endl;

    Tables t;

    std::cout << "Enter Table ID\n";
    std::cin >> t.TableID;


    std::cout << "Enter TableNumber" << std::endl;
    std::cin >> t.TableNumber;


    std::cout << "Enter TableName" << std::endl;
    std::cin >> t.TableName;


    std::cout << "Enter Capacity\n";
    std::cin >> t.Capacity;


    std::cout << "Enter Status\n";
    std::cin >> t.Status;

    tables.push_back(t);

    std::ofstream outfile("../Table.CSV", std::ios::app);

    outfile << t.TableID << '|' << t.TableNumber << '|' << t.TableName << '|' << t.Capacity << '|' << t.Status;

    outfile.close();

    std::cout << "New Table has been entered Safely" << std::endl;
}

void Available_Table() {
    std::fstream file ("../Table.CSV");
    if (!file) {
        std::cout << "[X] File has not been created" << std::endl;
        return;
    }
    std::cout << "File is already been created" << std::endl;
    std::string line, field;

    std::vector<Tables> tables;

    std::getline(file, line); // skip header row

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss (line);
        Tables t;

        std::getline(ss, field, '|');
        t.TableID = std::stoi(field);

        std::getline(ss, t.TableNumber, '|');

        std::getline(ss, t.TableName, '|');

        std::getline(ss, field, '|');
        t.Capacity = std::stoi(field);

        std::getline(ss, t.Status, '|');

        std::getline(ss, field, '|');
        t.CurrentOrderID = std::stoi(field);

        tables.push_back(t);
    }
    std::cout << "\n"
              << std::left << std::setw(10) << "ID"
              << std::setw(15) << "Table Number"
              << std::setw(15) << "Table Name"
              << std::setw(10) << "Capacity"
              << std::setw(15) << "Status" << "\n";
    std::cout << std::string(65, '-') << "\n";

    for (const Tables& t : tables){
        if (t.Status == "Available"){
            std::cout << std::left << std::setw(10) << t.TableID
                      << std::setw(15) << t.TableNumber
                      << std::setw(15) << t.TableName
                      << std::setw(10) << t.Capacity
                      << std::setw(15) << t.Status << "\n";
        }
    }
    Tablestatus();
    std::cout << std::string(65, '-') << std::endl;
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

    std::getline(file, line); // skip header row

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss (line);
        Tables t;

        std::getline(ss, field, '|');
        t.TableID = std::stoi(field);

        std::getline(ss, t.TableNumber, '|');

        std::getline(ss, t.TableName, '|');

        std::getline(ss, field, '|');
        t.Capacity = std::stoi(field);

        std::getline(ss, t.Status, '|');

        std::getline(ss, field, '|');
        t.CurrentOrderID = std::stoi(field);

        tables.push_back(t);
    }
    std::cout << "\n"
              << std::left << std::setw(10) << "ID"
              << std::setw(15) << "Table Number"
              << std::setw(15) << "Table Name"
              << std::setw(10) << "Capacity"
              << std::setw(15) << "Status" << "\n";
    std::cout << std::string(65, '-') << "\n";

    for (const Tables& t : tables){
        if (t.Status == "Occupied"){
            std::cout << std::left << std::setw(10) << t.TableID
                      << std::setw(15) << t.TableNumber
                      << std::setw(15) << t.TableName
                      << std::setw(10) << t.Capacity
                      << std::setw(15) << t.Status << "\n";
        }
    }
    Tablestatus();
    std::cout << std::string(65, '-') << std::endl;
}

void Tablestatus() {
    std::fstream file("../Table.CSV");
        if (!file) {
            std::cout << "[X] File has not been created" << std::endl;
            return;
        }
        std::cout << "File is already been created" << std::endl;
        std::string line, field;

        std::vector<Tables> tables;

        std::getline(file, line); // skip header row

        while (std::getline(file, line)) {
            if (line.empty()) continue;

            std::stringstream ss (line);
            Tables t;

            std::getline(ss, field, '|');
            t.TableID = std::stoi(field);

            std::getline(ss, t.TableNumber, '|');

            std::getline(ss, t.TableName, '|');

            std::getline(ss, field, '|');
            t.Capacity = std::stoi(field);

            std::getline(ss, t.Status, '|');

            std::getline(ss, field, '|');
            t.CurrentOrderID = std::stoi(field);

            tables.push_back(t);
    }
    int occupiedCount = 0;
    int AvailableCount = 0;
    for (const Tables& t : tables) {
        if (t.Status == "Available") {
            AvailableCount++;
        }
    }
    if (AvailableCount == 0) {
        std::cout << "There are no Available Table, must clear tables to be Available" << std::endl;
    }
    for (const Tables& t : tables) {
        if (t.Status == "Occupied") {
            occupiedCount++;
        }
    }

    if (occupiedCount == 0) {
        std::cout << "There are no Occupied Tables, All Waiting to be filled" << std::endl;
    }
}

void ViewAllTables() {
        std::vector<Tables> tables;

        for (int i = 1; i <= 8; i++) {
            Tables t;
            t.TableID = i;
            t.TableNumber = "Table " + std::to_string(i);
            t.TableName = "Table " + std::to_string(i);   // now actually set
            t.Capacity = 4;
            t.Status = "Available";
            t.CurrentOrderID = -1;
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

        file << "Table ID|Table Number|Table Name|Capacity|Status|CurrentOrderID" << std::endl;

        for (const Tables& t : tables) {
            file << t.TableID << "|" << t.TableNumber << "|" << t.TableName << "|"
                 << t.Capacity << "|" << t.Status << "|" << t.CurrentOrderID << std::endl;
        }
        file.close();
    }