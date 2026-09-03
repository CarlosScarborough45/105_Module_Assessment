#include <string>
#include <vector>

class Tables
{
public:
    std::string avalible;
    std::string TableID;
    std::string capacity;

    static bool CheckTable(const std::string &tableNumber);
    static bool SetAvailability(const std::string &tableNumber, const std::string &availability);
    static std::vector<Tables> checkTableFile();
    static void AddTable();
    static void RemoveTable();
    static void EditTable();
    static void ViewTable();
};