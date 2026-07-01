#include <iostream>
#include <vector>
#include "Global.h"

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
		case 1:{break;}
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

void profile() {

	User u;

	std::cout << "Your Name: " << " " << u.fullname << std::endl;

	std::cout << "Your Age: " << " " << u.age << std::endl;

	std::cout << "Your Email: " << " " << u.email << std::endl;

	std::cout << "Your Password: " << " " << u.password << std::endl;

	std::cout << "Your Number: " << " " << u.number << std::endl;

	std::cout << "Your Address: " << " " << u.address << std::endl;
}