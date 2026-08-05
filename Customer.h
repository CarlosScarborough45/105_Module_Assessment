#ifndef BACKEND_00P_CUSTOMER_H
#define BACKEND_00P_CUSTOMER_H
#include "Menu.h"
#include "Users.h"

void customerView();
void Make_Order();
void Make_Reservation();
void View_Order_Status();
void Current_Order_Status();

class Customer : public Users {
public:
    static Customer c;
    void rolesdashboard() override {
        customerView();
    }

    std::vector<Menu> check_file_Order() {
        std::vector<Menu> menulists;
        std::fstream file("../Orders.csv");
        std::string line, field;

        while (std::getline(file, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            Menu m{};

            std::getline(ss, m.ITemID, '|');
            std::getline(ss, m.Name, '|');
            std::getline(ss, field, '|');
            try {
                m.price = std::stod(field);
            } catch (const std::invalid_argument&) {
                std::cout << "Skipping bad price field: '" << field << "'" << std::endl;
                continue;
            }
            std::getline(ss, m.category, '|');
            std::getline(ss, m.Status, '|');   // <-- now actually reads Status

            menulists.push_back(m);
        }
        return menulists;
    }
};

#endif //BACKEND_00P_CUSTOMER_H