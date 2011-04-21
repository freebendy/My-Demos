#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect : public Shape
{
public:
    Rect();

    void paint(QPainter &painter);
};

#endif // RECT_H
