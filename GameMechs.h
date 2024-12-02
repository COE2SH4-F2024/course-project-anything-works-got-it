#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include "objPosArrayList.h"
#include "objPos.h"
#include "foodBin.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;
       
        objPos* food;
        foodBin* foodBucket;
    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();
        // check
        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        void incrementScore5();


        void generateFood(objPosArrayList* snakebody);
       


        objPos getFoodpos(int) const ;
};

#endif