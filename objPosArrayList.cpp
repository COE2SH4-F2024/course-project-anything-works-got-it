#include "objPosArrayList.h"
#include <iostream>
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // Deallocate heap data
    aList = nullptr;

}

int objPosArrayList::getSize() const
{

    return listSize;

}

void objPosArrayList::insertHead(objPos thisPos)
{

    if (listSize >= arrayCapacity)
    {
        std::cout << "Error: List is full; cannot insert at head." << std::endl;
        return;
    }

    for (int i = listSize; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos; // Insert new element at the head
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity)
    {
        std::cout << "Error: List is full; cannot insert at tail." << std::endl;
        return;
    }
    aList[listSize] = thisPos; // Insert new element at the tail
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize == 0)
    {
        std::cout << "Error: List is empty; cannot remove head." << std::endl;
        return;
    }
    for (int i = 0; i < listSize - 1; ++i)
    {
        aList[i] = aList[i + 1];
    }

    listSize--;
}

void objPosArrayList::removeTail()
{
    if (listSize == 0)
    {
        std::cout << "Error: List is empty; cannot remove tail." << std::endl;
        return;
    }
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}