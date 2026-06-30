#include "Global.h"
#include <iomanip>

void printRow(const std::string& left, const std::string& right) {
	std::cout << "|  " << std::left << std::setw(32) << left
			   << "|  " << std::left << std::setw(32) << right << "|\n";
}

void Admin() {

	int choice;
	std::cout << "+=====================================================================+\n";
	std::cout << "|                       Welcome to Admin Display                     |\n";
	std::cout << "+=====================================================================+\n";
	printRow("1. View Today Report", "2. Update menu");
	printRow("3. Manage staff accounts", "4. View all tables");
	printRow("5. Profile", "6. Return to menu");
	std::cout << "+=====================================================================+\n";
	std::cin >> choice;

	switch (choice) {
		case 1: {	break;}
		case 2: {	break;}
		case 3: {	break;}
		case 4: {	break;}
		case 5: {	break;}
		case 6: {std::cout << "+======================================+\n"
						  << "|                                      |\n"
						  << "|         You are logging out          |\n"
						  << "|                                      |\n"
						  << "+======================================+\n"; loggedin = false; main(); return;}
		default:{std::cout << " [X] Must have a choice between 1 - 6"; return;}
	}

}