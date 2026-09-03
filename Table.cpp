#include "./Headers/Tables.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<Tables> Tables::checkTableFile()
{
    std::ifstream file("Data/Tables.csv");
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

        if (line == "Table ID|Avalibility|Capacity")
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
        return false;
    }

    std::ofstream file("Data/Tables.csv");
    if (!file.is_open())
    {
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
            std::cout << "Current table capacity cannot be more than 10 people\n";
            return false;
        }
    }
    catch (const std::invalid_argument &)
    {
        std::cout << "Table capacity must be a number\n";
        return false;
    }

    return true;
}

void Tables::AddTable()
{
    std::string TableID, avalible, capacity;
    std::cout << "Enter Table ID\n";
    std::cin >> TableID;

    std::cout << "Enter Avalibility\n";
    std::cin >> avalible;

    std::cout << "Enter Capacity\n";
    std::cin >> capacity;

    if (!checkcapacity(capacity))
    {
        return;
    }

    std::fstream file("Data/Tables.csv", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "File has not been created\n";
    }

    file << "Table ID" << "|" << "Avalibility" << "|" << "Capacity" << "\n";
    file << TableID << "|" << avalible << "|" << capacity << "\n";
    std::cout << "New Table has been created\n";
}

void Tables::EditTable()
{
}

void Tables::RemoveTable()
{
}

void Tables::ViewTable()
{
    const std::vector<Tables> tables = checkTableFile();
    if (tables.empty())
    {
        return;
    }

    std::cout << "+===================================+\n";
    std::cout << "+ Table Id| Table Avalible | Capacity\n";
    std::cout << "+===================================+\n";
    for (const Tables &table : tables)
    {
        std::cout << "|" << table.TableID << " | "
                  << table.avalible << " | "
                  << table.capacity << "\n";
    }
    std::cout << "+===================================+\n";
}