#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0 ;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30 ;
    boardSizeY = 15 ;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0 ;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX ;
    boardSizeY = boardY ;

}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //not right now 
}

bool GameMechs::getExitFlagStatus() const
{

    return exitFlag;

}

bool GameMechs::getLoseFlagStatus() const
{

    return loseFlag;

}
    

char GameMechs::getInput() 
{
    return input;
}

int GameMechs::getScore() const
{

    return score;

}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{

    exitFlag = true;

}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{

    input = 0;

}

// More methods should be added here

void GameMechs::generateFood(objPosArrayList* snakebody)
{
   
    // int foodX, foodY;

    // do {
    //     // Generate random coordinates within the board bounds
    //     foodX = rand() % boardSizeX;
    //     foodY = rand() % boardSizeY;

    //     // Ensure the position is not a border
    //     if (foodX == 0 || foodX == boardSizeX - 1 ||
    //         foodY == 0 || foodY == boardSizeY - 1) {
    //         continue; // Skip border positions
    //     }

    // } while (foodX == blockOff.pos->x && foodY == blockOff.pos->y);

    // // Set food position and symbol
    // food.setObjPos(foodX, foodY, '*');

    int foodX, foodY;
    bool invalidPosition;

    do {
        invalidPosition = false;

        // Generate random coordinates
        foodX = rand() % boardSizeX;
        foodY = rand() % boardSizeY;

        // Check if position is on border
        if (foodX == 0 || foodX == boardSizeX - 1 ||
            foodY == 0 || foodY == boardSizeY - 1) {
            invalidPosition = true;
        } else {
            // Check for overlap with snake body
            for (int i = 0; i < snakebody->getSize(); i++) {
                objPos segment = snakebody->getElement(i);
                if (foodX == segment.pos->x && foodY == segment.pos->y) {
                    invalidPosition = true;
                    break;
                }
            }
        }
    } while (invalidPosition);

    // Set new food position
    food.setObjPos(foodX, foodY, '*');

} 

objPos GameMechs::getFoodpos() const 
{
    return food;
}