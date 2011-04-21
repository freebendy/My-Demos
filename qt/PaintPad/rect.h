#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>
#include "shape.h"

/**
* draw rect in the scene
*/
class Rect : public Shape, public QGraphicsRectItem
{
public:
    /**
    * constructor
    **/
    Rect();

    /**
    * Destructor
    **/
    ~Rect();

    /**
    * begin to draw the rect
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void beginDraw( QGraphicsSceneMouseEvent* event );

    /**
    * start drawing the rect
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void drawing( QGraphicsSceneMouseEvent* event );

private:
    /**
    * start point of the rect
    **/
    QPointF m_startPoint;

};

#endif // RECT_H
