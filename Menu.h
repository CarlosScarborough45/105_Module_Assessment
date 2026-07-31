#ifndef BACKEND_00P_MENU_H
#define BACKEND_00P_MENU_H
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


class Menu {
    public:
    std::string ITemID;
    std::string Name;
    std::string category;
    double price = 0;
    bool available = false;

        Menu(std::string id, std::string name, std::string cat, double p, bool avail)
            : ITemID(std::move(id)), Name(std::move(name)), category(std::move(cat)),
            price(p), available(avail) {}


    std::string getId() const {return ITemID;}
    std::string getName() const {return Name;}
    std::string getCategory() const {return category;}
    double getPrice() const {return price;}
    bool getAvailable() const {return available;}

};

class Menulist : public Menu{
public:
    std::vector<Menu> menulist = {
        Menu {"001", "Padthai", "Lunch", 15.00, true},
            {"002", "Crispy Shrimp Roll", "Appetizers", 12.50, true},
            {"003", "Onsen Prawn Dumpling", "Appetizers", 12.50, true},
              {"004", "Fish Maw soup", "Desserts", 25, true},
              {"005", "Pork Dumpling", "Desserts", 25, true},
              {"006", "Claypot Chicken", "Lunch", 25, true},
              {"007", "Sweet and Sour Fish", "Lunch", 25, true},
    };

    void load_Menu();
    void View_Specials();
    void View_Desserts();
    void View_Dinner();
    void View_Lunch();

    void View_Menu();

    static Menulist ml;
};

inline void Menulist::load_Menu() {
       std::cout << std::string (60, '-') << "\n";
        std::cout << "\n"
        <<std::left << std::setw(10)
        << "Name" << std::setw(10) << "Price" << "Category" << std::endl;
        std::cout << std::string (60, '-') << "\n";
        for (const auto& item : menulist) {
            std::cout << std::left << std::setw(20) << item.getName() << " | " << " $" << item.getPrice() << " | " << item.getCategory() << std::endl;
        }
       std::cout << std::string (60, '-') << "\n";
    }

inline void Menulist::View_Specials() {

}

inline void Menulist::View_Desserts() {
    std::cout << std::string (60, '-') << "\n";
    std::cout << "\n" << std::left << std::setw(20) << "Name" << "|" << std::setw(20) << "Price"
    << std::setw(20) << "Category" << "|" << std::endl;
    std::cout << std::string (60, '-') << "\n";

        for (const auto& m : ml.menulist) {
            if (m.category == "Desserts"){
            std::cout << std::left << std::setw(20) << m.getName() << " | " << " $" << m.getPrice() << " | " << m.getCategory() << std::endl;
        }
            else {
                std::cout << "No Desserts has been Created\n";
            }
    }
    std::cout << std::string (60, '-') << "\n";
}

inline void Menulist::View_Dinner() {

    std::cout << std::string (60, '-') << "\n";
    std::cout << "\n" << std::left << std::setw(20) << "Name" << "|" << std::setw(20) << "Price"
    << std::setw(20) << "Category" << "|" << std::endl;

    for (const auto& m : ml.menulist) {
        if (m.category == "Dinner"){
            std::cout << std::left << std::setw(20) << m.getName() << " | " << " $" << m.getPrice() << " | " << m.getCategory() << std::endl;
        }
        else {
            std::cout << "No Dinner has been Created\n";
        }
    }

    std::cout << std::string (60, '-') << "\n";
}

inline void Menulist::View_Lunch() {

    std::cout << std::string (60, '-') << "\n";
    std::cout << "\n" << std::left << std::setw(20) << "Name" << "|" << std::setw(20) << "Price"
    << std::setw(20) << "Category" << "|" << std::endl;

    for (const auto& m : ml.menulist) {
        if (m.category == "Lunch"){
            std::cout << std::left << std::setw(20) << m.getName() << " | " << " $" << m.getPrice() << " | " << m.getCategory() << std::endl;
        }
        else {
            std::cout << "No Lunch has been Created\n";
        }
    }
    std::cout << std::string (60, '-') << "\n";
}
#endif //BACKEND_00P_MENU_H