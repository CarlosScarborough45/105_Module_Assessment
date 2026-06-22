#include "raylib.h"
#include "Headers/Screens.h"
#include "raygui.h"

static bool logouttext = false;

static float logouttimer = 0.0f;

int activefield = 0;


void Staff_View(Screen screen)
{
    ClearBackground({0, 255, 255, 255});
    DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});
    DrawText("\n\n Welcome \n\n\n Staff", 20, 220, 40, WHITE);

    if (GuiButton((Rectangle){300, 330, 100, 100}, "Orders")) activefield = 1;
    if (GuiButton((Rectangle){300, 450, 100, 100}, "Menu")) activefield = 2;
    if (GuiButton((Rectangle){300, 570, 100, 100}, "Tables")) activefield = 3;
    if (GuiButton((Rectangle){300, 700, 100, 100}, "Reservations")) activefield = 4;

    switch (activefield)
    {
    case 1: { break; }
    case 2: { break; }
    case 3: { break; }
    case 4: { break; }
    }

    //======================= Logout ===================================//

    if (GuiButton((Rectangle){900, 600, 200, 40}, "Return to Menu"))
    {
        logouttext = true;
        logouttimer = 1.5f;
    }

    else if (logouttext)
    {
        DrawText("YOU ARE LOGGING OUT!!!!!", 650, 320, 20, {74, 122, 150, 255});
        logouttimer -= GetFrameTime();

        if (logouttimer <= 0.0f)
        {
            logouttext = false;
            currentScreen = Screen::LOGIN;
        }
    }
}
