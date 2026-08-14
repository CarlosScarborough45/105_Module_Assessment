#include "Menu.h"

Menu Menu::M;

Menulist Menulist::ml;

Menu::Menu(const char *str, const char *text, const char *lunch, double x, bool cond) {
    ITemID = str;
    Name = text;
    category = lunch;
    price = x;
    available = cond;
}
