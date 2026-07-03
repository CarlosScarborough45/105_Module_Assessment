#include <iostream>
#include <vector>
#include "Global.h"
#include <fstream>
#include <iomanip>
#include <sstream>

void staff(){

	int staff;
	std::cout << "+==================================================+\n";
	std::cout << "|                                                  |\n";
	std::cout << "|           Welcome to Staff Display               |\n";
	std::cout << "|                                                  |\n";
	std::cout << "+==================================================+\n";

	std::cout << "+==================================================+\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|  1. Kitchen          |  2. Tables / Orders       |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|  3. Profile          |  4. Return to Menu        |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "+==================================================+\n";
	std::cin >> staff;

	std::ofstream file("../Orders.CSV");
	if (!file.is_open()) {
		std::cout << "[X] file has not been created" << std::endl;
	}
	else if (file.is_open()) {
		std::cout << "file has been created" << std::endl;
	}

	if (file.app) {
		file << std::left << std::setw(20) << "order ID" << " | "
						  << std::setw(20) << "Table number" << " | "
						  << std::setw(20) << "Items" << " | "
						  << std::setw(20) << "Price" << " | "
						  << std::setw(20) << "Status" << " | "
						  << std::setw(20) << "Time" << " | " << std::endl;
	}

	switch (staff) {
		case 1:{kitchen();	break;}
		case 2:{break;}
		case 3:{profile(); break;}
		case 4:{std::cout << "+======================================+\n"
						  << "|                                      |\n"
						  << "|         You are logging out          |\n"
						  << "|                                      |\n"
						  << "+======================================+\n"; loggedin = false; main(); return;}
		default: {std::cout << " [X] Choose between 1 - 4" << std::endl;break;}
	}
}

void order_Menu(){

	int orders;
	std::cout << "+==================================================+\n";
	std::cout << "|                                                  |\n";
	std::cout << "|				Order & Table Display                |\n";
	std::cout << "|                                                  |\n";
	std::cout << "+==================================================+\n";

	std::cout << "+==================================================+\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|	1. Available Tables  |  2. Place new orders      |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "| 3. View active orders|  4. Return to Menu        |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "|                      |                           |\n";
	std::cout << "+==================================================+\n";
	std::cin >> orders;



	switch (orders) {

		case 1: {break;}
		case 2: {break;}
		case 3: {break;}
		case 4: {break;}

		default:{std::cout << "[X] Must choose between 1 - 4" << std::endl; break;}
	}
}

void profile() {

	User u;

	std::cout << "Your Name: " << " " << u.fullname << std::endl;

	std::cout << "Your Age: " << " " << u.age << std::endl;

	std::cout << "Your Email: " << " " << u.email << std::endl;

	std::cout << "Your Password: " << " " << u.password << std::endl;

	std::cout << "Your Number: " << " " << u.number << std::endl;

	std::cout << "Your Address: " << " " << u.address << std::endl;
}