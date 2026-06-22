#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include <fstream>
#include <iostream>
#include <sstream>
#include "raygui.h"
#include "Headers/Screens.h"
#include "Headers/Global.h"

bool LoginEditMode = false;
char LoginText[128] = " ";
bool PasswordEditMode = false;
char PasswordText[128] = " ";


int main()
{
    InitWindow(1500, 850, "Eats & Treats");
    SetTargetFPS(30);

    bool dropdown = false;
    int selectedRole = 0;
    bool loginFailed = false;

    std::string line;

    std::ifstream file("../File/User.CSV");

    if (!file.is_open())
    {
        DrawText("Error could not open File or Find file Please register!!!", 500, 500, 100, BLACK);
    }

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, lastname, username, password, age, role;

        std::getline(ss, name, '|');
        std::getline(ss, lastname, '|');
        std::getline(ss, username, '|');
        std::getline(ss, password, '|');
        std::getline(ss, age, '|');
        std::getline(ss, role, '|');

        auto trim = [](std::string s)
        {
            s.erase(0, s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
            return s;
        };

        User u;

        u.Name = trim(name);
        u.Lastname = trim(lastname);
        u.username = trim(username);
        u.Password = trim(password);
        u.Age = trim(age);
        u.Role = trim(role);

        users.push_back(u);
    }
    file.close();

    DrawText("Users has been loaded", 500, 500, 100, BLACK);


    while (!WindowShouldClose())
    {
        BeginDrawing();


        if (currentScreen == Screen::LOGIN)
        {
            ClearBackground({0, 255, 255, 255});
            DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});
            DrawText("\n\n Welcome to \n\n\n Eats & Treats", 20, 220, 40, WHITE);
            DrawText("Welcome to your login", 620, 130, 38, {10, 61, 92, 255});
            DrawText("Sign into your Account", 700, 200, 20, {10, 61, 92, 255});

            DrawText("UserName", 650, 320, 20, {74, 122, 150, 255});
            if (GuiTextBox({650, 350, 350, 45}, LoginText, 128, LoginEditMode))
                LoginEditMode = !LoginEditMode;

            DrawText("Password", 650, 520, 20, {74, 122, 150, 255});
            if (GuiTextBox({650, 550, 350, 45}, PasswordText, 128, PasswordEditMode))
                PasswordEditMode = !PasswordEditMode;

            if (GuiButton((Rectangle){900, 600, 200, 40}, "SIGN - IN"))
            {
                bool found = false;

                for (User& u : users)
                {
                    if (u.username == std::string(LoginText).substr(1)
                        && u.Password == std::string(PasswordText).substr(1))
                    {
                        found = true;
                        User currentuser = u;
                        loginFailed = false;

                        if (u.Role == "Admin") currentScreen = Screen::AdminDashboard;
                        else if (u.Role == "Customer") currentScreen = Screen::CustomerDashboard;
                        else if (u.Role == "Manager") currentScreen = Screen::ManagerDashboard;
                        else if (u.Role == "Staff") currentScreen = Screen::StaffDashboard;
                        break;
                    }
                }
                if (!found) loginFailed = true;

                if (loginFailed)
                    DrawText("User not found or wrong password!", 650, 700, 18, RED);
            }
            if (GuiButton({900, 650, 200, 40}, "Please - Register!!!!"))
                currentScreen = Screen::REGISTER;
        }

        else if (currentScreen == Screen::AdminDashboard) Admin_View(currentScreen);
        else if (currentScreen == Screen::CustomerDashboard) customer_view(currentScreen);
        else if (currentScreen == Screen::ManagerDashboard) Manager_view(currentScreen);
        else if (currentScreen == Screen::StaffDashboard) Staff_View(currentScreen);
        else if (currentScreen == Screen::REGISTER) Registration(currentScreen);

        DrawFPS(200, 200);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
