#ifndef SHAPE_H
#define SHAPE_H

class QGraphicsSceneMouseEvent;

class Shape
{
public:

    //shape code
    enum Code
    {
        None,
        Line,
        Rect,
        Oval,
        Star
    };

    /**
    * constructor
    **/
    Shape() {}

    /**
    * destructor
    **/
    virtual ~Shape() {}

    /**
    * begin to draw the shape. pure virtual function
    **/
    virtual void beginDraw( QGraphicsSceneMouseEvent* event ) = 0;

    /**
    * drawing the shape. pure virtual function
    **/
    virtual void drawing ( QGraphicsSceneMouseEvent* event ) = 0;

};

#endif // SHAPE_H
