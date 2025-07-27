#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_LEN 100

int x, y;  // Snake head coordinate
int fruitX, fruitY;
int score;
int gameOver;
int dir;  // A: Left D: Right W: Up S: Down
int tailX[MAX_LEN], tailY[MAX_LEN];
int tailLen = 0;

// Move the cursor
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hide the cursor
void hideCursor() {
    CONSOLE_CURSOR_INFO ci;
    ci.dwSize = 1;
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

// Initialise the game
void Setup() {
    gameOver = 0;
    dir = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    tailLen = 0;
}

// Draw the game interface
void Draw() {
    gotoxy(0, 0);
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");

            int printed = 0;
            if (i == y && j == x) {
                printf("O");  // Snake Head
                printed = 1;
            } else if (i == fruitY && j == fruitX) {
                printf("F");  // Food
                printed = 1;
            } else {
                for (int k = 0; k < tailLen; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");  // Snake body
                        printed = 1;
                        break;
                    }
                }
            }

            if (!printed) printf(" ");

            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

// Handling keyboard input
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': if (dir != 2) dir = 1; break;
            case 'd': if (dir != 1) dir = 2; break;
            case 'w': if (dir != 4) dir = 3; break;
            case 's': if (dir != 3) dir = 4; break;
            case 'x': gameOver = 1; break;
        }
    }
}

// Updat logic
void Logic() {
    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < tailLen; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case 1: x--; break;
        case 2: x++; break;
        case 3: y--; break;
        case 4: y++; break;
    }

    // Hit the wall
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameOver = 1;

    // Hit itself
    for (int i = 0; i < tailLen; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    // Get the food
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        tailLen++;
    }
}

// Main program
int main() {
    system("mode con: cols=40 lines=30"); // Set window
    hideCursor();
    Setup();

       for (int i = 0; i <= 1000; i++) {
        gotoxy(0, 0);
        printf("Number: %d", i);
        Sleep(50);
    }

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(200);  // Control the speed(the smaller the faster)
    }

    gotoxy(0, HEIGHT + 4);
    printf("Game Over!\nFinal Score: %d\n", score);
    system("pause");
    return 0;
}
