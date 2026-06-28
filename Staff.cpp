#include <iostream>
#include <vector>
#include "Global.h"

void staff(){

	int staff;
	std::cout << "+==================================================+" << std::endl;
	std::cout << "|                                                 |" << std::endl;
	std::cout << "|								                    |" << std::endl;
	std::cout << "|            Welcome to Staff Display             |" << std::endl;
	std::cout << "|                                                 |" << std::endl;
	std::cout << "|                                                 |" << std::endl;
	std::cout << "+==================================================+" << std::endl;

	std::cout << "+==================================================+" << std::endl;
	std::cout << "|                          |                       |" << std::endl;
	std::cout << "|  1. Kitchen				 | 2. Tables / Orders    |" << std::endl;
	std::cout << "|                          |                       |" << std::endl;
	std::cout << "|  3. Profile              |  4. Return to Menu    |" << std::endl;
	std::cout << "|                          |                       |" << std::endl;
	std::cout << "+==================================================+" << std::endl;
	std::cin >> staff;

	switch (staff) {
		case 1:{break;}
		case 2:{break;}
		case 3:{break;}
		case 4:{std::cout <<"+======================================+\n"
					      <<"|										|\n"
						  <<"|										|\n"
					      <<"|		You are logging out				|\n"
						  <<"|										|\n"
						  <<"|										|\n"
						  <<"+======================================+\n";break;}
		default: {std::cout << " [X] Choose between 1 - 4" << std::endl;break;}
	}
}