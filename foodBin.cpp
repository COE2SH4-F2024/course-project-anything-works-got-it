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
    int mysyticNumber = rand()%3 + 3; // 0 to 2. + 3 shifts to right by 3 -> 3 to 5
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

    if (i < mysyticNumber){
     objPos newFood (foodX,foodY,'*');
     foodBucket->insertHead(newFood);
    }
    else{
     objPos newFood (foodX,foodY,'+');
     foodBucket->insertHead(newFood);
    }
     copyX = foodX;
     copyY = foodY; 
    }

}

objPos foodBin:: getFoodPos(int i) const{

    return foodBucket->getElement(i);
} 
