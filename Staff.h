#ifndef BACKEND_00P_STAFF_H
#define BACKEND_00P_STAFF_H
#include "Tables.h"
#include "Users.h"
#include <fstream>
#include <vector>
#include <iomanip>

void LoadTables();
void Order_Status();
void Orders();
void Menu_Display();
void View_Tables();

class Staff : public Users {
public:
    void rolesdashboard() override {
        std::cout << "Welcome to Staff Dashboard" << std::endl;

    }
};

class WaitStaff : public Staff {
    public:
        void rolesdashboard() override {
            int wait;
                while (true){
                std::cout << "WaitStaff Display\n";
                std::cout << "1. Current Menu Display\n";
                std::cout << "2. View all Tables\n";
                std::cout << "3. Create new orders\n";
                std::cout << "4. View order Status (Pending / InProgress / Ready / Served)\n";
                std::cout << "5. Mark Order as Served\n";
                std::cout << "6. Return to menu\n";
                std::cin >> wait;

                switch (wait) {
                    case 1:{break;}
                    case 2:{break;}
                    case 3:{break;}
                    case 4:{break;}
                    case 5:{break;}
                    case 6:{return;}
                    default:{std::cout << "Must chose between 1 - 6" << std::endl;}
                }
            }
        }
};

class Kitchen : public Staff {
    public:
        void rolesdashboard() override {
            int Option;
            while (true){
            std::cout << "KitchenStaff Display\n";
            std::cout << "1. View Incoming Orders (Pending / InProgress)\n";
            std::cout << "2. Change Status (Pending / In Progress / Ready)\n";
            std::cout << "3. Return to menu\n";
            std::cin >> Option;

            switch (Option) {
                case 1:{Orders();       break;}
                case 2:{Order_Status(); break;}
                case 3:{return;}
                default: {std::cout << "Must Choose between 1 - 3" << std::endl;}
            }
            }
        }
};

class Host : public Staff  {
    public:
    std::vector<Tables> tables;
    std::string filepath = "../Table.csv";
    void Assign();
    void SaveTables();

    void LoadTables() {
        tables.clear();
        std::ifstream in(filepath);
        if (!in.is_open()) {
            std::cout << "Could not open file: " << filepath << "\n";
            return;
        }

        std::string line;
        int lineNum = 0;

        while (std::getline(in, line)) {
            lineNum++;
            if (line.empty()) continue;

            std::stringstream ss(line);
            std::string field;
            std::vector<std::string> fields;

            while (std::getline(ss, field, '|')) {
                fields.push_back(field);
            }

            if (fields.size() < 5) {
                std::cout << "Line " << lineNum << " has too few fields, skipping: [" << line << "]\n";
                continue;
            }

            Tables t;
            try {
                t.TableID        = std::stoi(fields[0]);
                t.TableNumber    = fields[1];               // string, not stoi
                t.TableName      = fields[2];
                t.Capacity       = std::stoi(fields[3]);
                t.Status         = fields[4];
                t.CurrentOrderID = (fields.size() >= 6) ? std::stoi(fields[5]) : -1; // default if missing
            } catch (const std::exception& e) {
                std::cout << "Line " << lineNum << " bad data, skipping: [" << line << "] (" << e.what() << ")\n";
                continue;
            }

            tables.push_back(t);
        }
    }

    void View_Tables() {
        LoadTables();
        for (const Tables& t : tables) {
            if (t.Status == "Available") {
                std::cout << std::left << std::setw(20) << t.TableID
                                       <<std::setw(20) << t.TableNumber
                                       <<std::setw(20) << t.TableName
                                       <<std::setw(20) << t.Capacity
                                       <<std::setw(20) << t.Status << "\n";
            }
        }

        for (const Tables& t : tables) {
            if (t.Status == "Occupied") {
                std::cout << std::left << std::setw(20) << t.TableID
                                       << std::setw(20) << t.TableNumber
                                       << std::setw(20) << t.TableName
                                       << std::setw(20) << t.Capacity
                                       << std::setw(20) << t.Status << "\n";
            }
        }
    }

            void rolesdashboard() override{
                int Host;
                    while (true){
                    std::cout << "This is Hosts Display\n";
                    std::cout << "1. View live tables (Available / Occupied / Reserved)\n";
                    std::cout << "2. Assign Guest to Table\n";
                    std::cout << "3. Create / Edit / Cancel reservations\n";
                    std::cout << "4. Mark Table as Available\n";
                    std::cout << "5. Return to Menu\n";
                    std::cin >> Host;
                        switch (Host) {
                            case 1:{View_Tables(); break;}
                            case 2:{Assign(); break;}
                            case 3:{break;}
                            case 4:{break;}
                            case 5:{return;}
                            default:{std::cout << "Must choose between 1 - 5" << std::endl;}
                        }

                }
            }
};







#endif //BACKEND_00P_STAFF_H