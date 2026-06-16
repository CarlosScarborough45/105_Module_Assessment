#include <iostream>
#include "raylib.h"

int main() {
	InitWindow(1500, 850, "Eats & Treats");
	SetTargetFPS(60);

	while (!WindowShouldClose()){

		BeginDrawing();
		DrawRectangle(0, -80, 2000, 250, BLUE);
		DrawText("Welcome to Eats and Treats Restaurant Management system", 200, 50, 35, RED);


		ClearBackground(WHITE);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
