#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>

class QLabel;

class Button : public QPushButton
{
    Q_OBJECT

public:
    Button(QWidget *parent = 0);
    ~Button();

private:
    QLabel* mLeftLabel;
    QLabel* mRightLabel;
};

#endif // WIDGET_H
