#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include <time.h>
using namespace std;

#define DELAY_CONST 100000

GameMechs *game;
Player* player1;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    srand(time(NULL));

    game = new GameMechs(50,20);
    player1 = new Player(game);
    game->generateFood(player1->getplayerPosList());

}

void GetInput(void)
{
   char input;
    if (MacUILib_hasChar()) {
        input = MacUILib_getChar();
        game->setInput(input);  // Use a method in GameMechs
    }
}

void RunLogic(void)
{


    player1->updatePlayerDir();
    player1->movePlayer();

    
}

void DrawScreen(void)
{
   
    MacUILib_clearScreen();  

    objPosArrayList* playerList = player1->getplayerPosList(); 
    for(int i = 0; i < game->getBoardSizeY(); i++) {  // Y-axis (rows)
        for(int j = 0; j < game->getBoardSizeX(); j++) {  // X-axis (columns)
            if (i == 0 || i == game->getBoardSizeY() - 1 || j == 0 || j == game->getBoardSizeX() - 1) {
                MacUILib_printf("#"); // draw the game board
            }
            else {
                bool printed = false;

                // Iterate through the player position list
                for(int k = 0; k < playerList->getSize(); k++) {
                    objPos segment = playerList->getElement(k);
                    if(i == segment.pos->y && j == segment.pos->x) {
                        MacUILib_printf("%c", segment.symbol);
                        printed = true;
                        break;
                    }
                }

                // Check if the current position is food
                if(!printed) {
                    for (int k = 0; k < 5; k++ ){
                    if(i == game->getFoodpos(k).pos->y && j == game->getFoodpos(k).pos->x){
                        MacUILib_printf("%c", game->getFoodpos(k).symbol);
                        printed = true;
                        }
                    }
                    
                }

                // If nothing is printed, print a space
                if(!printed) {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\nControls: W  A  S  D");
    MacUILib_printf("\nHit Space Button to stop the game");
    MacUILib_printf("\nScore: %d", game->getScore());
    MacUILib_printf("\n\n");
    MacUILib_printf("**Report**");
    for (int z = 0; z < 5; z++){
    MacUILib_printf("\nFruit %d Position: [%d, %d]",z+1,game->getFoodpos(z).pos->x,game->getFoodpos(z).pos->y);
    }
    if (game->getExitFlagStatus() && game->getLoseFlagStatus() != true){
        MacUILib_printf("\n\nYour Final Score is %d", game->getScore());
        MacUILib_printf("\n********************");
        MacUILib_printf("\nThank you for playing!");
        MacUILib_printf("\n********************");
    }

    else if(game->getLoseFlagStatus()){
        MacUILib_printf("\n\nBetter Luck Next Time");
        MacUILib_printf("\nYour Final Score is %d", game->getScore());
        MacUILib_printf("\n********************");
        MacUILib_printf("\nThank you for playing!");
        MacUILib_printf("\n********************");
    }


      
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    

    MacUILib_uninit();
}