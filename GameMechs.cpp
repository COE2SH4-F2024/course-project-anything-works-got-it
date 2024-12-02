#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0 ;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    food = new objPos[5];
    boardSizeX = 30 ;
    boardSizeY = 15 ;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
   
    input = 0 ;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    food = new objPos[5];

    boardSizeX = boardX ;
    boardSizeY = boardY ;

}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //delete[] food;
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
    int copyX = 0, copyY = 0;
    bool invalidPosition;
    
    for (int i = 0; i < 5; i++){
    do {
        invalidPosition = false;

        // Generate random coordinates
        
        foodX = rand() % boardSizeX;
        foodY = rand() % boardSizeY;

        // Check if position is on border
        if (foodX == 0 || foodX == boardSizeX - 1 ||
            foodY == 0 || foodY == boardSizeY - 1) {
            invalidPosition = true;
        } 
        else if (foodX == copyX && foodY == copyY){
            invalidPosition = true;
        }
        else {
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

     food[i].setObjPos(foodX, foodY, '*');
     copyX = foodX;
     copyY = foodY; 
    }

   // foodBucket.generateFood(boardSizeX,boardSizeY,snakebody);

   

} 

// objPos GameMechs::getFoodpos(int i) const 
// {
//     foodBucket.getFoodPos(i);
// }
objPos* GameMechs::getFoodpos() const 
{ 
    return food;
}
