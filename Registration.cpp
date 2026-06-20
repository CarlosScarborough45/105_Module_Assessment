#include "Headers/Global.h"
#include "raylib.h"
#include "Headers/Screens.h"
#include "raygui.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//drop down state
bool dropdown = false;
int selectedRole = 0;

bool TextBox000EditMode = false;
char TextBox000Text[128] = "";
bool TextBox001EditMode = false;
char TextBox001Text[128] = "";
bool TextBox002EditMode = false;
char TextBox002Text[128] = "";
bool TextBox003EditMode = false;
char TextBox003Text[128] = "";
bool TextBox004EditMode = false;
char TextBox004Text[128] = "";

const char* roles[] = {"Admin", "Customer", "Manager", "Staff"};

void Registration(Screen screen)
{

    ClearBackground({0, 255, 255, 255});
    DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255}); // dark sidebar
    DrawText("Registration", 620, 80, 38, {10, 61, 92, 255});
    DrawText("\n\n Welcome to \n\n\n Registration", 20, 220, 40, WHITE);


        DrawText("First Name", 650, 160, 20,  BLACK);
    if (GuiTextBox({650, 200, 350, 45,}, TextBox000Text, 128, TextBox000EditMode))
        TextBox000EditMode = !TextBox000EditMode;

        DrawText("Last Name", 650, 270, 20,  BLACK);
    if (GuiTextBox({650, 300, 350, 45}, TextBox001Text, 128, TextBox001EditMode))
        TextBox001EditMode = !TextBox001EditMode;


        DrawText("UserName", 650, 370, 20,  BLACK);
    if (GuiTextBox({650, 400, 350, 45}, TextBox002Text, 128, TextBox002EditMode))
        TextBox002EditMode = !TextBox002EditMode;

        DrawText("Password", 650, 470, 20,  BLACK);
    if (GuiTextBox({650, 500, 350, 45}, TextBox003Text, 128, TextBox003EditMode))
        TextBox003EditMode = !TextBox003EditMode;


        DrawText("Age", 650, 570, 20,  BLACK);
    if (GuiTextBox({650, 600, 350, 45}, TextBox004Text, 128, TextBox004EditMode))
        TextBox004EditMode = !TextBox004EditMode;

    if (GuiDropdownBox({650, 650, 200, 40}, "Admin; Customer; Manager; Staff", &selectedRole, dropdown))
    {
        dropdown = !dropdown;
    }

    if (GuiButton((Rectangle){900, 650, 200, 40}, "Register!!!"))
    {

        std::ofstream file("../File/User.CSV", std::ios::app);

        if (!file.is_open()) {
            DrawText("Error Cannot open file to Save!!!!", 650, 640, 20, BLACK);
        }

        User newuser;

        newuser.Name = TextBox000Text;
        newuser.Lastname = TextBox001Text;
        newuser.username = TextBox002Text;
        newuser.Password = TextBox003Text;
        newuser.Age = TextBox004Text;
        newuser.Role = roles[selectedRole];

        users.push_back(newuser);

            file << std::left << std::setw(20)
                 << TextBox000Text << " | " << std::setw(20) << TextBox001Text << " | "
                 << std::setw(20) << TextBox002Text << " | "
                 << std::setw(20) << TextBox003Text << " | "
                 << std::setw(20) << TextBox004Text << " | "
                 << roles[selectedRole] << std::endl;

            file.close();

        currentScreen = Screen::LOGIN;
    }
}

