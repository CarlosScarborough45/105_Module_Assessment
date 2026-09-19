#include <iostream>
#include "Headers/Filemanagement.h"
#include "Headers/Admin.h"

void FileManagement() {
	int choice = 0;
	while (choice != 5) {
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "Welcome to File Management\n";
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "[1] Check Selected File Size\n";
		std::cout << "[2] View Selected folder and Files\n";
		std::cout << "[3] Delete Selected File\n";
		std::cout << "[4] Check Files\n";
		std::cout << "[5] Return to Menu\n";
		std::cout << "+" << std::string(60, '=') << "+" << "\n";
		std::cout << "Enter Choice\n";
		std::cin >> choice;

		switch (choice) {
			case 1: {CheckFile();	break;}
			case 2: {ViewFiles();	break;}
			case 3: {DeleteFiles();	break;}
			case 4: {CheckFile();	break;}
			case 5: {
				std::cout << "+" << std::string(60, '=') << "+" << "\n";
				std::cout << "Returning to Menu Display\n";
				std::cout << "+" << std::string(60, '=') << "+" << "\n";
				Admin::TopBoss();
			}
				default: {
				std::cout << "+" << std::string(60, '=') << "+" << "\n";
				std::cout << "Must Choose between 1 - 5\n";
				std::cout << "+" << std::string(60, '=') << "+" << "\n";
				return;
			}
		}
	}
}