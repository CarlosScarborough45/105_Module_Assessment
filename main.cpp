#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

#include "Global.h"

bool operator==(const std::string & lhs, Roles rhs);

bool found = false;
bool loggedin = false;


int main()
{
	std::vector<User> users;
	User u;

    std::string InputPassword, InputUsername;

    std::cout << "+==================================================+" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "|             Welcome to Eat && Treats             |" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "+==================================================+" << std::endl;

    std::cout << "+====================================================+" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|               Welcome to your login                |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "+====================================================+" << std::endl;

	std::fstream file("../Users.CSV");
	std::string line;

	while (getline(file, line)) {
		if (line.empty())
			continue;

		std::stringstream ss (line);

		std::getline(ss, u.fullname, ',');
		std::getline(ss, u.age, ',');
		std::getline(ss, u.email, ',');
		std::getline(ss, u.password, ',');
		std::getline(ss, u.number, ',');
		std::getline(ss, u.address, ',');
		std::getline(ss, RolesUser, ',');

		if (RolesUser == "Staff") {
			u.role = Roles::Staff;
		}
		else if (RolesUser == "Manager") {
			u.role = Roles::Manager;
		}
		else if (RolesUser == "Admin") {
			u.role = Roles::Admin;
		}
		users.push_back(u);
	}

    std::cout << "Please Enter your Email: "    << std::endl;
    std::cin >> InputUsername;

    std::cout << "Please Enter your Password: " << std::endl;
    std::cin >> InputPassword;

	User loggedinUser;

	for (const User& u : users) {
		if (InputUsername == u.email && InputPassword == u.password) {
			std::cout << "Email and Password has been found" << std::endl;
			loggedinUser = u;
			found = true;
			break;
		}
	}

		if (found == true) {
			std::cout << "Login was successful" << std::endl;
				switch (loggedinUser.role) {
					case Roles::Staff: {staff(); break;}
					case Roles::Manager: {Manager(); break;}
					case Roles::Admin: {Admin(); break;}
				}
			}

			if (found == false) {
				std::cout << "+==========================================+"
						  << "|                                          |"
						  << "|    Email and Password does not match     |"
						  << "|                                          |"
						  << "+==========================================+" << std::endl;
				Signup();
			}
		}

void Signup(){

    std::ofstream file("../Users.CSV", std::ios::app);

    if (!file.is_open()) {
        std::cout << "+==========================================+"
                  << "|                                          |"
                  << "|    File Cannot be created or found       |"
                  << "|                                          |"
                  << "+==========================================+" << std::endl;
    }
    else if (file.is_open()) {
        std::cout << "+==========================================+"
                  << "|                                          |"
                  << "|     File Has been Created Continue       |"
                  << "|                                          |"
                  << "+==========================================+" << std::endl;
    }

    std::vector<User> users;
    User u;

    std::cout << "+====================================================+" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|              Welcome to Registration               |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "|                                                    |" << std::endl;
    std::cout << "+====================================================+" << std::endl;

    std::cout << "Enter your Name: " << std::endl;
    std::cin >> u.fullname;

    std::cout << "Enter your Age: " << std::endl;
    std::cin >> u.age;

    std::cout << "Enter your Email: " << std::endl;
    std::cin >> u.email;

    std::cout << "Enter your Password: " << std::endl;
    std::cin >> u.password;

    std::cout << "Enter your number: " << std::endl;
    std::cin >> u.number;

    std::cout << "Enter your Address: " << std::endl;
    std::cin >> u.address;

	int role;
    std::cout << "Select your Role > "
              << "1. Staff "
			  << "2. Manager "
			  << "3. Admin " << std::endl;
	std::cin >> role;

	switch (role) {
		case 1: {u.role = Roles::Staff; break;}
		case 2: {u.role = Roles::Manager; break;}
		case 3: {u.role = Roles::Admin; break;}
		default: {std::cout << "+==========================================+"
							<< "|                                          |"
							<< "|     Must select Between 1 - 3			   |"
							<< "|                                          |"
							<< "+==========================================+" << std::endl; break;}
	}

	if (u.role == Roles::Staff) RolesUser =  "Staff";
	if (u.role == Roles::Manager) RolesUser =  "Manager";
	if (u.role == Roles::Admin) RolesUser =  "Admin";

	users.push_back(u);

	std::string line;

	    file << std::left << "FullName " << ","
						  << "Age "		<< ","
						  << "Email "	<< ","
						  << "Password "<< ","
						  << "Number "	<< ","
						  << "Address "	<< ","
						  << "Role "		<< "," << std::endl;

		file << std::left <<  u.fullname << ","
						  <<  u.age	   << ","
						  <<  u.email	   << ","
						  <<  u.password << ","
						  <<  u.number   << ","
						  <<  u.address  << ","
						  <<  RolesUser << "," << std::endl;
	file.close();

	std::cout << "+==========================================+"
			  << "|                                          |"
			  << "|     New User has been Created		     |"
			  << "|                                          |"
			  << "+==========================================+" << std::endl;
}
