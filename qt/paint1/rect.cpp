#include "rect.h"

Rect::Rect()
{
}

void Rect::paint(QPainter &painter)
{
    painter.drawRect(start.x(), start.y(),
                     end.x() - start.x(), end.y() - start.y());
}
