#ifndef FOOD_H
#define FOOD_H

#include "objPosArrayList.h"
#include <cstdlib>

class foodBin{

    private:
        objPosArrayList* foodBucket;
    public:
        foodBin();
        ~foodBin();
        void generateFood(int,int, objPosArrayList*);
        objPos getFoodPos(int) const;

};



#endif