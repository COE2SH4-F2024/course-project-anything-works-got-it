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
    foodBucket = new foodBin();
}

GameMechs::GameMechs(int boardX, int boardY)
{
   
    input = 0 ;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    foodBucket = new foodBin();
    boardSizeX = boardX ;
    boardSizeY = boardY ;

}

// do you need a destructor?
GameMechs::~GameMechs()
{
    delete foodBucket;
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
void GameMechs::incrementScore5()
{
    score+=5;
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


void GameMechs::generateFood(objPosArrayList* snakebody)
{
   
   foodBucket->generateFood(boardSizeX,boardSizeY,snakebody); //  foodBucket of foodBin class calls the function to generate food inside GameMechs generateFood() function

} 

objPos GameMechs::getFoodpos(int i) const 
{ 
    return foodBucket->getFoodPos(i);
}
