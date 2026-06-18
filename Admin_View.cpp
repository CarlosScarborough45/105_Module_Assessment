#include <raygui.h>
#include "raylib.h"
#include "Headers/Screens.h"

void Admin_View(Screen screen)
{
    // int currentTab = 0;

    ClearBackground({0, 255, 255, 255});
    DrawRectangle(0, 0, 400, 900, {28, 40, 58, 255});
    DrawText("\n\n Welcome \n\n\n Admin", 20, 220, 40, WHITE);

    // if (GuiButton(Rectangle) {}, "Orders") currentTab = 0;
    // if (GuiButton(Rectangle) {}, "Menu") currentTab = 1;
    // if (GuiButton(Rectangle) {}, "Staff") currentTab = 2;
    // if (GuiButton(Rectangle) {}, "Report") currentTab = 3;
    //
    // switch (currentTab) {
    //
    //     case 0: {   break;}
    //     case 1: {   break;}
    //     case 2: {   break;}
    //     case 3: {   break;}
    // }
}
