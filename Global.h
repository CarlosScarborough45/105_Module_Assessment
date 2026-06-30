#ifndef INC_105MODULE_GLOBAL_H
#define INC_105MODULE_GLOBAL_H
#include <string>
#include <iostream>

enum class Roles{Staff, Manager, Admin};
inline std::string RolesUser;

class User {
	public:
		std::string age;
		std::string email;
		std::string password;
		std::string fullname;
		std::string address;
		std::string number;
		Roles role;
};

inline bool loggedin  = false;
inline bool found     = false;
inline User currentUser;

inline bool isvalidpassword(std::string& password) {
	bool hasUpper = false;
	bool hasLower = false;
	bool hasDigit = false;
	bool hasSpecial = false;

	if (password.length() <= 8) {
		std::cout << "must have a length of 8 characters" << std::endl;
		return false;
	}

		for (char pw : password)
		{
			if (isupper(pw)) hasUpper   = true;
			if (islower(pw)) hasLower   = true;
			if (isdigit(pw)) hasDigit   = true;
			if (ispunct(pw)) hasSpecial = true;
		}

		if (!hasUpper){std::cout << "Must have an Upper character (U)" << std::endl;}
		if (!hasLower){std::cout << "Must have an Lower character (u)" << std::endl;}
		if (!hasDigit){std::cout << "Must have an Digit character (1)" << std::endl;}
		if (!hasSpecial){std::cout << "Must have an Special character (!)" << std::endl;
	}

	return hasDigit && hasLower && hasSpecial && hasUpper;
}

inline bool isvalidEmail(std::string& email) {
	if (email.length() > 30) {
		return false;
	}

	size_t atPos = email.find("@");
	if (atPos == std::string::npos || atPos == 0) {
		return false;
	}

	std::string domain = email.substr(atPos + 1);


	if (domain != "gmail.com" && domain != "outlook.com" && domain != "Eatandtreats.com") {
		return false;
	}
	return true;

}

void Signup();
void staff();
void Manager();
void Admin();
void login();
int main();
#endif //INC_105MODULE_GLOBAL_H