#include "Users.h"

class kitchen : public Users
{
private:
public:
    static void Cook();
    static void Pending();
    static void Completed();
    static void TurnPending();
};