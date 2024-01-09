#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonX_clicked();
    void on_buttonO_clicked();
    void on_buttonPlay_clicked();
    void onGameFieldButtonClicked();
    void changeGameFieldAfterComputerStep(int x, int y);
    void displayGameEnd(QString wonSymbol, QList<QPoint*> wonPoints);

signals:
    void gameStarted(QString playerSymbol);
    void playerStepIsDone(int x, int y);

private:
    Ui::MainWindow *ui;
    QString playerSymbol = "X";
    bool isGameOn = false;
    void setGUIStyle();
    void changeButtonStyle(int x, int y, QString style);
    void setInitialGameFieldStyle();
    void configurateGameField();
    void lockGameFieldButtons();
    void unlockGameFieldButtons();
};
#endif // MAINWINDOW_H
