#ifndef SHAPE_H
#define SHAPE_H

#include <QtGui>

class Shape
{
public:

    enum Code {
        Line,
        Rect
    };

    Shape();

    void setStart(QPoint s)
    {
        start = s;
    }

    void setEnd(QPoint e)
    {
        end = e;
    }

    QPoint startPoint()
    {
        return start;
    }

    QPoint endPoint()
    {
        return end;
    }

    void virtual paint(QPainter & painter) = 0;

protected:
    QPoint start;
    QPoint end;
};

#endif // SHAPE_H
