#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Game area size
#define W 20
#define H 20

// Global variables
int snakeX, snakeY;       // Snake head position
int foodX, foodY;         // Food position
int tailX[50], tailY[50]; // Snake body position
int tailLen;              // Snake body length
int dir;                  // Directions: 1left 2right 3up 4down
int score;                // Scord
int gameOver;             // Game over sign

// Initialize
void setup() {
    snakeX = W / 2;
    snakeY = H / 2;
    foodX = rand() % W;
    foodY = rand() % H;
    tailLen = 0;
    dir = 0;
    score = 0;
    gameOver = 0;
}

// Picture
void draw() {
    system("cls");  // Clear screen
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            
            // Draw walls
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                printf("#");
            }
            // Draw snake head
            else if (i == snakeY && j == snakeX) {
                printf("O");
            }
            // Draw food
            else if (i == foodY && j == foodX) {
                printf("F");
            }
            // Draw snake body
            else {
                int isBody = 0;
                for (int k = 0; k < tailLen; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        isBody = 1;
                        break;
                    }
                }
                if (!isBody) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// Input
void input() {
    if (_kbhit()) {
        char c = _getch();
        if (c == 'a') dir = 1;  // left
        if (c == 'd') dir = 2;  // right
        if (c == 'w') dir = 3;  // up
        if (c == 's') dir = 4;  // down
        if (c == 'x') gameOver = 1;  // Quit
    }
}

// Logic
void logic() {
    // The snake's body followed the snake's head
    for (int i = tailLen - 1; i > 0; i--) {
        tailX[i] = tailX[i-1];
        tailY[i] = tailY[i-1];
    }
    if (tailLen > 0) {
        tailX[0] = snakeX;
        tailY[0] = snakeY;
    }
    
    // Move snake head
    if (dir == 1) snakeX--;
    if (dir == 2) snakeX++;
    if (dir == 3) snakeY--;
    if (dir == 4) snakeY++;
    
    // Death by hitting a wall
    if (snakeX <= 0 || snakeX >= W-1 || snakeY <= 0 || snakeY >= H-1) {
        gameOver = 1;
    }
    
    // He died from hitting itself
    for (int i = 0; i < tailLen; i++) {
        if (tailX[i] == snakeX && tailY[i] == snakeY) {
            gameOver = 1;
        }
    }
    
    // Eat food
    if (snakeX == foodX && snakeY == foodY) {
        score += 10;
        tailLen++;
        foodX = rand() % (W-2) + 1;  // Food cannot be on the wall
        foodY = rand() % (H-2) + 1;
    }
}

int main() {
    setup();
    
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(200);  // Speed
    }
    
    printf("Game Over! Score: %d\n", score);
    system("pause");
    return 0;
}
