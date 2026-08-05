#include "Customer.h"
#include "Users.h"
#include "Menu.h"
#include "Staff.h"

Customer Customer::c;

void customerView() {
        int Customer;
        while (true) {
        std::cout << "Welcome To Customer View\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. Make an Order\n";
        std::cout << "3. Make a Reservation\n";
        std::cout << "4. Check Order Status\n";
        std::cout << "5. Return to Menu\n";
        std::cin >> Customer;

        switch (Customer) {
            case 1: {Menulist::ml.View_Menu();  break;}
            case 2: {Make_Order();        break;}
            case 3: {Make_Reservation();  break;}
            case 4: {View_Order_Status(); break;}
            case 5: {main(); break;}
            default:{std::cout << "Enter choice between 1 - 4\n"; break;}
        }
    }
}

void Menulist::View_Menu() {
    int Menu;
    while (true){
    std::cout << "Welcome to Menu option\n";
    std::cout << "1. View all Menu\n";
    std::cout << "2. View Specials\n";
    std::cout << "3. View Lunch\n";
    std::cout << "4. View Dinner\n";
    std::cout << "5. View Dessert\n";
    std::cout << "6. Back to Customer View\n";
    std::cin >> Menu;

        switch (Menu) {
            case 1: {ml.load_Menu();  break;}
            case 2: {ml.View_Specials(); break;}
            case 3: {ml.View_Lunch();    break;}
            case 4: {ml.View_Dinner();   break;}
            case 5: {ml.View_Desserts(); break;}
            case 6: {customerView();  break;}
            default: {std::cout << "Must Choose between 1 - 6\n"; break;}
        }
    }
}


void Make_Order() {
    std::string Order;
    std::cout << "Enter your Order ID: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, Order);

    bool found = false;

    for (auto item : Menulist::ml.menulist) {
        if (item.ITemID == Order) {
            std::cout << "Id is " << item.ITemID
                       << "\nName is " << item.Name
                       << "\nPrice is $" << item.price
                       << "\nCategory is " << item.category << std::endl;
            found = true;

            std::cout << "Enter status Order: ";
            std::cin >> item.Status;

            std::ofstream file("../Orders.csv", std::ios::app);
            file << item.ITemID << "|" << item.Name << "|" << item.price << "|"
                 << item.category << "|" << item.Status << std::endl;
            file.close();
            break;
        }
    }
    if (!found) {
        std::cout << "Id is currently not in Menu" << std::endl;
    }
}

void Make_Reservation() {
    std::cout << "Welcome to Reservation menu\n";
}

void View_Order_Status() {
    int Order_Status;
    std::cout << "Welcome to Order Status menu\n";
    std::cout << "1. View Current Order Status\n";
    std::cout << "2. Return to menu\n";
    std::cin >> Order_Status;

    switch (Order_Status) {
        case 1: {Current_Order_Status(); break;}
        case 2: {customerView(); break;}
        default: {std::cout << "Must Choose between 1 and 2\n"; break;}
    }
}

void Current_Order_Status() {
    std::vector<Menu> customer = Customer::c.check_file_Order();

    std::string Order;
    std::cout << "Enter Order ID: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, Order);

    bool found = false;

    for (const auto& Itemid : customer) {   // <-- search the loaded orders, not the menu
        if (Itemid.ITemID == Order) {
            std::cout << "Id: " << Itemid.ITemID
                       << "\nName: " << Itemid.Name
                       << "\nStatus: " << Itemid.Status << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Order Cannot be found in database" << std::endl;
    }
}