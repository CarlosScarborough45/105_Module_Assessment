#include <iostream>
#include "raylib.h"
#include <vector>
#include <string>
#include "Global.h"

// =============================================
// Food item structure
// =============================================
struct FoodItem {
    std::string name;
    float price;
    int quantity; // how many are in the cart
};

int main() {
    InitWindow(1500, 850, "Eats & Treats");
    SetTargetFPS(60);

    User u;
    User* loggedIn = nullptr;

    // =============================================
    // Users
    // =============================================
    std::vector<User> users = {
        {"Carlos45", "DavidandCarlos", "27", "Carlos", "Scarborough"},
        {"john99",   "mypassword",     "25", "John",   "Doe"        }
    };

    // =============================================
    // Menu items
    // =============================================
    std::vector<FoodItem> menu = {
        {"Cheeseburger",      12.50, 0},
        {"Chicken Wrap",      11.00, 0},
        {"Veggie Burger",     10.50, 0},
        {"Loaded Fries",       7.00, 0},
        {"Onion Rings",        5.50, 0},
        {"Garden Salad",       8.00, 0},
        {"Chocolate Shake",    6.50, 0},
        {"Lemonade",           4.00, 0},
        {"Cola",               3.00, 0},
        {"Cheesecake Slice",   7.50, 0},
        {"Brownie",            5.00, 0},
        {"Ice Cream Cup",      4.50, 0},
    };

    // 0 = login screen, 1 = menu screen
    int currentScreen = 0;

    std::string errorMsg = "";

    // Login screen rectangles
    Rectangle usernamebox = {};

    while (!WindowShouldClose()) {
        //======================================================================//
        //============================= DRAWING ================================//
        //====================================================================//
        BeginDrawing();
        ClearBackground({0, 255, 255, 255});

            DrawText("Welcome to\nEats & Treats", 20, 220, 40, {10, 61, 92, 255});

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