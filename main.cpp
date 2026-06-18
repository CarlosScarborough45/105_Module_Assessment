#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include "Screens.h"

int main() {
    InitWindow(1500, 850, "Eats & Treats");
    SetTargetFPS(60);

    auto myflag = false;


    while (!WindowShouldClose()) {
        //======================================================================//
        //============================= DRAWING ================================//
        //====================================================================//

        if (currentScreen == Screen::LOGIN)
        {
            //Drawing logic
            BeginDrawing();
            ClearBackground({0, 255, 255, 255});
            DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});

            DrawText("Welcome to \n\n\n Eats & Treats", 20, 220, 40, WHITE);


            // Title
            DrawText("Welcome to your login", 620, 130, 38, {10, 61, 92, 255});
            DrawText("Sign into your Account", 700, 200, 20, {10, 61, 92, 255});

            // Username box
            DrawText("UserName", 650, 320, 20, {74, 122, 150, 255});
            DrawRectangle(650, 350, 350, 45, {255, 255, 255, 255});


            // Password box
            DrawText("Password", 650, 520, 20, {74, 122, 150, 255});
            DrawRectangle(650, 550, 350, 45, {255, 255, 255, 255});

            if (GuiButton((Rectangle){300, 340, 200, 40}, "SIGN - IN"))
            {
                currentScreen = Screen::DASHBOARD;
            }
        }
           else if (currentScreen == Screen::DASHBOARD)
            {
                Dashboard(currentScreen);
            }

            EndDrawing();

        }
    CloseWindow();
    return 0;
    }
