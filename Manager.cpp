#include <vector>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "Orders.h"
#include "Global.h"


void Manager() {

	int manager;
	std::cout << "+==================================================+\n";
	std::cout << "|                                                 |\n";
	std::cout << "|								                    |\n";
	std::cout << "|            Welcome to Manager Display           |\n";
	std::cout << "|                                                 |\n";
	std::cout << "|                                                 |\n";
	std::cout << "+==================================================+\n";

	std::cout << "+==================================================+\n";
	std::cout << "|                          |                       |\n";
	std::cout << "|  1. Kitchen				 | 2. Tables / Orders    |\n";
	std::cout << "|                          |                       |\n";
	std::cout << "|  3. Profile              |  4. Return to Menu    |\n";
	std::cout << "|                          |                       |\n";
	std::cout << "|  5. Sales	             |  6. Menu changes      |\n";
	std::cout << "+==================================================+\n";
	std::cin >> manager;

	switch (manager) {
		case 1: {	break;}
		case 2: {	break;}
		case 3: {	break;}
		case 4: {	break;}
		case 5: {sales(); break;}
		case 6: {	break;}
	}


}
void sales() {

    Order search;
    std::cout << "Enter table number: " << std::endl;
    std::cin >> search.TableNumber;

    std::ifstream file("../Orders.CSV");
    if (!file.is_open()) {
        std::cout << "[X] Error cannot open file" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    std::vector<Order> orders;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        Order O;
        std::stringstream ss(line);
        std::getline(ss, O.orderID,     '|');
        std::getline(ss, O.TableNumber, '|');
        std::getline(ss, O.Items,       '|');
        std::getline(ss, O.Price,       '|');
        std::getline(ss, O.Status,      '|');
        orders.push_back(O);
    }
    file.close();

    // Display and calculate
    double total = 0.0;
    std::string allItems = "";

    std::cout << "+=====================================================+" << std::endl;
    std::cout << "| Table " << search.TableNumber << " Orders          |" << std::endl;
    std::cout << "+=====================================================+" << std::endl;

    for (const Order& O : orders) {
        if (O.TableNumber == search.TableNumber && !O.Price.empty()) {
            std::cout << "| OrderID: " << O.orderID << std::endl;
            std::cout << "| Items:   " << O.Items   << std::endl;
            std::cout << "| Price:  $" << O.Price   << std::endl;
            std::cout << "+-------------------------+"   << std::endl;
            total += std::stod(O.Price);
            allItems += O.Items + " "; // build up items string
        }
    }

    std::cout << "| Grand Total: $" << total << std::endl;
    std::cout << "+===================================+" << std::endl;

    // Save to Sales.CSV
    bool fileExists = std::filesystem::exists("../Sales.CSV") &&
                      std::filesystem::file_size("../Sales.CSV") > 0;

    std::ofstream salefile("../Sales.CSV", std::ios::app); // correct variable name
    if (!salefile.is_open()) {
        std::cout << "[X] Could not open Sales.CSV" << std::endl;
        return;
    }

    if (!fileExists) {
        salefile << "TableNumber | Items | Total\n"; // write header once
    }

    salefile << search.TableNumber << " | "
             << allItems           << " | "
             << total              << "\n";
    salefile.close();

    std::cout << "[OK] Saved to Sales.CSV!" << std::endl;
}