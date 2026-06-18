#include "raylib.h"
#include "Screens.h"

void Dashboard(Screen screen)
{
    switch (currentScreen)
    {
    case Screen::LOGIN: ; break;
    case Screen::REGISTER: Registration(currentScreen); break;
    }
        BeginDrawing();

        ClearBackground({0, 255, 255, 255});
        DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});

        DrawText(" Welcome to \n\n\n Eat & Treats ", 20, 220, 40, WHITE);

        EndDrawing();
}
