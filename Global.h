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

void Signup();
void staff();
void Manager();
void Admin();
void login();
int main();
#endif //INC_105MODULE_GLOBAL_H