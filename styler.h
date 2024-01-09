#ifndef STYLER_H
#define STYLER_H

#include <QString>

class Styler
{
public:
    static QString getMainWindowStyle();
    static QString getPlayButtonStyle();

    static QString getXButtonNonSelectedStyle();
    static QString getXButtonSelectedStyle();
    static QString getOButtonNonSelectedStyle();
    static QString getOButtonSelectedStyle();

    static QString getEmptyFieldButtonStyle();

    static QString getXFieldButtonStyle();
    static QString getXWinButtonStyle();
    static QString getXLossButtonStyle();

    static QString getOFieldButtonStyle();
    static QString getOWinButtonStyle();
    static QString getOLossButtonStyle();
};

#endif // STYLER_H
