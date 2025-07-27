# 🐍 Snake Game (Simple C Version)
A simple console-based Snake game written in pure C language, designed to run on Windows. It uses conio.h to detect real-time keyboard input.

## 🎮 Controls
W: Move Up
A: Move Left
S: Move Down
D: Move Right
P: Pause / Resume
X: Exit Game

- Each time you eat a food, you get +10 points and your movement speed increases.
- You can't hit the wall or yourself.

## 💻 Environment
Language: C (ANSI C)
Compiler: GCC (MinGW or TDM-GCC recommended)
IDE: Code::Blocks or any C-compatible IDE
Platform: Windows (uses windows.h and conio.h)

## 🧱 Project Structure

Snake/
├── Snake.c // Main program
├── Snake.cbp // Code::Blocks project file
├── README.md // Project description
└── .gitignore // Git ignore files

## 📦 Features
Snake grows after eating food
Speed increases as the game progresses
Wall collision detection
Self-collision detection
Pause functionality
Real-time keyboard input

## 🔧 Build Instructions
You need a GCC compiler (like [MinGW](https://www.mingw-w64.org/)) installed and available in your system `PATH`.

## 🚀 Run Instructions
Option 1: Compile with Code::Blocks
  Open the .cbp project file and press F9 to build and run.
Option 2: Compile with GCC manually
  bash
  gcc snake.c -o snake.exe
  ./snake.exe
