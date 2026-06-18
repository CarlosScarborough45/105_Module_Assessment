#ifndef INC_105_MODULE_ASSESSMENT_SCREENS_H
#define INC_105_MODULE_ASSESSMENT_SCREENS_H

enum class Screen {REGISTER, LOGIN, DASHBOARD, AdminDashboard, StaffDashboard, ManagerDashboard};

inline Screen currentScreen = Screen::LOGIN;

void Registration(Screen screen);

void Dashboard(Screen screen);

void Admin_View(Screen screen);

#endif //INC_105_MODULE_ASSESSMENT_SCREENS_H