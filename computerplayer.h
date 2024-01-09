#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <QObject>
#include "player.h"
#include "playermark.h"
#include "icomputerplayerbehavior.h"

class ComputerPlayer : public Player
{
private:
    IComputerPlayerBehavior* strategy;
public:
    void setBehaviorStrategy(IComputerPlayerBehavior* newStrategy);
    Cell* doNextStep(Field* field);
};

#endif // COMPUTERPLAYER_H
