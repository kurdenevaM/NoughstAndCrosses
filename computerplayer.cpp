#include "computerplayer.h"

void ComputerPlayer::setBehaviorStrategy(IComputerPlayerBehavior* newStrategy)
{
    strategy = newStrategy;
}
Cell* ComputerPlayer::doNextStep(Field* field)
{
    Cell* cell = strategy->chooseNextStep(field);
    CellCondition newCondition = mark == NoughtMark ? Nought : Cross;
    cell->setCondition(newCondition);
    return cell;
}
