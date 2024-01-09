#ifndef ICOMPUTERPLAYERBEHAVIOR_H
#define ICOMPUTERPLAYERBEHAVIOR_H

#include "field.h"

class IComputerPlayerBehavior
{
public:
    virtual Cell* chooseNextStep(Field* field) = 0;
};

#endif // ICOMPUTERPLAYERBEHAVIOR_H
