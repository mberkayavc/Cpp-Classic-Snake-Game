# Classic Snake Game in C++

This repository contains a basic implementation of the classic Snake Game in C++ using the `conio.h` and `windows.h` libraries. The game allows the player to control a snake that grows longer as it eats fruits while avoiding walls and its own tail. The player can choose between three difficulty levels and control the snake using the keyboard.

# Game Features

- **Snake Movement**: The snake moves using the `w` (up), `a` (left), `s` (down), and `d` (right) keys.
- **Difficulty Levels**: Players can choose between Easy, Medium, and Hard difficulty, affecting the speed of the snake.
- **Score System**: The player earns 10 points for each fruit consumed. The score is displayed after each game frame.
- **Tail Growth**: The snake grows longer as it consumes fruits, making the game progressively more challenging.
- **Game Over Conditions**: The game ends when the snake hits a wall or bites its own tail.

## Controls
```w``` - Move up
```a``` - Move left
```s``` - Move down
```d``` - Move right
```x``` - Exit the game

# Game Overview
The objective is simple: guide the snake to eat fruits that randomly appear on the screen. 
Every time the snake eats a fruit, it grows longer, and the player's score increases. 
The player loses the game if the snake crashes into the walls or bites its own tail.

# Game Loop
The game starts by asking for the player's name and preferred difficulty level ```(Easy, Medium, or Hard)```.
The snake starts moving once the player presses a direction key ```(w, a, s, or d)```.
The game updates the snake's position, renders the game board, checks for collisions, and tracks the ```player's score```.
If the snake hits a wall or its own tail, the game ends, and the player can try again.

# Code Overview

## Global Variables
 ```width, height: ```  Dimensions of the game board.
 
```x, y:``` Current position of the snake's head.

```fruitCordX, fruitCordY:``` Position of the fruit on the board.

```playerScore:``` The player's current score.

```snakeTailX, snakeTailY:``` Arrays storing the position of the snake's tail.

```lenTail:``` Length of the snake's tail.

```sDir:``` Enum representing the direction of the snake's movement.

```isGameOver:``` Boolean flag to track whether the game has ended.

## Key Functions
```setGame():``` Initializes the game state, including the snake's position, the fruit's position, and resetting the score.

```GameRender():``` Renders the game board, including the walls, snake, and fruit, and displays the player's score.

```UpdateGame():``` Updates the snake's position, checks for collisions with walls or its tail, and increases the snake's length when it eats a fruit.

```SetDifficulty():``` Allows the player to choose a difficulty level that controls the speed of the game.

```UserInput():``` Captures and handles the player's keyboard input to move the snake.

### Prerequisites

- A C++ compiler (GCC, Clang, MSVC, etc.)
- Visual Studio Code or any other IDE
- The game uses platform-specific libraries (`conio.h` and `windows.h`), so it's best run on Windows.

### Compiling and Running

1. Clone or download the repository:
   ```bash
   git clone https://github.com/yourusername/snake-game-cpp.git
   cd snake-game-cpp
