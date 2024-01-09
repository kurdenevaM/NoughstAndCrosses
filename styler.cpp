#include "styler.h"

QString Styler::getMainWindowStyle()
{
    return "background-color: #fee6ff;";
}

QString Styler::getPlayButtonStyle()
{
    return "QPushButton{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(220, 107, 255, 255), stop:1 rgba(113, 82, 255, 255));"
               "border: none;"
               "border-radius: 20px;"
               "color: #ffffff;"
               "}"
               "QPushButton::hover{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(221, 110, 255, 255), stop:1 rgba(131, 104, 255, 255));"
               "}"
               "QPushButton::pressed{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(196, 95, 227, 255), stop:1 rgba(99, 71, 223, 255));"
           "}";
}

QString Styler::getXButtonNonSelectedStyle()
{
    return "QPushButton{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(118, 55, 212, 255), stop:1 rgba(71, 51, 159, 255));"
               "border: 1px solid #333;"
               "border-top-left-radius: 5px;"
               "border-bottom-left-radius: 5px;"
               "color: #ffffff;"
           "}";
}

QString Styler::getXButtonSelectedStyle()
{
    return "QPushButton{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(104, 49, 187, 255), stop:1 rgba(67, 48, 150, 255));"
               "border: 1px solid #333;"
               "border-top-left-radius: 5px;"
               "border-bottom-left-radius: 5px;"
               "color: #ffffff;"
           "}";
}

QString Styler::getOButtonNonSelectedStyle()
{
    return "QPushButton{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(118, 55, 212, 255), stop:1 rgba(71, 51, 159, 255));"
               "border: 1px solid #333;"
               "border-left: none;"
               "border-top-right-radius: 5px;"
               "border-bottom-right-radius: 5px;"
               "color: #ffffff;"
           "}";
}

QString Styler::getOButtonSelectedStyle()
{
    return "QPushButton{"
               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.949, "
               "stop:0 rgba(104, 49, 187, 255), stop:1 rgba(67, 48, 150, 255));"
               "border: 1px solid #333;"
               "border-left: none;"
               "border-top-right-radius: 5px;"
               "border-bottom-right-radius: 5px;"
               "color: #ffffff;"
           "}";
}

QString Styler::getEmptyFieldButtonStyle()
{
    return "QPushButton{"
               "background-color: #6709d9;"
               "border: none;"
               "border-radius: 5px;"
               "}"
               "QPushButton::hover{"
               "background-color: #790bff;"
           "}";
}

QString Styler::getXFieldButtonStyle()
{
    return "QPushButton{"
               "background-color: #6709d9;"
               "border: none;"
               "border-radius: 5px;"
               "font-family: 'Segoe Print';"
               "font-size: 70px;"
               "font-weight: bold;"
               "color: rgb(252, 255, 198);"
           "}";
}

QString Styler::getXWinButtonStyle()
{
    return "QPushButton{"
               "background-color: #ba09eb;"
               "border: none;"
               "border-radius: 5px;"
               "font-family: 'Segoe Print';"
               "font-size: 70px;"
               "font-weight: bold;"
               "color: rgb(252, 255, 198);"
           "}";
}

QString Styler::getXLossButtonStyle()
{
    return "QPushButton{"
               "background-color: #4404cf;"
               "border: none;"
               "border-radius: 5px;"
               "font-family: 'Segoe Print';"
               "font-size: 70px;"
               "font-weight: bold;"
               "color: rgb(252, 255, 198);"
           "}";
}

QString Styler::getOFieldButtonStyle()
{
    return "QPushButton{"
               "background-color: #6709d9;"
               "border: none;"
               "border-radius: 5px;"
               "font-family: 'Segoe Print';"
               "font-size: 70px;"
               "font-weight: bold;"
               "color: #f1f1f1;"
           "}";
}

QString Styler::getOWinButtonStyle()
{
    return "QPushButton{"
               "background-color: #ba09eb;"
               "border: none;"
               "border-radius: 5px;"
               "font-family: 'Segoe Print';"
               "font-size: 70px;"
               "font-weight: bold;"
               "color: #f1f1f1;"
           "}";
}

QString Styler::getOLossButtonStyle()
{
    return "QPushButton{"
               "background-color: #4404cf;"
               "border: none;"
               "border-radius: 5px;"
               "font-family: 'Segoe Print';"
               "font-size: 70px;"
               "font-weight: bold;"
               "color: #f1f1f1;"
           "}";
}
