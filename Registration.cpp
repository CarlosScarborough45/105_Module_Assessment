#include "Headers/Global.h"
#include "raylib.h"
#include "Headers/Screens.h"
#include "raygui.h"

bool TextBox000EditMode = false;
char TextBox000Text[128] = "FIrst Name";
bool TextBox001EditMode = false;
char TextBox001Text[128] = "Last Name";
bool TextBox002EditMode = false;
char TextBox002Text[128] = "Age";
bool TextBox003EditMode = false;
char TextBox003Text[128] = "Email";
bool TextBox004EditMode = false;
char TextBox004Text[128] = "Password";

void Registration(Screen screen)
{
        ClearBackground({0, 255, 255, 255});

        DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255}); // dark sidebar
        DrawText("Registration", 620, 80, 38, {10, 61, 92, 255});
        DrawText("\n\n Welcome to \n\n\n Eats & Treats", 20, 220, 40, WHITE);

        if (GuiTextBox((Rectangle){ 620, 200,  500, 60}, TextBox000Text, 200, TextBox000EditMode)) TextBox000EditMode = !TextBox000EditMode;
        if (GuiTextBox((Rectangle){ 620, 240,  500, 60}, TextBox001Text, 200, TextBox001EditMode)) TextBox001EditMode = !TextBox001EditMode;
        if (GuiTextBox((Rectangle){ 620, 280, 500, 60}, TextBox002Text, 200, TextBox002EditMode)) TextBox002EditMode = !TextBox002EditMode;
        if (GuiTextBox((Rectangle){ 620, 320, 500, 60}, TextBox003Text, 200, TextBox003EditMode)) TextBox003EditMode = !TextBox003EditMode;
        if (GuiTextBox((Rectangle){ 620, 360, 500, 60}, TextBox004Text, 200, TextBox004EditMode)) TextBox004EditMode = !TextBox004EditMode;

        if (GuiButton((Rectangle){650, 600, 200, 40}, "SIGN - IN")) {
                currentScreen = Screen::LOGIN;
        }
        else if (currentScreen == Screen::LOGIN) {
                Dashboard(currentScreen);
        }
}