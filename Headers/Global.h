#ifndef INC_105_MODULE_ASSESSMENT_GLOBAL_H
#define INC_105_MODULE_ASSESSMENT_GLOBAL_H
#include <iostream>
#include <iostream>
#include <vector>

class User{
	public:
		std::string username;
		std::string Password;
		std::string Age;
		std::string Name;
		std::string Lastname;
		std::string Role;
};

inline std::vector<User> users;

inline User u;
#endif //INC_105_MODULE_ASSESSMENT_GLOBAL_H
