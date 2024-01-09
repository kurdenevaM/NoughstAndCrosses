#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QList>
#include <QPoint>
#include "field.h"
#include "player.h"
#include "computerplayer.h"
#include "simplecomputerplayerbehavior.h"

class Game : public QObject
{
    Q_OBJECT
protected:
    Field field;
    Player player1;
    ComputerPlayer player2;
    QList<Cell*> wonCombination;
    void initialGame(QString symbol);
    bool checkGameEnd();
    bool checkXWon();
    bool checkOWon();
    bool checkWonCombination(CellCondition mark);
    void sendEndGameSignal();
    void doComputerStep();

public slots:
    void startGame(QString symbol);
    void changeFieldAfterHumanStep(int x, int y);

signals:
    void computerStepIsDone(int x, int y);
    void isGameEnd(QString symbol, QList<QPoint*> wonCombination);
};

#endif // GAME_H
