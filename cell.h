#ifndef CELL_H
#define CELL_H

#include "cellcondition.h"

class Cell
{
private:
    int x;
    int y;
    CellCondition condition;
public:
    void setX(int newX);
    int getX();
    void setY(int newY);
    int getY();
    void setCondition(CellCondition newCondition);
    CellCondition getCondition();
};

#endif // CELL_H
