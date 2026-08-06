#include "Customer.h"
#include "Staff.h"

void Current_Menu_Display(){}

void View_All_Tables(){}

void Create_New_Orders(){}

void Orders_Status(){}

void Mark_Order_As_Served() {
    std::cout << "Welcome to Order Status\n";
    std::string Change;
    std::cout << "Enter the OrderID you want to change?" << std::endl;
    std::cin >> Change;



    std::vector<Menu> menu = Customer::check_file_Order();;

    bool found = false;

    int change = -1;
    for (int d = 0; d < menu.size(); d++) {
        if (Change == menu[d].ITemID) {
            change = d;
            found = true;
            std::cout << "Order Id has been found" << std::endl;
            break;
        }
    }
        if (found) {
            std::cout << "Change current Order Status:\n";
            std::cin >> Change;

            if (Change == "Complete") {
                menu[change].Status = "Served";
                std::ofstream file("../Orders.csv", std::ios::trunc);
                for (const auto& order : menu) {
                    file << order.ITemID << "|" << order.Name << "|" << "|" << order.price << "|" << order.category
                    << order.Status << "|" << std::endl;
                }
                file.close();
            std::cout << "[ok] Order has been changed\n";
        } else {
            std::cout << "[X] No Order has been successfully found\n";
        }
    }
}