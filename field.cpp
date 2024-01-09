#include "field.h"

Field::Field()
{
    field = new Cell*[height];
    for (int i = 0; i < height; i++)
        field[i] = new Cell[width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            field[i][j].setX(i);
            field[i][j].setY(j);
            field[i][j].setCondition(Empty);
        }
}

int Field::getHeight()
{
    return height;
}

int Field::getWidth()
{
    return width;
}

Cell* Field::getCell(int i, int j)
{
    return &field[i][j];
}

bool Field::isContainedEmptyCell()
{
    bool result = false;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result = field[i][j].getCondition() == Empty;
            if(result)
                break;
        }
        if(result)
            break;
    }

    return result;
}
