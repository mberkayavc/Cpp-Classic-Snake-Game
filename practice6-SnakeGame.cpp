#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std ;

/*

### It's a basic Snake Game Program in C++

# What we are going to do first ?

Rules
-Don't hit a wall and don't bite your own tail.
-Crashing to them will end the game and asks "Try Again"
-10 points will be added to player's score for eating
the fruit and the length of the snake will be increased after
eating the fruits.
-We are going to use w,a,s,d buttons to move up,left,down and 
right.

*/

/*

###STEPS:

1. Setting up the project
2. Including necessary libs
3. Defining Global variables for the game
4. Initializing the game
5. Creating game board cum game rendering function
6. Uptading the game state
7. Setting the game difficulty
8. Hangling user input
9. Creating main function

*/


/* Global Variables */

//Board width and Height
const int width = 80;
const int height = 20;

//Snake Position
int x,y;

//Fruit Position
int fruitCordX, fruitCordY;

//Variable to store the score of player
int playerScore;

//Creating array to store the coordinates of snake tail
// x and y both
int snakeTailX[100], snakeTailY[100];

//Storing the length of the snake's tail
int lenTail;

//Moving Direction
enum snakesDirection { STOP = 0 , LEFT , RIGHT , UP , DOWN
};

// snakesDirection variable
snakesDirection sDir;

//Boolean for checking game is over or not 1  or 0
bool isGameOver;

/* Functions */

//Function for initializing the Game

void setGame(){

    isGameOver = false; //Game hasn't ended yet
    sDir = STOP; //Snake is not moving at start
    
    //Put the snake into the middle of the board
    x = width / 2;
    y = height / 2;

    //Random position for fruit
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;

    //At the start, score and tail are zero
    playerScore = 0;
}


void GameRender(string playerName)
{
    system("cls"); // Clear the console

    // Creating top walls with '-'
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            // Creating side walls with '|'
            if (j == 0 || j == width)
                cout << "|";
            // Creating snake's head with 'O'
            if (i == y && j == x)
                cout << "O";
            // Creating the sanke's food with '#'
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#";
            // Creating snake's head with 'O'
            else {
                bool prTail = false;
                for (int k = 0; k < lenTail; k++) {
                    if (snakeTailX[k] == j
                        && snakeTailY[k] == i) {
                        cout << "o";
                        prTail = true;
                    }
                }
                if (!prTail)
                    cout << " ";
            }
        }
        cout << endl;
    }

    // Creating bottom walls with '-'
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    // Display player's score
    cout << playerName << "'s Score: " << playerScore << endl;
}

//Function for updating game scale
void UpdateGame()
{

    int lastX = snakeTailX[0];
    int lastY = snakeTailY[0];

    int last2X, last2Y;
    
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for(int i = 1; i < lenTail; i++){
        last2X = snakeTailX[i];
        last2Y = snakeTailY[i];

        lastX = last2X;
        last2Y = lastY;
    }

    switch (sDir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;    
    }

//Now, checking collisions and updating game
//there are two collisions here, wall and snake's circles

//Checks for snake's collision with the wall x and y axis
    if (x >= width || x < 0 || y >= height || y < 0)
    {
        isGameOver = true;
    }
    
//Checks for collision with the tail (o)
    for (int i = 0 ; i < lenTail ; i++){
        if(snakeTailX[i] == x && snakeTailY[i] == y){
            isGameOver = true;
        }
    }

//Checks for collision with the food (F)

    if(x == fruitCordX && y == fruitCordY){
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;

        lenTail++;
    }
}

//Funcion to set the game difficulty

int SetDifficulty(){

    int difficulty;
    int choice;

    cout <<"\n"<<"SET DIFFICULTY LEVEL"<<"\n"<<"1: Easy"<<"\n"<<"2: Medium"<<"\n"<<"3: Hard";
    cout << "\n";
    cout<<": if not chosen or pressed any other key, the difficulty will be automatically set to medium";
    cout<< "\n"<<"Choose difficulty level: ";

    cin >> choice;

    switch (choice)
    {
    case '1':
        difficulty = 50;
        break;
    case '2':
        difficulty = 100;
        break;
    case '3':
        difficulty = 150;
        break;
    
    default:
        difficulty = 100;
        break;
    }
    return difficulty;
}

void UserInput(){

    //_kbhit and _getch using
    if(_kbhit()){

        switch (_getch())
        {
        case  'a':
            sDir = LEFT;
            break;
        
        case  'd':
            sDir = RIGHT;
            break;

        case  'w':
            sDir = UP;
            break;

        case  's':
            sDir = DOWN;
            break;

        case  'x':
            isGameOver = true;
            break;

        }
    }
}


int main(){

    string playerName;
    cout << "enter your name: ";
    cin >> playerName;
    int abc = SetDifficulty();

    setGame();

    while(!isGameOver){
        GameRender(playerName);
        UserInput();
        UpdateGame();
        //
        //
       Sleep(abc);

    }

    return 0;
}
