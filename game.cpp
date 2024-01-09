#include "game.h"

/*Game::Game()
{
    field = Field();
}*/

void Game::initialGame(QString symbol)
{
    field = Field();
    /*for (int i = 0; i < field.getHeight(); i++)
        for (int j = 0; j < field.getWidth(); j++)
            field.getCell(i, j)->setCondition(Empty);*/

    if (symbol == "X")
    {
        player1.setPlayerMark(CrossMark);
        player2.setPlayerMark(NoughtMark);
    }
    else
    {
        player2.setPlayerMark(CrossMark);
        player1.setPlayerMark(NoughtMark);
    }

    wonCombination.clear();
}

bool Game::checkGameEnd()
{
    return checkXWon() || checkOWon() || !field.isContainedEmptyCell();
}

bool Game::checkXWon()
{
    return checkWonCombination(Cross);
}

bool Game::checkOWon()
{
    return checkWonCombination(Nought);
}

bool Game::checkWonCombination(CellCondition mark)
{
    bool result = false;
    for (int i = 0; i < field.getHeight(); i++)
    {
        for (int j = 0; j < field.getWidth(); j++)
        {
            result = field.getCell(i, j)->getCondition() == mark;
            if (!result)
            {
                wonCombination.clear();
                break;
            }
            wonCombination.append(field.getCell(i, j));
        }
        if(result)
            return result;
    }

    for (int i = 0; i < field.getHeight(); i++)
    {
        for (int j = 0; j < field.getWidth(); j++)
        {
            result = field.getCell(j, i)->getCondition() == mark;
            if (!result)
            {
                wonCombination.clear();
                break;
            }
            wonCombination.append(field.getCell(j, i));
        }
        if(result)
            return result;
    }

    for (int i = 0; i < field.getHeight(); i++)
    {
        result = field.getCell(i, i)->getCondition() == mark;
        if (!result)
        {
            wonCombination.clear();
            break;
        }
        wonCombination.append(field.getCell(i, i));
    }

    if(result)
        return result;

    for (int i = 0; i < field.getHeight(); i++)
    {
        result = field.getCell(i, field.getWidth() - (i + 1))->getCondition() == mark;
        if (!result)
        {
            wonCombination.clear();
            break;
        }
        wonCombination.append(field.getCell(i, field.getWidth() - (i + 1)));
    }

    return result;
}

void Game::sendEndGameSignal()
{
    QList<QPoint*> wonPoints;
    QString wonSymbol = "";
    if (!wonCombination.isEmpty())
        wonSymbol = wonCombination.first()->getCondition() == Cross ? "X" : "O";
    foreach (Cell* cell, wonCombination)
        wonPoints.append(new QPoint(cell->getX(), cell->getY()));

    isGameEnd(wonSymbol, wonPoints);
}

void Game::startGame(QString symbol)
{
    initialGame(symbol);
    IComputerPlayerBehavior* strategy = new SimpleComputerPlayerBehavior();
    player2.setBehaviorStrategy(strategy);
        if (player1.getPlayerMark() != CrossMark)
        doComputerStep();
}

void Game::changeFieldAfterHumanStep(int x, int y)
{
    CellCondition cond = player1.getPlayerMark() == CrossMark ? Cross : Nought;
    field.getCell(x, y)->setCondition(cond);

    if(checkGameEnd())
        sendEndGameSignal();
    else
        doComputerStep();
}

void Game::doComputerStep()
{
    Cell* cell = player2.doNextStep(&field);
    cell->setCondition(cell->getCondition());
    emit computerStepIsDone(cell->getX(), cell->getY());
    if(checkGameEnd())
        sendEndGameSignal();
}
