#ifndef BACKEND_00P_MANAGER_H
#define BACKEND_00P_MANAGER_H
#include "Tables.h"
#include "Users.h"

void orders();
void menu();
void reports();
void Table();

void Total_Revenue();
void Order_Process();
void Most_Order_Item();
void View_All_Total_Order();
void Table_Occupancy();

class Manager : public Users{
public:
    void rolesdashboard() override {
        int choice;
            while (true){
            std::cout << "Welcome to Manager Dashboard" << std::endl;
            std::cout << "1. View all Orders\n";
            std::cout << "2. Menu Customisation\n";
            std::cout << "3. Daily / Weekly Reports\n";
            std::cout << "4. Table Customisation\n";
            std::cout << "5. Back to menu\n";
            std::cin >> choice;

            switch (choice) {
                case 1:{orders(); break;}
                case 2:{menu(); break;}
                case 3:{reports(); break;}
                case 4:{Table(); break;}
                case 5:{std::cout << "You are Logging out" << std::endl; main();}
                default:{std::cout << "Choose between 1 - 6 thank you"; break;}
            }
        }
    }

    static std::vector<Tables> Table_File() {
        std::vector<Tables> tableList;
        std::fstream file("../Table.CSV");
        if (file.is_open()) {
            std::cout << "[ok] file is open and can be used\n";
            std::string line;
            std::stringstream ss;
            Tables t;
            while (std::getline(file, line)) {
                if (line.empty()) continue;
                std::getline(ss, t.TableID, '|');
                std::getline(ss, t.TableName, '|');
                std::getline(ss, t.Capacity, '|');
                std::getline(ss, t.CurrentOrderID, '|');
                std::getline(ss, t.Status, '|');
                std::getline(ss, t.TableNumber, '|');
            }
        }
        else if (!file.is_open()) {
            std::cout << "[X] file is not open\n";
        }
        file.close();
        return tableList;
    }
};
#endif //BACKEND_00P_MANAGER_H