#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    objPos initialPos(5, 5, '@');  // Starting position with '@' symbol
    playerPosList->insertHead(initialPos);
    // objPos otherbodypart(4,5,'@');
    // playerPosList->insertHead(otherbodypart);
    


    // more actions to be included
}


Player::~Player()
{
    delete playerPosList;
    // delete any heap members here
}

// void Player::getPlayerPos(objPos &returnPos) const
// {
//     // return the reference to the playerPos arrray list
// }

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList->getHeadElement();
}

objPosArrayList* Player::getplayerPosList() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{

        // PPA3 input processing logic
        char input = mainGameMechsRef->getInput();
        switch (input) {
            case 'w':  // UP
                if (myDir == LEFT || myDir == RIGHT || myDir == STOP) {
                    myDir = UP;
                }
                break;
            case 's':  // DOWN
                if (myDir == LEFT || myDir == RIGHT || myDir == STOP) {
                    myDir = DOWN;
                }
                break;
            case 'a':  // LEFT
                if (myDir == UP || myDir == DOWN || myDir == STOP) {
                    myDir = LEFT;
                }
                break;
            case 'd':  // RIGHT
                if (myDir == UP || myDir == DOWN || myDir == STOP) {
                    myDir = RIGHT;
                }
                break;   
            case ' ':  // Space to exit
                mainGameMechsRef->setExitTrue();
                break;
            // case 'f':
            //     mainGameMechsRef->generateFood(playerPos);
            //     break;
        }       
}

void Player::movePlayer()
{
    objPos currentHead = playerPosList->getHeadElement();
    int newX = currentHead.pos->x;
    int newY = currentHead.pos->y;
    int flag = 0;


    switch (myDir) {
        case UP:
            newY--;
            if (newY < 1) {
                newY = mainGameMechsRef->getBoardSizeY() - 2;  // Wraparound for top
            }
            break;
        case DOWN:
            newY++;
            if (newY > mainGameMechsRef->getBoardSizeY() - 2) {
                newY = 1;  // Wraparound for bottom
            }
            break;
        case LEFT:
            newX--;
            if (newX < 1) {
                newX = mainGameMechsRef->getBoardSizeX() - 2;  // Wraparound for left
            }
            break;
        case RIGHT:
            newX++;
            if (newX > mainGameMechsRef->getBoardSizeX() - 2) {
                newX = 1;  // Wraparound for right
            }
            break;
        default:
            // Do nothing; the player remains stationary
            break;
    }



    if (checkselfcollision()) {
        // Collision detected: set lose and exit flags
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }
    else
    {
        objPos newPos(newX, newY, '@');

    // Check for collision with food
    //objPos* foodPos = mainGameMechsRef->getFoodpos();
    for (int i = 0; i<5; i++){
    if (newX == mainGameMechsRef->getFoodpos(i).pos->x && newY == mainGameMechsRef->getFoodpos(i).pos->y) {
        // Eat the food: Insert new head, don't remove tail
        
        // if eat normal food
        if (mainGameMechsRef->getFoodpos(i).getSymbol() == '*'){
            playerPosList->insertHead(newPos);
            mainGameMechsRef->incrementScore();
        }
        else{ // if eat special food
            playerPosList->insertHead(newPos);
            playerPosList->removeTail();
            mainGameMechsRef->incrementScore5();
        }
        // Generate new food
        mainGameMechsRef->generateFood(playerPosList);
        flag = 1;
    } 
    }
    if (!flag) {
        // Regular movement: Insert new head, remove tail
        playerPosList->insertHead(newPos);
        playerPosList->removeTail();
    }
    
    }

}

bool Player::checkselfcollision()
{
    // Get the head position
    objPos head = playerPosList->getHeadElement();

    // Iterate through the body segments starting from index 1
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        objPos segment = playerPosList->getElement(i);

        if (head.pos->x == segment.pos->x && head.pos->y == segment.pos->y)
        {
            return true; // Collision detected
        }
    }
    return false; // No collision
}

// More methods to be added