#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include "shape.h"

/**
* draw star in the scene
*/
class Star : public Shape, public QAbstractGraphicsShapeItem, public QObject
{
public:
    /**
    * constructor
    **/
    Star( QObject* parent = 0 );

    /**
    * Destructor
    **/
    ~Star();

    /**
    * begin to draw the star
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void beginDraw( QGraphicsSceneMouseEvent* event );

    /**
    * start drawing the star
    *
    * @param event the QGraphicsSceneMouseEvent
    **/
    void drawing( QGraphicsSceneMouseEvent* event );

    /**
    * set rect for star
    *
    * @param rect the rect of star
    **/
    void setRect( const QRectF& rect );

    /**
    * From QGraphicsItem
    * get the painter path
    **/
    QPainterPath shape () const;

protected:
    /**
    * From QGraphicsItem
    * get the boundingRect
    **/
    QRectF boundingRect() const;

    /**
    * From QGraphicsItem
    * paints the contents of an item in local coordinates
    *
    * @param painter painter to paint content
    * @param opt style options for the item
    * @param widget the widget painted on
    **/
    void paint( QPainter* painter,
                const QStyleOptionGraphicsItem* opt,
                QWidget* widget = 0 );

    /**
    * From QObject
    * time event handler
    **/
    void timerEvent( QTimerEvent* timerEvent );


private:
    /**
    * the bounding Rect
    **/
    QRectF m_rect;

    /**
    * the painter path
    **/
    QPainterPath m_shape;

    /**
    * start point of the star
    **/
    QPointF m_startPoint;

};

#endif // STAR_H
