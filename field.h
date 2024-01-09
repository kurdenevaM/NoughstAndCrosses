#ifndef FIELD_H
#define FIELD_H

#include "cell.h"

class Field
{
private:
    int height = 3;
    int width = 3;
    Cell** field;

public:
    Field();
    int getHeight();
    int getWidth();
    Cell* getCell(int i, int j);
    bool isContainedEmptyCell();
};

#endif // FIELD_H
