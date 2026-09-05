#include "Headers/Manager.h"
#include "Headers/Menu.h"
#include "./Headers/Tables.h"
#include "./Headers/Order.h"

bool blockAmin(roles role)
{
    return role == roles::Admin;
}

namespace
{
    std::string RoleToString(roles role)
    {
        switch (role)
        {
        case roles::WaitStaff:
            return "WaitStaff";
        case roles::Kitchen:
            return "Kitchen";
        case roles::Manager:
            return "Manager";
        case roles::Admin:
            return "Admin";
        default:
            return "Unknown";
        }
    }
}

void Manager::ViewStock()
{
    std::vector<Menu> menu = Menu::check_Menu();

    std::cout << "+==========================================================+\n";
    std::cout << "+                      View all Stock                      +\n";
    std::cout << "+==========================================================+\n";
    for (const auto &M : menu)
    {
        std::cout << "Name:" << M.Name << "\n"
                  << "ID:" << M.menuID << "\n"
                  << "Price:" << "$"<< M.price << "\n"
                  << "Avalability:" << M.avalability << "\n";
        std::cout << "+==========================================================+\n";
    }
    return;
}

void Manager::SelectStock()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                 View Selected Stock                     +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    std::cout << "Enter the required stock\n";
}

void Manager::Refill()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                    Stock To Refill                      +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";
}

void Manager::StockManage()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+             Welcome to Stock Management                 +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    int Stock;
    std::cout << "+==========================================================+\n";
    std::cout << "+                           *                              +\n";
    std::cout << "+     1. View Stock         *     2. Select Stock          +\n";
    std::cout << "+                           *                              +\n";
    std::cout << "+     3. Refill Stock       *     4. Return to menu        +\n";
    std::cout << "+                           *                              +\n";
    std::cout << "+==========================================================+\n";
    std::cin >> Stock;

    switch (Stock)
    {
    case 1:
    {
        Manager::ViewStock();
        break;
    }
    case 2:
    {
        Manager::SelectStock();
        break;
    }
    case 3:
    {
        Manager::Refill();
        break;
    }
    case 4:
    {
        return;
    }
    }
}

void Manager::AllProfile()
{
    std::vector<Users::UserRecord> users = Users::check_File();
    for (const auto &u : users)
    {
        if (u.role == roles::Admin)
        {
            std::cout << "You Cannot View Admin roles\n";
            continue;
        }
        std::cout << "+=========================================+\n";
        std::cout << "+             Selected User               +\n";
        std::cout << "+=========================================+\n";
        std::cout << "Name:" << u.Name << "\n"
                  << "Email:" << u.Email << "\n"
                  << "Password:" << u.Password << "\n"
                  << "Username:" << u.Username << "\n"
                  << "role:" << RoleToString(u.role) << "\n";
        std::cout << "+=========================================+\n";
    }
}

void Manager::Loggedprofile()
{
}

void Manager::selectedprofile()
{
    std::cout << "Enter the selected profile you want to see\n";

    std::vector<Users::UserRecord> users = Users::check_File();

    std::string person;
    std::cout << "Enter the person\n";
    std::cin >> person;

    for (const auto &u : users)
    {
        if (person == u.Name)
        {
            if (blockAmin(u.role))
            {
                std::cout << "You Cannot View Admin roles\n";
                return;
            }

            std::cout << "+=========================================+\n";
            std::cout << "+             Selected User               +\n";
            std::cout << "+=========================================+\n";
            std::cout << "Selected user has been found\n";
            std::cout << "Name:" << u.Name << "\n"
                      << "Email:" << u.Email << "\n"
                      << "Password:" << u.Password << "\n"
                      << "Username:" << u.Username << "\n"
                      << "role:" << RoleToString(u.role) << "\n";
            std::cout << "+=========================================+\n";
            return;
        }
    }

    std::cout << "cannot find selected user\n";
}

void Profile()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+             Welcome to Profile display                  +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    int profile;

    std::cout << "+==========================================================+\n";
    std::cout << "+                           *                              +\n";
    std::cout << "+ 1. View selected profile  *   2. view all profiles       +\n";
    std::cout << "+                           *                              +\n";
    std::cout << "+ 3. view Logged profile    *   4. Return to menu          +\n";
    std::cout << "+                           *                              +\n";
    std::cout << "+==========================================================+\n";
    std::cin >> profile;

    switch (profile)
    {
    case 1:
    {
        Manager::selectedprofile();
        break;
    }
    case 2:
    {
        Manager::AllProfile();
        break;
    }
    case 3:
    {
        Manager::Loggedprofile();
        break;
    }
    case 4:
    {
        return;
    }
    }
}

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
    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Manager View                   +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Menu         *       2. Reporting               +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3. Table        *       4. OverRides               +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         5. Logout       *       6. Profile                 +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         7. Orders       *       8. StockManagement         +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";

        std::cout << "Please Enter your choice\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Manager::MenuCustomization();
            break;
        }
        case 2:
        {
            Manager::Reports();
            break;
        }
        case 3:
        {
            Manager::Tables();
            break;
        }
        case 4:
        {
            Manager::OverRide();
            break;
        }
        case 5:
        {
            std::cout << "+============================================================+\n";
            std::cout << "+                                                            +\n";
            std::cout << "+                                                            +\n";
            std::cout << "+                 You Are logging out                        +\n";
            std::cout << "+                                                            +\n";
            std::cout << "+============================================================+\n";
            return;
        }
        case 6:
        {
            Profile();
            break;
        }
        case 7:
        {
            Manager::OrderMenu();
            break;
        }
        case 8:
        {
            Manager::StockManage();
            break;
        }
        default:
        {
            std::cout << "Invalid choice\n";
            break;
        }
        }
    }
}

void Manager::MenuCustomization()
{
    std::cout << "+=========================================================+\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+            Welcome to the Menu Manager                  +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+                                                         +\n";
    std::cout << "+=========================================================+\n";

    int choice;

    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Menu View                      +\n";
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

        switch (choice)
        {
        case 1:
        {
            Menu::AddItem();
            break;
        }
        case 2:
        {
            Menu::RemoveItem();
            break;
        }
        case 3:
        {
            Menu::SpecialItem();
            break;
        }
        case 4:
        {
            Menu::EditItem();
            break;
        }
        case 5:
        {
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            you are returning to Menu Display            +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";
            return;
        }
        case 6:
        {
            Menu::ViewItem();
            break;
        }
        }
    }
}

void Manager::OverRide()
{
}

void Manager::sales(){
    std::vector<Menu> menu = Menu::check_Menu();
    std::vector<Orders> orders = Orders::checkOrderFile();
    Menu m;

    std::string choice;

    std::cout << "Which sale you want to enter?\n";
    std::cin >> choice;

    bool found = false;
    if (choice == Orders::TableID){
        found = true;    
    }

    if (!found){
        std::cout << "Cannot find order\n";
        return;
    }

    bool Order = false;
    if (found){
        std::cout << "Table has been found\n";
        std::string ID;
        std::cout << "Enter Order ID\n";
        std::cin >> ID;

        std::cout << "+=================================================================+\n";
        std::cout << "+                         Sale Orders                             +\n";
        std::cout << "+=================================================================+\n";
        if (ID == Orders::OrderID){
            Order = true;
            std::cout << "Order has been found\n";
            for (const auto o : orders){
            std::cout << "ID: "  <<o.OrderID << "\n"
            << "Product: " << o.Product << "\n" << "Price: " << "$"<<m.price << "\n";
        }
        }
        std::cout << "+=================================================================+\n";
    }

    if (!Order){
        std::cout << "Order cannot be found\n";
        return;
    }

}

void Manager::selected_sales(){

}

void Manager::BestSales(){

}

void Manager::WorstSales(){

}

void Manager::TableUsage(){

}

void Manager::Reports()
{
        int choice;
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Report Menu                    +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "1. View All Sales\n";
        std::cout << "2. VIew Selected Total Sales\n";
        std::cout << "3. View Best sales\n";
        std::cout << "4. View Worst sales\n";
        std::cout << "5. View Table usage\n";
        std::cout << "6. Return to menu\n";
        std::cout << "+============================================================+\n";
        std::cout << "Enter the choice\n";
        std::cin >> choice;

        switch(choice){
            case 1: {Manager::sales();              break;}
            case 2: {Manager::selected_sales();     break;}
            case 3: {Manager::BestSales();          break;}
            case 4: {Manager::WorstSales();         break;}
            case 5: {Manager::TableUsage();         break;}
            case 6: { std::cout << "+============================================================+\n";
                      std::cout << "+                                                            +\n";
                      std::cout << "+                                                            +\n";
                      std::cout << "+              Returning to Manager Menu                     +\n";
                      std::cout << "+                                                            +\n";
                      std::cout << "+============================================================+\n";return;}
        }

}

void Manager::OrderMenu()
{
    int Order;
    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Order View                     +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Add Order    *       2. Remove Order            +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3. Edit Order   *       4. Return                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";
        std::cin >> Order;

        switch (Order)
        {
        case 1:
        {
            Manager::AddOrders();
            break;
        }
        case 2:
        {
            Manager::RemoveOrders();
            break;
        }
        case 3:
        {
            Manager::EditOrders();
            break;
        }
        default:
        {
            std::cout << "Must choose between 1 - 4\n";
            return;
        }
        }
    }
}

void Manager::Tables()
{

    int choice;

    while (true)
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Welcome to the Table Menu                     +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         1. Add Table    *       2. Remove Table            +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         3. EditTable    *       4. Return                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+         5. ViewTable    *                                  +\n";
        std::cout << "+                         *                                  +\n";
        std::cout << "+============================================================+\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Tables::AddTable();
            break;
        }
        case 2:
        {
            Tables::RemoveTable();
            break;
        }
        case 3:
        {
            Tables::RemoveTable();
            break;
        }
        case 4:
        {
            std::cout << "+=========================================================+\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+            You are returning to Manager Display         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+                                                         +\n";
            std::cout << "+=========================================================+\n";
            return;
        }
        case 5:
        {
            Tables::ViewTable();
            break;
        }
        }
    }
}