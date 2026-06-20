#ifndef INC_105_MODULE_ASSESSMENT_SCREENS_H
#define INC_105_MODULE_ASSESSMENT_SCREENS_H
#include <string>

#include "Global.h"

enum class Screen { REGISTER, LOGIN, DASHBOARD, AdminDashboard, StaffDashboard, ManagerDashboard, CustomerDashboard };

inline Screen currentScreen = Screen::LOGIN;

void Registration(Screen screen);

void Dashboard(Screen screen);

void Admin_View(Screen screen);

void customer_view(Screen screen);

void Manager_view(Screen screen);

void Staff_View(Screen screen);

#endif //INC_105_MODULE_ASSESSMENT_SCREENS_H
