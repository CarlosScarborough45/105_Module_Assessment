#ifndef BACKEND_00P_MANAGER_H
#define BACKEND_00P_MANAGER_H
#include "Users.h"

void orders();
void menu();
void reports();
void Table();

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
                case 5:{std::cout << "You are Logging out" << std::endl; return;}
                default:{std::cout << "Choose between 1 - 6 thank you"; break;}
            }
        }
    }
};
#endif //BACKEND_00P_MANAGER_H