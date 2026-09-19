#include "./Headers/Tables.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string Tables::avalible;

std::vector<Tables> Tables::checkTableFile()
{
    std::ifstream file("../Data/Tables.csv");
    if (!file.is_open())
    {
        std::cout << "File has not been created\n";
        return {};
    }
    std::vector<Tables> table;
    Tables t;

    std::string line;
    std::stringstream ss;

    while (std::getline(file, line))
    {
        ss.clear();
        ss.str(line);

        if (line == "Table ID|Availability|Capacity")
        {
            continue;
        }

        t = Tables{};
        std::getline(ss, t.TableID, '|');
        std::getline(ss, t.avalible, '|');
        std::getline(ss, t.capacity, '|');

        if (!t.TableID.empty())
        {
            table.push_back(t);
        }
    }

    return table;
}

bool Tables::SetAvailability(const std::string &tableNumber, const std::string &availability)
{
    std::vector<Tables> tables = checkTableFile();
    bool found = false;

    for (Tables &table : tables)
    {
        if (table.TableID == tableNumber)
        {
            table.avalible = availability;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table cannot be found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";     
        return false;
    }

    std::ofstream file("../Data/Tables.csv");
    if (!file.is_open())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File cannot be created\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return false;
    }

    file << "Table ID|Avalibility|Capacity\n";
    for (const Tables &table : tables)
    {
        file << table.TableID << "|" << table.avalible << "|"
             << table.capacity << "\n";
    }

    return true;
}

bool checkcapacity(const std::string &capacity)
{
    try
    {
        if (std::stoi(capacity) > 10)
        {
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            std::cout << "Current table capacity cannot be more than 10 people\n";
            std::cout << "+" << std::string(60, '=') << "+" << "\n";
            return false;
        }
    }
    catch (const std::invalid_argument &)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table capacity must be a number\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return false;
    }

    return true;
}

void Tables::AddTable()
{
    std::string TableID, avalible, capacity;
    std::cout << "Enter Table ID\n";
    std::cin >> TableID;

    std::cout << "Enter Availability\n";
    std::cin >> avalible;

    std::cout << "Enter Capacity\n";
    std::cin >> capacity;

    if (!checkcapacity(capacity))
    {
        return;
    }

    std::fstream file("../Data/Tables.csv", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "File has not been created\n";
    }

    file << "Table ID" << "|" << "Availability" << "|" << "Capacity" << "\n";
    file << TableID << "|" << avalible << "|" << capacity << "\n";
    std::cout << "New Table has been created\n";
}

static void saveTableFile(const std::vector<Tables> &tables)
{
    std::ofstream file("../Data/Tables.csv");
    if (!file.is_open())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "File cannot be opened\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }
    file << "Table ID|Availability|Capacity\n";
    for (const Tables &t : tables)
    {
        file << t.TableID << "|" << t.avalible << "|" << t.capacity << "\n";
    }
}

void Tables::EditTable()
{
    std::vector<Tables> tables = checkTableFile();

    if (tables.empty())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "No tables found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << std::left << std::setw(12) << "Table ID" << "|"
              << std::setw(12) << "Available" << "|"
              << std::setw(10) << "Capacity" << "|\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &t : tables)
    {
        std::cout << std::left << std::setw(12) << t.TableID << "|"
                  << std::setw(12) << t.avalible << "|"
                  << std::setw(10) << t.capacity << "|\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string id;
    std::cout << "Enter Table ID to edit\n";
    std::cin >> id;

    bool found = false;
    for (const auto &t : tables)
    {
        if (t.TableID == id) { found = true; break; }
    }

    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table not found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::string field;
    std::cout << "Enter field to change (TableID, Availability, Capacity)\n";
    std::cin >> field;

    if (field != "TableID" && field != "Availability" && field != "Capacity")
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Invalid field name\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::string newValue;
    std::cout << "Enter new value\n";
    std::cin >> newValue;

    if (field == "Capacity" && !checkcapacity(newValue))
    {
        return;
    }

    for (auto &t : tables)
    {
        if (t.TableID == id)
        {
            if (field == "TableID")       t.TableID  = newValue;
            else if (field == "Availability") t.avalible = newValue;
            else if (field == "Capacity") t.capacity = newValue;
            break;
        }
    }

    saveTableFile(tables);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Table updated\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Tables::RemoveTable()
{
    std::vector<Tables> tables = checkTableFile();

    if (tables.empty())
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "No tables found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << std::left << std::setw(12) << "Table ID" << "|"
              << std::setw(12) << "Available" << "|"
              << std::setw(10) << "Capacity" << "|\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    for (const auto &t : tables)
    {
        std::cout << std::left << std::setw(12) << t.TableID << "|"
                  << std::setw(12) << t.avalible << "|"
                  << std::setw(10) << t.capacity << "|\n";
    }
    std::cout << "+" << std::string(60, '=') << "+" << "\n";

    std::string id;
    std::cout << "Enter Table ID to remove\n";
    std::cin >> id;

    bool found = false;
    for (const auto &t : tables)
    {
        if (t.TableID == id) { found = true; break; }
    }

    if (!found)
    {
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        std::cout << "Table not found\n";
        std::cout << "+" << std::string(60, '=') << "+" << "\n";
        return;
    }

    std::string confirm;
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Remove table " << id << "? (Yes/No)\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cin >> confirm;

    if (confirm != "Yes" && confirm != "yes")
    {
        std::cout << "Removal cancelled\n";
        return;
    }

    tables.erase(std::remove_if(tables.begin(), tables.end(),
        [&id](const Tables &t) { return t.TableID == id; }), tables.end());

    saveTableFile(tables);
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
    std::cout << "Table " << id << " has been removed\n";
    std::cout << "+" << std::string(60, '=') << "+" << "\n";
}

void Tables::ViewTable()
{
    const std::vector<Tables> tables = checkTableFile();
    if (tables.empty())
    {
        return;
    }

    std::cout << "\nTables\n";
    std::cout << "Table ID | Available | Capacity\n";
    for (const Tables &table : tables)
    {
        std::cout << "|" << table.TableID << " | "
                  << table.avalible << " | "
                  << table.capacity << "\n";
    }
}