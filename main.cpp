#include <iostream>
#include "raylib.h"

int main()
{
    InitWindow(800, 950, "Eat and Greet");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("Welcome to Eat and Greet", 50, 50, 50, BLACK);

        EndDrawing();
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
