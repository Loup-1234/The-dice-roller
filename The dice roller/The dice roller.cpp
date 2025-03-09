#define _CRT_SECURE_NO_WARNINGS
#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "raygui.h"

#include <string>

using namespace std;

int main()
{
    InitWindow(390, 225, "The dice roller");

    Image icon = LoadImage("dice-multiple.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    int number = 100;
    int max = 100;

    while (!WindowShouldClose())
    {
        GuiLoadStyle("style_cyber.rgs");

        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        GuiDrawText(to_string(number).c_str(), Rectangle{ 5, 5, 380, 50 }, 1, GetColor(GuiGetStyle(DEFAULT, TEXT)));

        GuiSpinner(Rectangle{ 5, 60, 380, 50 }, NULL, &max, 1, 100, false);

        if (GuiButton(Rectangle{ 5, 115, 50, 50 }, "4"))
        {
            max = 4;
        }

        if (GuiButton(Rectangle{ 60, 115, 50, 50 }, "6"))
        {
            max = 6;
        }

        if (GuiButton(Rectangle{ 115, 115, 50, 50 }, "8"))
        {
            max = 8;
        }

        if (GuiButton(Rectangle{ 170, 115, 50, 50 }, "10"))
        {
            max = 10;
        }

        if (GuiButton(Rectangle{ 225, 115, 50, 50 }, "12"))
        {
            max = 12;
        }

        if (GuiButton(Rectangle{ 280, 115, 50, 50 }, "20"))
        {
            max = 20;
        }

        if (GuiButton(Rectangle{ 335, 115, 50, 50 }, "100"))
        {
            max = 100;
        }

        if (GuiButton(Rectangle{ 5, 170, 380, 50 }, "Roll"))
        {
            number = rand() % (max)+1;
        }

        EndDrawing();
    }

    CloseWindow();
}