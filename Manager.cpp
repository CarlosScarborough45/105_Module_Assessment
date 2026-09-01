#include "Headers/Manager.h"


void Manager::Boss()
{
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            You are Logged in As Manager                 +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";

            int choice;
                while (true){
                std::cout << "+============================================================+\n";
                std::cout << "+                                                            +\n";
                std::cout << "+                                                            +\n";
                std::cout << "+              Welcome to then Manager View                  +\n";
                std::cout << "+                                                            +\n";
                std::cout << "+============================================================+\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+         1. Menu         *       2. Reporting               +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+         3. Table        *       4. OverRides               +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+         5. Logout       *       6. Profile                 +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+============================================================+\n";

                std::cout << "Please Enter your choice\n";
                std::cin >> choice;

                switch (choice){
                    case 1: {Manager::MenuCustomization(); break;}
                    case 2: {Manager::Reports(); break;}
                    case 3: {Manager::Tables(); break;}
                    case 4: {Manager::OverRide(); break;}
                    case 5: {return;}
                    case 6: {break;}
                    default: {std::cout << "Invalid choice\n"; break;}
                }
            }
}

void Manager::MenuCustomization(){

}

void Manager::OverRide(){

}

void Manager::Reports(){

}

void Manager::Tables(){

}