
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // 用 _kbhit 和 _getch
#include <windows.h> // 用 Sleep


#define WIDTH 20
#define HEIGHT 20
#define MAX_LEN 100
int x, y;                 // 蛇头坐标
int fruitX, fruitY;       // 食物坐标
int score;
int gameOver;
int dir;                  // 1左 2右 3上 4下
int tailX[MAX_LEN], tailY[MAX_LEN];  // 身体每一节的坐标
int tailLen = 0;          // 当前长度

int delay = 200;
int paused = 0;

void Setup() {
    gameOver = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}

void Draw() {
    system("cls");  // 清屏
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");
            if (i == y && j == x) printf("O");        // 蛇头
            else if (i == fruitY && j == fruitX) printf("F");  // 食物
            else printf(" ");
            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = 1;
            break;
        case 'd':
            dir = 2;
            break;
        case 'w':
            dir = 3;
            break;
        case 's':
            dir = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void Logic() {
    switch (dir) {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    }

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameOver = 1;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
}


int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);  // 控制速度
    }
    printf("Game Over!\n");
    return 0;
}

