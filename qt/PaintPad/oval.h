#ifndef OVAL_H
#define OVAL_H

#include <QGraphicsEllipseItem>
#include "shape.h"

/**
* draw oval in the scene
*/
class Oval : public Shape, public QGraphicsEllipseItem
{
public:
    /**
    * constructor
    **/
    Oval();

    /**
    * Destructor
    **/
    ~Oval();

    /**
    * begin to draw the oval
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void beginDraw( QGraphicsSceneMouseEvent* event );

    /**
    * start drawing the oval
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void drawing( QGraphicsSceneMouseEvent* event );

private:
    /**
    * start point of the oval
    **/
    QPointF m_startPoint;

};

#endif // OVAL_H
