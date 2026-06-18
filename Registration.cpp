#include "Headers/Global.h"
#include "raylib.h"
#include "Headers/Screens.h"
#include "raygui.h"
#include <iostream>

//drop down state
bool dropdown = false;
int selectedRole = 0;


void Registration(Screen screen)
{
    ClearBackground({0, 255, 255, 255});
    DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255}); // dark sidebar
    DrawText("Registration", 620, 80, 38, {10, 61, 92, 255});
    DrawText("\n\n Welcome to \n\n\n Registration", 20, 220, 40, WHITE);

    DrawRectangle(650, 200, 350, 45, WHITE);
    DrawRectangle(650, 300, 350, 45, WHITE);
    DrawRectangle(650, 400, 350, 45, WHITE);
    DrawRectangle(650, 500, 350, 45, WHITE);

    if (GuiDropdownBox({650, 600, 200, 40}, "Admin; Customer; Manager; Staff", &selectedRole, dropdown))
    {
        dropdown = !dropdown;
    }

    if (GuiButton((Rectangle){900, 600, 200, 40}, "SIGN - IN"))
    {
        currentScreen = Screen::LOGIN;
    }
}

