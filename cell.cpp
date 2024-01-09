#include "cell.h"

void Cell::setX(int newX)
{
    x = newX;
}

int Cell::getX()
{
    return x;
}

void Cell::setY(int newY)
{
    y = newY;
}

int Cell::getY()
{
    return y;
}

void Cell::setCondition(CellCondition newCondition)
{
    condition = newCondition;
}

CellCondition Cell::getCondition()
{
    return condition;
}
