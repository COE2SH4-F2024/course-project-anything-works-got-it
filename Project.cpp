#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

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

    game = new GameMechs();
    player1 = new Player(game);
    //game->generateFood(player1->getPlayerPos());
    game->generateFood(player1->getplayerPosList());
    

    exitFlag = false;
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
    //srand(time(NULL));

    player1->updatePlayerDir();
    player1->movePlayer();
    

    
}

void DrawScreen(void)
{
    // objPos playerposition = player1->getPlayerPos();
    // objPos player1copy = playerposition.getObjPos();
    // objPos foodposition = game->getFoodpos();
    // objPos foodcopy = foodposition.getObjPos();

    // objPosArrayList* playerlist = player1->getplayerPosList();

    // MacUILib_clearScreen();  

    // for(int i = 0 ; i < game->getBoardSizeY();i++){

    //     for(int j = 0 ; j < game->getBoardSizeX(); j++){
            
    //         if ( i == 0 || i == game->getBoardSizeY()-1 || j ==0 || j == game->getBoardSizeX()-1 )

    //         {MacUILib_printf("#");}

    //         else if(i == player1copy.pos->y && j == player1copy.pos->x){

    //             MacUILib_printf("%c",player1copy.symbol);
    //         }

    //         else if( i == foodcopy.pos->y && j == foodcopy.pos->x ){

    //             MacUILib_printf("%c",foodcopy.symbol);
    //         }

    //         else
    //         {

    //             MacUILib_printf(" ");

    //         }
    //     }
    //     MacUILib_printf("\n");
    // }

    objPos foodcopy = game->getFoodpos();

    MacUILib_clearScreen();  

    objPosArrayList* playerList = player1->getplayerPosList();

    for(int i = 0; i < game->getBoardSizeY(); i++) {  // Y-axis (rows)
        for(int j = 0; j < game->getBoardSizeX(); j++) {  // X-axis (columns)
            if (i == 0 || i == game->getBoardSizeY() - 1 || j == 0 || j == game->getBoardSizeX() - 1) {
                MacUILib_printf("#");
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
                    if(i == foodcopy.pos->y && j == foodcopy.pos->x){
                        MacUILib_printf("%c", foodcopy.symbol);
                        printed = true;
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
    MacUILib_printf("WASD are the controls");
      
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}