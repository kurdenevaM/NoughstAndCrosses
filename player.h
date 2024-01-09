#ifndef PLAYER_H
#define PLAYER_H

#include "playermark.h"

class Player
{
protected:
    PlayerMark mark;
public:
    void setPlayerMark(PlayerMark newMark);
    PlayerMark getPlayerMark();
};

#endif // PLAYER_H
