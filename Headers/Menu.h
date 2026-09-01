#include "Manager.h"
#include <string>

class Menu{

    private:
        std::string menuID;
        std::string Name;
        double price;
        bool avalability = false;
        
    public:
    void AddItem();
    void ViewItem();
    void EditItem();
    void RemoveItem();
};