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
       
        foodBin* foodBucket; // foodBin class is considered to be one of the members in GameMechs
    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); 
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();
        
        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        // the special function for incrementing score by 5 if the snake hits special food '+'
        void incrementScore5();


        void generateFood(objPosArrayList* snakebody);
       


        objPos getFoodpos(int) const ;
};

#endif