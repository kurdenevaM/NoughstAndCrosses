#include "mainwindow.h"
#include "game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Game game;

    QObject::connect(&w, SIGNAL(gameStarted(QString)), &game, SLOT(startGame(QString)));
    QObject::connect(&w, SIGNAL(playerStepIsDone(int, int)), &game, SLOT(changeFieldAfterHumanStep(int, int)));
    QObject::connect(&game, SIGNAL(computerStepIsDone(int, int)), &w, SLOT(changeGameFieldAfterComputerStep(int, int)));
    QObject::connect(&game, SIGNAL(isGameEnd(QString, QList<QPoint*>)), &w, SLOT(displayGameEnd(QString, QList<QPoint*>)));

    return a.exec();
}
