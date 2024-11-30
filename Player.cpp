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

    //Switch based on mydirection
    // switch (myDir) {
    //     case UP:
    //         playerPos.pos->y--;
    //         if (playerPos.pos->y < 1) {
    //             playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;  // Wraparound logic for top
    //         }
    //         break;
    //     case DOWN:
    //         playerPos.pos->y++;
    //         if (playerPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2) {
    //             playerPos.pos->y = 1;  // Wraparound logic for bottom
    //         }
    //         break;
    //     case LEFT:
    //         playerPos.pos->x--;
    //         if (playerPos.pos->x < 1) {
    //             playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;  // Wraparound logic for left
    //         }
    //         break;
    //     case RIGHT:
    //         playerPos.pos->x++;
    //         if (playerPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2) {
    //             playerPos.pos->x = 1;  // Wraparound logic for right
    //         }
    //         break;
    //     default:
    //         // Do nothing; the player remains stationary
    //         break;
    // }

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

    // Create new position and update the list
    // objPos newPos(newX, newY, '@');
    // Create new head position

    if (checkselfcollision()) {
        // Collision detected: set lose and exit flags
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }
    else
    {
        objPos newPos(newX, newY, '@');

    // Check for collision with food
    objPos foodPos = mainGameMechsRef->getFoodpos();
    if (newX == foodPos.pos->x && newY == foodPos.pos->y) {
        // Eat the food: Insert new head, don't remove tail
        playerPosList->insertHead(newPos);

        // Generate new food
        mainGameMechsRef->generateFood(playerPosList);
    } else {
        // Regular movement: Insert new head, remove tail
        playerPosList->insertHead(newPos);
        playerPosList->removeTail();
    }

    }

    // playerPosList->insertHead(newPos);
    // playerPosList->removeTail();
    // PPA3 Finite State Machine logic
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