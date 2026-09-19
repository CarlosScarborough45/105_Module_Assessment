#include "Headers/Filesystem.h"
#include <iostream>
#include <filesystem>
#include <iomanip>
#include <string>

namespace fs = std::filesystem;

void FileSystem::ReportFileSizes()
{
    const std::string files[] = {
        "Data/Users.csv",
        "Data/Menu.CSV",
        "Data/Order.csv",
        "Data/Sales.csv",
        "Data/Tables.csv",
        "Data/Table.occupancy.csv"
    };

    std::cout << "+" << std::string(40, '=') << "+\n";
    std::cout << std::left << std::setw(30) << "File" << std::setw(12) << "Size (bytes)" << "\n";
    std::cout << "+" << std::string(40, '=') << "+\n";

    for (const auto &path : files)
    {
        std::error_code ec;
        auto size = fs::file_size(path, ec);
        std::cout << std::left << std::setw(30) << path;
        if (ec)
            std::cout << "N/A\n";
        else
            std::cout << std::setw(12) << size << "\n";
    }

    std::cout << "+" << std::string(40, '=') << "+\n";
}
