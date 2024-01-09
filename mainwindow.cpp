#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "styler.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGUIStyle();
    configurateGameField();
    lockGameFieldButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGUIStyle()
{
    this->setStyleSheet(Styler::getMainWindowStyle());
    ui->buttonPlay->setStyleSheet(Styler::getPlayButtonStyle());
    ui->buttonX->setStyleSheet(Styler::getXButtonSelectedStyle());
    ui->buttonO->setStyleSheet(Styler::getOButtonNonSelectedStyle());
    setInitialGameFieldStyle();
    ui->winLabel->setText("");
}

void MainWindow::on_buttonX_clicked()
{
    playerSymbol = "X";
    ui->buttonX->setStyleSheet(Styler::getXButtonSelectedStyle());
    ui->buttonO->setStyleSheet(Styler::getOButtonNonSelectedStyle());
}

void MainWindow::on_buttonO_clicked()
{
    playerSymbol = "O";
    ui->buttonO->setStyleSheet(Styler::getOButtonSelectedStyle());
    ui->buttonX->setStyleSheet(Styler::getXButtonNonSelectedStyle());
}

void MainWindow::onGameFieldButtonClicked()
{
    QPushButton* btn = qobject_cast <QPushButton*>(sender());
    int row = btn->property("row").toInt();
    int column = btn->property("column").toInt();

    if(btn->text() == "")
    {
        btn->setText(playerSymbol);

        QString style;
        if (playerSymbol == "X")
            style = Styler::getXFieldButtonStyle();
        else
            style = Styler::getOFieldButtonStyle();

        changeButtonStyle(row+1, column, style);

        emit playerStepIsDone(row, column);
    }
}

void MainWindow::changeGameFieldAfterComputerStep(int x, int y)
{
    QString symbol;
    QString style;

    if (playerSymbol == "X")
    {
        symbol = "O";
        style = Styler::getOFieldButtonStyle();
    }
    else
    {
        symbol = "X";
        style = Styler::getXFieldButtonStyle();
    }

    QPushButton* btn = qobject_cast <QPushButton*>(ui->gridLayout->itemAtPosition(x+1, y)->widget());
    btn->setText(symbol);
    changeButtonStyle(x+1, y, style);
}

void MainWindow::displayGameEnd(QString wonSymbol, QList<QPoint*> wonPoints)
{
    QString message;
    if (wonSymbol != "")
    {
        QString style;
        if (wonSymbol == playerSymbol)
        {
            message = "Вы выиграли! :)";
            style = wonSymbol == "X" ? Styler::getXWinButtonStyle() : Styler::getOWinButtonStyle();
        }
        else
        {
            message = "Вы проиграли! :(";
            style = wonSymbol == "X" ? Styler::getXLossButtonStyle() : Styler::getOLossButtonStyle();
        }

        foreach(QPoint* point, wonPoints)
            changeButtonStyle(point->x()+1, point->y(), style);
    }
    else
        message = "Ничья";

    ui->winLabel->setText(message);
    lockGameFieldButtons();
    ui->buttonPlay->setText("Играть снова");
    isGameOn = false;
    ui->buttonX->setDisabled(false);
    ui->buttonO->setDisabled(false);
}

void MainWindow::changeButtonStyle(int x, int y, QString style)
{
    QPushButton* btn = qobject_cast <QPushButton*>(ui->gridLayout->itemAtPosition(x, y)->widget());
    btn->setStyleSheet(style);
}

void MainWindow::setInitialGameFieldStyle()
{
    QString style = Styler::getEmptyFieldButtonStyle();
    for (int i = 0; i <3; i++)
        for (int j = 0; j < 3; j++)
        {
            qobject_cast <QPushButton*>(ui->gridLayout->itemAtPosition(i+1, j)->widget())->setText("");
            changeButtonStyle(i+1, j, style);
        }
}

void MainWindow::on_buttonPlay_clicked()
{
    if (!isGameOn)
    {
        setInitialGameFieldStyle();
        unlockGameFieldButtons();
        ui->buttonPlay->setText("Сдаюсь");
        ui->buttonX->setDisabled(true);
        ui->buttonO->setDisabled(true);
        ui->winLabel->setText("Идет игра");
        isGameOn = true;
        emit gameStarted(playerSymbol);
    }
    else {
        ui->buttonPlay->setText("Играть");
        ui->buttonX->setDisabled(false);
        ui->buttonO->setDisabled(false);
        ui->winLabel->setText("Проиграл :(");
        isGameOn = false;
    }
}

void MainWindow::configurateGameField()
{
    QGridLayout* grid = qobject_cast<QGridLayout*>(ui->gridLayout);
    for (int i = 0; i <3; i++)
        for (int j = 0; j < 3; j++)
        {
            QPushButton* btn = qobject_cast <QPushButton*>(grid->itemAtPosition(i+1, j)->widget());
            btn->setProperty("row", i);
            btn->setProperty("column", j);
            connect(btn, &QPushButton::clicked, this, &MainWindow::onGameFieldButtonClicked);
        }
}

void MainWindow::lockGameFieldButtons()
{
    QGridLayout* grid = qobject_cast<QGridLayout*>(ui->gridLayout);
    for (int i = 0; i <3; i++)
        for (int j = 0; j < 3; j++)
        {
            QPushButton* btn = qobject_cast <QPushButton*>(grid->itemAtPosition(i+1, j)->widget());
            btn->setDisabled(true);
        }
}

void MainWindow::unlockGameFieldButtons()
{
    QGridLayout* grid = qobject_cast<QGridLayout*>(ui->gridLayout);
    for (int i = 0; i <3; i++)
        for (int j = 0; j < 3; j++)
        {
            QPushButton* btn = qobject_cast <QPushButton*>(grid->itemAtPosition(i+1, j)->widget());
            btn->setDisabled(false);
        }
}
