#include "Headers/Manager.h"
#include "Headers/Menu.h"


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
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            Welcome to the Menu Manager                  +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";

            int choice;

            while (true){
                std::cout << "+============================================================+\n";
                std::cout << "+                                                            +\n";
                std::cout << "+                                                            +\n";
                std::cout << "+              Welcome to then Menu View                     +\n";
                std::cout << "+                                                            +\n";
                std::cout << "+============================================================+\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+         1. Add Item     *       2. Remove Item             +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+         3 Special       *       4. Edit Item               +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+         5. Return       *       6.  View Menu              +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+                         *                                  +\n";
                std::cout << "+============================================================+\n";
                std::cin >> choice;

                switch (choice) {
                    case 1: {Menu::AddItem();         break;}
                    case 2: {Menu::RemoveItem();      break;}
                    case 3: {Menu::SpecialItem();     break;}
                    case 4: {Menu::EditItem();        break;}
                    case 5: {          std::cout << "+=========================================================+\n";
                                       std::cout << "+                                                         +\n";
                                       std::cout << "+                                                         +\n";
                                       std::cout << "+            you are returning to Menu Display            +\n";
                                       std::cout << "+                                                         +\n";
                                       std::cout << "+                                                         +\n";
                                       std::cout << "+=========================================================+\n";
                                        return;
                                    }
                    case 6: {Menu::ViewItem();       break;}                
                
                }

                }
}



void Manager::OverRide(){

}

void Manager::Reports(){

}

void Manager::Tables(){

}