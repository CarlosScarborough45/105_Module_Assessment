#include "Headers/Manager.h"
#include "Headers/Menu.h"
#include "./Headers/Tables.h"
#include "./Headers/Order.h"
#include <cctype>
#include <fstream>
#include <iomanip>
#include <limits>

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

    std::cout << "\nAll Stock\n";
    for (const auto &M : menu)
    {
        std::cout << "Name:" << M.Name << "\n"
                  << "ID:" << M.menuID << "\n"
                  << "Price:" << "$" << M.price << "\n"
                  << "Quantity: " << M.Quantity << "\n"
                  << "Avalability:" << M.avalability << "\n";
    }
    return;
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
                      << "Quantity: " << M.Quantity << "\n"
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
              << "Avalible Stock: " << menus[index].Quantity << std::endl;

    std::cout << "+============================================+\n";
    std::cout << "+     How much stock do you want to Refil    +\n";
    std::cout << "+============================================+\n";

    int Amount = 0;
    std::cin >> Amount;

    if (std::cin.fail() || Amount <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "+============================================+\n";
        std::cout << "+     Invalid amount. Nothing changed.       +\n";
        std::cout << "+============================================+\n";
        return;
    }

    else if (Amount >= 20)
    {
        std::cout << std::string(50, '=') << "\n";
        std::cout << "Cannot Change stock that is higher\n";
        std::cout << std::string(50, '=') << "\n";
        return;
    }

    std::string status;
    std::cout << "Change Stock Status: \n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, status);

    menus[index].Quantity += Amount;
    if (!status.empty())
    {
        menus[index].avalability = status;
    }
    Menu::save_Menu(menus);

    std::cout << menus[index].Name << " restocked to "
              << menus[index].Quantity << " Changes Status "
              << menus[index].avalability << "\n";
    return;
}

void Manager::StockManage()
{
    std::cout << "\nStock Management\n";

    int Stock;
    std::cout << "\n--- Stock Options ---\n";
    std::cout << "[1] View Stock\n";
    std::cout << "[2] Select Stock\n";
    std::cout << "[3] Refill Stock\n";
    std::cout << "[4] Return to menu\n";
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
        std::cout << "\nSelected User\n";
        std::cout << "Name:" << u.Name << "\n"
                  << "Email:" << u.Email << "\n"
                  << "Password:" << u.Password << "\n"
                  << "Username:" << u.Username << "\n"
                  << "role:" << RoleToString(u.role) << "\n";
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

            std::cout << "\nSelected User\n";
            std::cout << "Selected user has been found\n";
            std::cout << "Name:" << u.Name << "\n"
                      << "Email:" << u.Email << "\n"
                      << "Password:" << u.Password << "\n"
                      << "Username:" << u.Username << "\n"
                      << "role:" << RoleToString(u.role) << "\n";
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
    std::cout << "[3] View logged profile\n";
    std::cout << "[4] Return to menu\n";
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
        std::cout << "\n--- Manager Menu ---\n";
        std::cout << "[1] Menu\n";
        std::cout << "[2] Reporting\n";
        std::cout << "[3] Table\n";
        std::cout << "[4] Overrides\n";
        std::cout << "[5] Logout\n";
        std::cout << "[6] Profile\n";
        std::cout << "[7] Orders\n";
        std::cout << "[8] Stock Management\n";
        std::cout << "[9] Staff\n";

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
    std::cout << "+=========================================+\n";
    std::cout << "+  Welcome to Eats and Treats Hiring Page +\n";
    std::cout << "+=========================================+\n";

    int Staff;
    std::cout << "+========================================+\n";
    std::cout << "[1] Add Staff\n";
    std::cout << "[2] Remove Staff\n";
    std::cout << "[3] Return to Manager View\n";
    std::cout << "+=======================================+\n";
    std::cout << "Enter a choice: \n";
    std::cin >> Staff;

    switch (Staff)
    {
    case 1:
    {
        Staff::Add_Staff();
        break;
    }
    case 2:
    {
        Staff::Remove_Staff();
        break;
    }
    case 3:
    {
        std::cout << "You are Returning back to Manager view no more Hires\n";
        return;
    }
    default:
    {
        std::cout << "Must Make a choice between 1 - 3\n";
        return;
    }
    }
}

void Staff::Add_Staff()
{
    std::cout << "+==============================================+\n";
    std::cout << "+         Welcome to Eat and Treats            +\n";
    std::cout << "+==============================================+\n";

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

    std::string normalisedRole = roleinput;
    for (char &character : normalisedRole)
    {
        character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
    }

    if (normalisedRole != "kitchen" && normalisedRole != "waitstaff" && normalisedRole != "waiter")
    {
        std::cout << "Managers can only hire Kitchen or Waitstaff employees\n";
        return;
    }

    std::string hire;
    std::cout << "Do you want to be hired Yes or No\n";
    std::cin >> hire;

    if (hire == "N" || hire == "n" || hire == "No" || hire == "no")
    {
        std::cout << "You have not been hired\n";
        return;
    }

    if (hire == "Y" || hire == "y" || hire == "Yes" || hire == "yes")
    {
        u.role = Users::ParseRole(normalisedRole);
        Users::Save(u);
        std::cout << "You have been hired and saved to the users file\n";
        return;
    }

    std::cout << "Please answer Yes or No\n";
}

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

    std::ofstream file("Data/Users.csv");
    if (!file)
    {
        std::cout << "Could not update the users file\n";
        return;
    }

    for (const auto &user : users)
    {
        file << user.Name << "|" << user.Email << "|" << user.Password << "|"
             << user.Username << "|" << RoleToString(user.role) << "|\n";
    }
    std::cout << "Staff has been fired\n";
    return;
    std::cout << "+======================================================+\n";
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
        std::cout << "\n--- Menu Options ---\n";
        std::cout << "[1] Add Item\n";
        std::cout << "[2] Remove Item\n";
        std::cout << "[3] Special Item\n";
        std::cout << "[4] Edit Item\n";
        std::cout << "[5] Return\n";
        std::cout << "[6] View Menu\n";
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
}

void Manager::BestSales()
{
}

void Manager::WorstSales()
{
}

void Manager::TableUsage()
{
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
        Manager::sales();
        break;
    }
    case 2:
    {
        Manager::selected_sales();
        break;
    }
    case 3:
    {
        Manager::BestSales();
        break;
    }
    case 4:
    {
        Manager::WorstSales();
        break;
    }
    case 5:
    {
        Manager::TableUsage();
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
        return;
    }
    }
}

void Manager::OrderMenu()
{
    int Order;
    while (true)
    {
        std::cout << "\n--- Order Options ---\n";
        std::cout << "[1] Add Order\n";
        std::cout << "[2] Remove Order\n";
        std::cout << "[3] Edit Order\n";
        std::cout << "[4] Return\n";
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
        std::cout << "\n--- Table Options ---\n";
        std::cout << "[1] Add Table\n";
        std::cout << "[2] Remove Table\n";
        std::cout << "[3] Edit Table\n";
        std::cout << "[4] Return\n";
        std::cout << "[5] View Table\n";
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