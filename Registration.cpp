#include "Headers/Global.h"
#include "raylib.h"
#include "Headers/Screens.h"
#include "raygui.h"
#include <iostream>

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


void Registration(Screen screen)
{
    ClearBackground({0, 255, 255, 255});
    DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255}); // dark sidebar
    DrawText("Registration", 620, 80, 38, {10, 61, 92, 255});
    DrawText("\n\n Welcome to \n\n\n Registration", 20, 220, 40, WHITE);

    if (GuiTextBox({650, 200, 350, 45,}, TextBox000Text, 128, TextBox000EditMode))
        TextBox000EditMode = !TextBox000EditMode;


    if (GuiTextBox({650, 300, 350, 45}, TextBox001Text, 128, TextBox001EditMode))
        TextBox001EditMode = !TextBox001EditMode;

    if (GuiTextBox({650, 400, 350, 45}, TextBox002Text, 128, TextBox002EditMode))
        TextBox002EditMode = !TextBox002EditMode;

    if (GuiTextBox({650, 500, 350, 45}, TextBox003Text, 128, TextBox003EditMode))
        TextBox003EditMode = !TextBox003EditMode;

    if (GuiDropdownBox({650, 600, 200, 40}, "Admin; Customer; Manager; Staff", &selectedRole, dropdown))
    {
        dropdown = !dropdown;
    }

    if (GuiButton((Rectangle){900, 600, 200, 40}, "SIGN - IN"))
    {
        currentScreen = Screen::LOGIN;
    }
}

