#ifndef FOOD_H
#define FOOD_H

#include "objPosArrayList.h"
#include <cstdlib>

class food{

    private:
        objPosArrayList* foodBucket;
    public:
        food();
        ~food();
        void generateFood(int,int, objPosArrayList*);
        objPos getFoodPos(int) const;

};



#endif