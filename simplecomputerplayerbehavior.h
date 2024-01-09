#ifndef SIMPLECOMPUTERPLAYERBEHAVIOR_H
#define SIMPLECOMPUTERPLAYERBEHAVIOR_H

#include "icomputerplayerbehavior.h"

class SimpleComputerPlayerBehavior : public IComputerPlayerBehavior
{
public:
    Cell* chooseNextStep(Field* field);
};

#endif // SIMPLECOMPUTERPLAYERBEHAVIOR_H
