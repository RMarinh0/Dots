#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void gotoxy(short x, short y)
{
    COORD cord;
    cord.X = x;
    cord.Y = y;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, cord);
}
