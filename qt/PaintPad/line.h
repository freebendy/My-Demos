#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "shape.h"

/**
* draw oval in the scene
*/
class Line : public Shape, public QGraphicsLineItem
{
public:
    /**
    * constructor
    **/
    Line();

    /**
    * Destructor
    **/
    ~Line();

    /**
    * begin to draw the line
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void beginDraw( QGraphicsSceneMouseEvent* event );

    /**
    * start drawing the line
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void drawing( QGraphicsSceneMouseEvent* event );

};

#endif // LINE_H
