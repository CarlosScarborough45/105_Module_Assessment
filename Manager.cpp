#include "Headers/Manager.h"
#include "Headers/Menu.h"
#include "./Headers/Tables.h"
#include "./Headers/Order.h"
#include "Headers/Stock.h"
#include "Headers/Sales.h"
#include <cctype>
#include <fstream>
#include <iomanip>
#include <limits>

bool blockAmin(roles role)
{
    return role == roles::Admin;
}

namespace role
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

    std::cout << "\nAll Stock\n";
    for (const auto &M : menu)
    {
        bool available = stock::CheckStock(M.Quantity);
        std::cout << "Name:" << M.Name << "\n"
                  << "ID:" << M.menuID << "\n"
                  << "Price:" << "$" << M.price << "\n"
                  << "Quantity: " << stock::CheckStock(M.Quantity) << "\n"
                  << "Availability: " << stock::status << "\n";
    }
    return;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Manager::SelectStock()
{
    std::cout << "+============================================+\n";
    std::cout << "+             Selected Stock                 +\n";
    std::cout << "+============================================+\n";

    std::string stock;
    std::cout << "+============================================+\n";
    std::cout << "+           Enter the required stock         +\n";
    std::cout << "+============================================+\n";
    std::cin >> stock;

    std::vector<Menu> menu = Menu::check_Menu();

    bool found = false;
    std::cout << "+============================================+\n";
    std::cout << "+             Stock Details                  +\n";
    std::cout << "+============================================+\n";
    for (const auto &M : menu)
    {
        if (stock == M.Name)
        {
            std::cout << "+============================================+\n";
            std::cout << "+             Stock has been found           +\n";
            std::cout << "+============================================+\n";
            found = true;
            std::cout << "Name:" << M.Name << "\n"
                      << "ID:" << M.menuID << "\n"
                      << "Price:" << "$" << M.price << "\n"
                      << "Quantity: " << stock::CheckStock(M.Quantity) << "\n"
                      << "Avalability:" << M.avalability << "\n";
        }
    }
    std::cout << "+====================================================+\n";
    if (!found)
    {
        std::cout << "+============================================+\n";
        std::cout << "+             Stock not found                +\n";
        std::cout << "+============================================+\n";
        return;
    }
}

void Manager::Refill()
{
    std::cout << "+============================================+\n";
    std::cout << "+         Welcome to Stock Refill            +\n";
    std::cout << "+============================================+\n";

    std::vector<Menu> menus = Menu::check_Menu();

    std::string Stock;

    std::cout << "+============================================+\n";
    std::cout << "+     Enter What Stock you want to Refill    +\n";
    std::cout << "+============================================+\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, Stock);

    bool found = false;
    int index = -1;
    for (int i = 0; i < menus.size(); i++)
    {
        if (Stock == menus[i].Name)
        {
            found = true;
            index = i;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Cannot find current Stock\n";
        return;
    }

    std::cout << "Current Stock Found\n";
    std::cout << "+============================================+\n";
    std::cout << "+             Chosen Stock Avalibility       +\n";
    std::cout << "+============================================+\n";
    std::cout << "ID: " << menus[index].menuID << "\n"
              << "Name: " << menus[index].Name << "\n"
              << "Price: " << "$" << menus[index].price << "\n"
              << "Available Stock: " << menus[index].Quantity << std::endl;

    std::cout << "+============================================+\n";
    std::cout << "+     How much stock do you want to Refil    +\n";
    std::cout << "+============================================+\n";

    int Amount = 0;
    std::cin >> Amount;

    if (Amount >= menus[index].Quantity) {
        std::cout << "Stock is a level cannot refile any more\n";
        return;
    }

    menus[index].Quantity += Amount;

    Menu::save_Menu(menus);

    std::cout << menus[index].Name << " restocked to "
              << menus[index].Quantity << " Changes Status "
              << menus[index].avalability << "\n";
}

void Manager::StockManage()
{
    std::cout << "\nStock Management\n";

    int Stock;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Stock Options\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "[1] View Stock\n";
    std::cout << "[2] Select Stock\n";
    std::cout << "[3] Refill Stock\n";
    std::cout << "[4] Return to menu\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter your choice\n";
    std::cin >> Stock;

    switch (Stock)
    {
    case 1:
    {
        ViewStock();
        break;
    }
    case 2:
    {
        SelectStock();
        break;
    }
    case 3:
    {
        Refill();
        break;
    }
    case 4:
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Return to Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
        default: ;
    }
}

void Manager::AllProfile()
{
    std::vector<UserRecord> users = check_File();
    for (const auto &u : users)
    {
        if (u.role == roles::Admin)
        {
            std::cout << "You Cannot View Admin roles\n";
            continue;
        }
        std::cout << "\nSelected User\n";
        std::cout << "Name:" << u.Name << "\n"
                  << "Email:" << u.Email << "\n"
                  << "Password:" << u.Password << "\n"
                  << "Username:" << u.Username << "\n"
                  << "role:" << role::RoleToString(u.role) << "\n";
    }
}

void Manager::selectedprofile()
{
    std::cout << "Enter the selected profile you want to see\n";

    std::vector<UserRecord> users = check_File();

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

            std::cout << "\nSelected User\n";
            std::cout << "Selected user has been found\n";
            std::cout << "Name:" << u.Name << "\n"
                      << "Email:" << u.Email << "\n"
                      << "Password:" << u.Password << "\n"
                      << "Username:" << u.Username << "\n"
                      << "role:" << role::RoleToString(u.role) << "\n";
            return;
        }
    }

    std::cout << "cannot find selected user\n";
}

void Profile()
{
    std::cout << "\nProfiles\n";

    int profile;

    std::cout << "\n--- Profile Options ---\n";
    std::cout << "[1] View selected profile\n";
    std::cout << "[2] View all profiles\n";
    std::cout << "[3] Return to menu\n";
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
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Returning to Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        Manager::Boss();
    }
        default: std::cout << "+" << std::string(60, '=') << "+" << "\n";
                 std::cout << "Must Choose between 1 - 4\n";
                 std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
}

void Manager::Boss()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "You are Logged in As Manager\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    int choice;
    while (true)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Manager Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "[1] Menu\n";
        std::cout << "[2] Reporting\n";
        std::cout << "[3] Table\n";
        std::cout << "[4] Overrides\n";
        std::cout << "[5] Logout\n";
        std::cout << "[6] Profile\n";
        std::cout << "[7] Orders\n";
        std::cout << "[8] Stock Management\n";
        std::cout << "[9] Staff\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Please Enter your choice\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            MenuCustomization();
            break;
        }
        case 2:
        {
            Reports();
            break;
        }
        case 3:
        {
            Tables();
            break;
        }
        case 4:
        {
            OverRide();
            break;
        }
        case 5:
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "You Are logging out\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return;
        }
        case 6:
        {
            Profile();
            break;
        }
        case 7:
        {
            OrderMenu();
            break;
        }
        case 8:
        {
            StockManage();
            break;
        }
        case 9:
        {
            Staff::Staff_View();
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

void Staff::Staff_View()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Eats and Treats Hiring Page\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    int Staff;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "[1] Add Staff\n";
    std::cout << "[2] Remove Staff\n";
    std::cout << "[3] Return to Manager View\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Enter a choice: \n";
    std::cin >> Staff;

    switch (Staff)
    {
    case 1:
    {
        Add_Staff();
        break;
    }
    case 2:
    {
        Remove_Staff();
        break;
    }
    case 3:
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "You are Returning back to Manager view no more Hires\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }
    default:
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Must Make a choice between 1 - 3\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }
    }
}

void Staff::Add_Staff()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Add Staff Display\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    UserRecord u;

    std::cout << "Enter your name\n";
    std::cin >> u.Name;

    std::cout << "Enter your Email\n";
    std::cin >> u.Email;

    std::cout << "Enter your Password\n";
    std::cin >> u.Password;

    std::cout << "Enter your Username\n";
    std::cin >> u.Username;

    std::string roleinput;
    std::cout << "Enter your Role (Kitchen, Waitstaff)\n";
    std::cin >> roleinput;

    if (roleinput == "Manager" || roleinput == "Admin" || roleinput == "manager" || roleinput == "admin")
    {
        std::cout << std::string(50, '=') << "\n";
        std::cout << "Cannot Hire Manager or Admin\n";
        std::cout << std::string(50, '=') << "\n";
    }

    std::string hire;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Do you want to be hired Yes or No\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cin >> hire;

    if (hire == "N" || hire == "n" || hire == "No" || hire == "no")
    {
        std::cout << std::string(50, '=') << "\n";
        std::cout << "You cannot be hired\n";
        std::cout << std::string(50, '=') << "\n";
        return;
    }

    if (hire == "Y" || hire == "y" || hire == "Yes" || hire == "yes")
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::vector<Users::UserRecord> users = {u};
        Users::Save(users);
        std::cout << "You have been hired and saved to the users file\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }

    else
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Please answer Yes or No\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
    }
    return;
}

//======================Staff Removal====================//

void Staff::Remove_Staff()
{
    std::cout << "+=====================================+\n";
    std::cout << "+     Welcome staff for removal       +\n";
    std::cout << "+=====================================+\n";

    std::vector<Users::UserRecord> users = Users::check_File();

    std::string remove;
    std::cout << "+======================================================+\n";
    std::cout << "+                 Enter Staff for Removal              +\n";
    std::cin >> remove;

    auto userToRemove = users.end();
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (remove == it->Name)
        {
            userToRemove = it;
            break;
        }
    }

    if (userToRemove == users.end())
    {
        std::cout << "Cannot Found Staff for firing\n";
        return;
    }

    std::cout << "Found Staff for firing\n";
    users.erase(userToRemove);

    std::ofstream file("../Data/Users.csv");
    if (!file)
    {
        std::cout << "Could not update the users file\n";
        return;
    }

    for (const auto &user : users)
    {
        file << user.Name << "|" << user.Email << "|" << user.Password << "|"
             << user.Username << "|" << role::RoleToString(user.role) << "|\n";
    }
    std::cout << "Staff has been fired\n";
    std::cout << "+======================================================+\n";
}

void Manager::MenuCustomization()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to the Menu Manager\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    int choice;

    while (true)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Menu Options\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "[1] Add Item\n";
        std::cout << "[2] Remove Item\n";
        std::cout << "[3] Special Item\n";
        std::cout << "[4] Edit Item\n";
        std::cout << "[5] Return\n";
        std::cout << "[6] View Menu\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
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
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "you are returning to Menu Display\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
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
void Manager::sales()
{
    std::vector<Menu> menu = Menu::check_Menu();
    std::vector<Orders> orders = Orders::checkOrderFile();

    std::string choice;

    std::cout << "Which sale you want to enter?\n";
    std::cin >> choice;

    bool found = false;
    for (const auto &order : orders)
    {
        if (choice == order.TableID)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Cannot find order\n";
        return;
    }

    bool Order = false;
    if (found)
    {
        std::cout << "Table has been found\n";
        std::string ID;
        std::cout << "Enter Order ID\n";
        std::cin >> ID;

        std::cout << "+=================================================================+\n";
        std::cout << "+                         Sale Orders                             +\n";
        std::cout << "+=================================================================+\n";
        for (const auto &order : orders)
        {
            if (ID == order.OrderID && choice == order.TableID)
            {
                Order = true;
                std::cout << "Order has been found\n";
                std::cout << "ID: " << order.OrderID << "\n"
                          << "Product: " << order.Product << "\n";

                for (const auto &item : menu)
                {
                    if (item.Name == order.Product)
                    {
                        std::cout << "Price: $" << std::fixed << std::setprecision(2)
                                  << item.price << "\n";
                        break;
                    }
                }
                break;
            }
        }
        std::cout << "+=================================================================+\n";
    }

    if (!Order)
    {
        std::cout << "Order cannot be found\n";
        return;
    }
}

void Manager::selected_sales()
{

    std::vector<Orders> orders = Orders::checkOrderFile();
    std::vector<Menu> menu = Menu::check_Menu();


    std::string ID;
    std::cout << "Enter your Order Id\n";
    std::cin >> ID;

    double TotalSales = 0.0;
    int found = 0;


    for (auto & order : orders)
    {

        if (order.OrderID == ID)
        {

            double price = 0.0;
            for (auto & j : menu)
            {
                if (j.Name == order.Product)
                {
                    price = Menu::price;
                }
            }

            std::cout << "Id: " << order.OrderID << "\n";
            std::cout << "Name: " << order.Customer << "\n";
            std::cout << "Product: " << order.Product << "\n";
            std::cout << "Price: $" << price << "\n";

            TotalSales += price;
            found++;
        }
    }

    if (found == 0)
    {
        std::cout << "No orders found for that ID\n";
        return;
    }

    std::cout << "Total Sales: $" << TotalSales << "\n";

    std::ofstream file("../Data/Sales.csv", std::ios::app);
    if (file.is_open())
    {
        file << ID << "|" << found << "|" << TotalSales << "\n";
        std::cout << "Sales have been saved\n";
    }
    else
    {
        std::cout << "Could not open the file\n";
    }
}

void Manager::BestSales()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Best Sales\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<struct sales> sale = sales::checkSaleFile();

    std::cout << std::left << std::setw(15) << "ID"
              << std::setw(15) << "Price"
              << std::setw(15) << "Total Sales" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    for (const auto& s : sale) {
        try {
            if (std::stod(s.TotalSales) >= 50) {
                std::cout << std::left << std::setw(15) << s.ID
                          << std::setw(15) << s.Price
                          << std::setw(15) << s.TotalSales << "\n";
            }
        } catch (...) {}
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Manager::WorstSales()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Welcome to Worst Sales\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<struct sales> sale = sales::checkSaleFile();

    std::cout << std::left << std::setw(15) << "ID"
              << std::setw(15) << "Price"
              << std::setw(15) << "Total Sales" << "\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";

    for (const auto& s : sale) {
        try {
            if (std::stod(s.TotalSales) <= 20) {
                std::cout << std::left << std::setw(15) << s.ID
                          << std::setw(15) << s.Price
                          << std::setw(15) << s.TotalSales << "\n";
            }
        } catch (...) {}
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Manager::TableUsage()
{
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Table Usage\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::vector<Tables> tables = Tables::checkTableFile();

    int occupied = 0, available = 0, reserved = 0;
    std::cout << std::left << std::setw(12) << "Table ID" << "|"
              << std::setw(12) << "Status" << "|"
              << std::setw(10) << "Capacity" << "|\n";
    std::cout << "+" << std::string(60, '-') << "+" << "\n";
    for (const auto &t : tables)
    {
        std::cout << std::left << std::setw(12) << t.TableID << "|"
                  << std::setw(12) << t.avalible << "|"
                  << std::setw(10) << t.capacity << "|\n";
        if (t.avalible == "Occupied")       occupied++;
        else if (t.avalible == "Available" || t.avalible == "Avalible") available++;
        else                                reserved++;
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Occupied: "  << occupied  << "  |  "
              << "Available: " << available << "  |  "
              << "Reserved: "  << reserved  << "\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
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
    std::cout << "\n--- Report Options ---\n";
    std::cout << "[1] View All Sales\n";
    std::cout << "[2] View Selected Total Sales\n";
    std::cout << "[3] View Best Sales\n";
    std::cout << "[4] View Worst Sales\n";
    std::cout << "[5] View Table Usage\n";
    std::cout << "[6] Return to menu\n";
    std::cout << "+============================================================+\n";
    std::cout << "Enter the choice\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        sales();
        break;
    }
    case 2:
    {
        selected_sales();
        break;
    }
    case 3:
    {
       BestSales();
        break;
    }
    case 4:
    {
        WorstSales();
        break;
    }
    case 5:
    {
        TableUsage();
        break;
    }
    case 6:
    {
        std::cout << "+============================================================+\n";
        std::cout << "+                                                            +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+              Returning to Manager Menu                     +\n";
        std::cout << "+                                                            +\n";
        std::cout << "+============================================================+\n";
        Boss();
    }
        default: {
        std::cout << "must choose between 1 - 6\n";break;
    }
    }
}

void Manager::OrderMenu()
{
    int Order;
    while (true)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Order Options\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "[1] Add Order\n";
        std::cout << "[2] Remove Order\n";
        std::cout << "[3] Edit Order\n";
        std::cout << "[4] Return\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Enter your choice\n";
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
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Must choose between 1 - 4\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
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
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table Options\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "[1] Add Table\n";
        std::cout << "[2] Remove Table\n";
        std::cout << "[3] Edit Table\n";
        std::cout << "[4] Return\n";
        std::cout << "[5] View Table\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Enter Choice\n";
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
            Tables::EditTable();
            break;
        }
        case 4:
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "You are returning to Manager Display\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return;
        }
        case 5:
        {
            Tables::ViewTable();
            break;
        }
                default:{std::cout << "must choose between 1 - 5\n";break;}
        }
    }
}