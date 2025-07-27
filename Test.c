#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    for (int i = 0; i <= 1000; i++) {
        gotoxy(0, 0);
        printf("Number: %d", i);
        Sleep(50);
    }
    return 0;
}

