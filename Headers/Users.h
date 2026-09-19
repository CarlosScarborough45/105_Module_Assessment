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
    roles role = roles::Admin;

public:
    struct UserRecord
    {
        std::string Name, Email, Password, Username;
        roles role;
    };

    static std::vector<UserRecord> check_File();
    static void Save(std::vector<Users::UserRecord> &users);
    static int main();

public:
    static void Login();
    static void registration();
};