#pragma once
#include <string>
#include <vector>

enum class roles
{
    WaitStaff,
    Kitchen,
    Manager,
    Admin
};

class Users
{
private:
    std::string Name, Email, Password, Username;
    roles role;

public:
    struct UserRecord
    {
        std::string Name, Email, Password, Username;
        roles role;
    };

    static std::vector<UserRecord> check_File();
    static void Save(const UserRecord &user);

    // Make Login/registration public so callers in `main.cpp` can invoke them
public:
    static void Login();
    static void registration();
};