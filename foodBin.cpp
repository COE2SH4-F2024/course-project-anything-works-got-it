#include "foodBin.h"


foodBin::foodBin(){
    foodBucket = new objPosArrayList();
}

foodBin::~foodBin(){
    delete foodBucket;
}


void foodBin:: generateFood(int boardSizeX, int boardSizeY, objPosArrayList* snakebody){

    int foodX, foodY;
    int copyX = -1, copyY = -1;
    bool invalidPosition;
    int mysyticNumber = rand()%3 + 3; // randomly generate a number for the maximum number of ordinary food
    int referenceMap[boardSizeY][boardSizeX]={0};

    for (int i = 0; i < 5; i++){ // A total of 5 food will be generated and displayed on the board; number is preset

    do {
        invalidPosition = false;

        // Generate random coordinates
        
        foodX = rand() % (boardSizeX-2)+1;
        foodY = rand() % (boardSizeY-2)+1;

        // Check if position is on border
            // Check for overlap with snake body
        for (int i = 0; i < snakebody->getSize(); i++) {
                objPos segment = snakebody->getElement(i);
                if (foodX == segment.pos->x && foodY == segment.pos->y) {
                    invalidPosition = true;
                    break;
                }
            }
        if (referenceMap[foodY][foodX] == 1) invalidPosition = true;

    } while (invalidPosition);
    referenceMap[foodY][foodX] = 1; 
    if (i < mysyticNumber){ // generate normal food
     objPos newFood (foodX,foodY,'*');
     foodBucket->insertHead(newFood);
    }
    else{ // generate special food
     objPos newFood (foodX,foodY,'+');
     foodBucket->insertHead(newFood);
    }


    }

}

objPos foodBin:: getFoodPos(int i) const{

    return foodBucket->getElement(i);
} 
