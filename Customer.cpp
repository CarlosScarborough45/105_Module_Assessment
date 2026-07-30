#include "Customer.h"
#include "Users.h"

void customerView() {

    int Customer;
        while (true) {
        std::cout << "Welcome To Customer View\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. Make an Order\n";
        std::cout << "3. Make a Reservation\n";
        std::cout << "4. Return to Menu\n";
        std::cin >> Customer;

        switch (Customer) {
            case 1: {View_Menu();         break;}
            case 2: {Make_Order();        break;}
            case 3: {Make_Reservation();  break;}
            case 4: {main(); break;}
            default:{std::cout << "Enter choice between 1 - 4\n"; break;}
        }
    }
}

void View_Menu() {
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
            case 1: {break;}
            case 2: {break;}
            case 3: {break;}
            case 4: {break;}
            case 5: {break;}
            case 6: {customerView(); break;}
            default: {std::cout << "Must Choose between 1 - 6\n"; break;}
        }
    }
}

void Make_Order() {
    while (true){
    int Order;
    std::cout << "Welcome to Order Menu\n";
    std::cout << "1. Place Order\n";
    std::cout << "2. View Current Order Status\n";
    std::cout << "3. Return Back to Customer View\n";
    std::cin >> Order;
        switch (Order) {
            case 1: {break;}
            case 2: {View_Order_Status(); break;}
            case 3: {customerView(); break;}
            default:{std::cout << "Must Choose between 1 - 3\n"; break;}
        }
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
        case 1: {break;}
        case 2: {customerView(); break;}
        default: {std::cout << "Must Choose between 1 and 2\n"; break;}
    }
}