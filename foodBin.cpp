#include "foodBin.h"


foodBin::foodBin(){
    foodBucket = new objPosArrayList();
}

foodBin::~foodBin(){
    delete foodBucket;
}


void foodBin:: generateFood(int boardSizeX, int boardSizeY, objPosArrayList* snakebody){

    int foodX, foodY;
    int copyX = 0, copyY = 0;
    bool invalidPosition;
    objPos emptyFood;

    for (int i = 0; i < 5; i++){
    foodBucket->insertHead(emptyFood);
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

     foodBucket->getElement(i).setObjPos(foodX, foodY, '*');

     copyX = foodX;
     copyY = foodY; 
    }

}

objPos foodBin:: getFoodPos(int i) const{

    return foodBucket->getElement(i);
} 
