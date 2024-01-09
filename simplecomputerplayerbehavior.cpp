#include <QList>
#include "simplecomputerplayerbehavior.h"

Cell* SimpleComputerPlayerBehavior::chooseNextStep(Field* field)
{
    QList<Cell*> emptyCellList;
    Cell* cell;

    for (int i = 0; i < field->getHeight(); i++)
        for (int j = 0; j < field->getWidth(); j++)
        {
            cell = field->getCell(i, j);
            if (cell->getCondition() == Empty)
                emptyCellList.append(cell);
        }

    srand(time(NULL));
    int i = rand() % emptyCellList.count();

    return emptyCellList.at(i);
}
