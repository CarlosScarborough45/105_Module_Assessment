#include <iostream>
#include <vector>
#include "Global.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Orders.h"

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

	switch (staff) {
		case 1:{kitchen();	break;}
		case 2:{order_Menu(); break;}
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
		case 2: {place_new_orders(); break;}
		case 3: {break;}
		case 4: {break;}

		default:{std::cout << "[X] Must choose between 1 - 4" << std::endl; break;}
	}
}

void place_new_orders() {

	std::cout << "+==================================================+\n";
	std::cout << "|                                                  |\n";
	std::cout << "|           Welcome to new orders		             |\n";
	std::cout << "|                                                  |\n";
	std::cout << "+==================================================+\n";

	std::vector<Order> order;
	Order O;

	//checks if any orders are empty if not then it will loop out any orders thats in the system.
	if (order.empty()) {
		std::cout << "[X] Must place an order to continue" << std::endl;
	}
	else {
		for (Order& O : order) {
			std::cout << "Table: " << O.TableNumber << std::endl;
			std::cout << "Items: " << O.Items << std::endl;
			std::cout << "Status: " << O.Status << std::endl;
			std::cout << "_________________________________" << std::endl;
		}
	}


	std::ofstream file("../Orders.CSV", std::ios::app);
	if (!file.is_open()) {
		std::cout << "[X] file has not been created" << std::endl;
	}
	else if (file.is_open()) {
		std::cout << "file has been created" << std::endl;
	}

	std::cout << "Enter the table number: " << std::endl;
	std::cin >> O.TableNumber;

	std::cout << "Enter the Item: " << std::endl;
	std::cin >> O.Items;

	std::cout << "Enter the Status: " << std::endl;
	std::cin >> O.Status;

	std::cout << "Enter the order ID: " << std::endl;
	std::cin >> O.orderID;

	if (file.tellp() == 0) {
		file << std::left << std::setw(20) << "OrderID" << " | "
						  << std::setw(20) << "TableNumber" << " | "
						  << std::setw(20) << "Item" << " | "
						  << std::setw(20) << "Status" << " | " << std::endl;
	}

	file << std::left << std::setw(20) << O.orderID << " | "
					  << std::setw(20) << O.TableNumber << " | "
					  << std::setw(20) << O.Items << " | "
					  << std::setw(20) << O.Status << " | " << std::endl;

	order.push_back(O);
	file.close();

	std::cout << "[ok] Order has been saved successfully" << std::endl;
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