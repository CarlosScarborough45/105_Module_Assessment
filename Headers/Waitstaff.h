#include "Users.h"

class WaitStaff : public Users
{
public:
    static void Waiter();
    void Order();
    void table();
    void menu();

public:
    static void Add_Order();
    static void View_Order();
    static void View_Kitchen_Status();
    static void View_Selected_TableOrder();
    static void ViewCustomerOrder();
    static void PendingOrder();
};