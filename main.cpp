
#include "raylib.h"


int main() {
    InitWindow(1500, 850, "Eats & Treats");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        //======================================================================//
        //============================= DRAWING ================================//
        //====================================================================//
        BeginDrawing();
        ClearBackground({0, 255, 255, 255});

            DrawText("Welcome to \n\n\n Eats & Treats", 20, 220, 40, {10, 61, 92, 255});

            // Title
            DrawText("Welcome to your login", 620, 130, 38, {10, 61, 92, 255});
            DrawText("Sign into your Account", 700, 200, 20, {10, 61, 92, 255});

            // Username box
            DrawText("UserName", 650, 320, 20, {74, 122, 150, 255});
            DrawRectangle(650, 350, 350, 45, {255, 255, 255, 255});


            // Password box
            DrawText("Password", 650, 520, 20, {74, 122, 150, 255});
            DrawRectangle(650, 550, 350, 45, {255, 255, 255, 255});




        EndDrawing();
    }

    CloseWindow();
    return 0;
}