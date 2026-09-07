#include "Users.h"

class WaitStaff : public Users
{
public:
    void Waiter();
    void Order();
    void table();
    void menu();

public:
    void Add_Order();
    void View_Order();
    void View_Kitchen_Status();
    void View_Selected_TableOrder();
    void ViewCustomerOrder();
    void PendingOrder();
};