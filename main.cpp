#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "Headers/Screens.h"

int main() {
    InitWindow(1500, 850, "Eats & Treats");
    SetTargetFPS(64);

    while (!WindowShouldClose()) {

        BeginDrawing();

        if (currentScreen == Screen::LOGIN) {
            ClearBackground({0, 255, 255, 255});
            DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});
            DrawText("\n\n Welcome to \n\n\n Eats & Treats", 20, 220, 40, WHITE);
            DrawText("Welcome to your login", 620, 130, 38, {10, 61, 92, 255});
            DrawText("Sign into your Account", 700, 200, 20, {10, 61, 92, 255});
            DrawText("UserName", 650, 320, 20, {74, 122, 150, 255});
            DrawRectangle(650, 350, 350, 45, WHITE);
            DrawText("Password", 650, 520, 20, {74, 122, 150, 255});
            DrawRectangle(650, 550, 350, 45, WHITE);

            if (GuiButton((Rectangle){650, 600, 200, 40}, "SIGN - IN")) {
                currentScreen = Screen::DASHBOARD;
            }
            if (GuiButton((Rectangle){650, 650, 200, 40}, "Please - Register!!!!")) {
                currentScreen = Screen::REGISTER;
            }
                }
                else if (currentScreen == Screen::DASHBOARD) {
                    Dashboard(currentScreen);
                }
                else if (currentScreen == Screen::REGISTER) {
                    Registration(currentScreen);
                }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}