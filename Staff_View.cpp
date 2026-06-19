#include "raylib.h"
#include "Headers/Screens.h"
#include "raygui.h"

void Staff_View(Screen screen)
{
    ClearBackground({0, 255, 255, 255});
    DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});
    DrawText("\n\n Welcome \n\n\n Staff", 20, 220, 40, WHITE);

    if (GuiButton((Rectangle){900, 600, 200, 40}, "Return to Menu"))
    {
        currentScreen = Screen::LOGIN;
    }
}
