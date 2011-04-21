#ifndef SHAPEUTILS_H
#define SHAPEUTILS_H

class ShapeUtils
{
public:
    static QRectF rect( QPointF* startPoint, QGraphicsSceneMouseEvent* event )
    {
        QPointF topLeft;
        QSizeF size;
        //drag down right
        if( event->scenePos().x() >= startPoint->x() &&
            event->scenePos().y() >= startPoint->y() )
        {
            topLeft = *startPoint;
            size = QSizeF( event->scenePos().x() - startPoint->x(),
                           event->scenePos().y() - startPoint->y() );
        }
        //drag up right
        else if( event->scenePos().x() > startPoint->x() &&
                 event->scenePos().y() < startPoint->y() )
        {
            topLeft = QPointF( startPoint->x(), event->scenePos().y() );
            size = QSizeF( event->scenePos().x() - startPoint->x(),
                            startPoint->y() - event->scenePos().y() );
        }
        //drag up left
        else if( event->scenePos().x() <= startPoint->x() &&
                 event->scenePos().y() <= startPoint->y() )
        {
            topLeft = QPointF( event->scenePos().x(), event->scenePos().y() );
            size = QSizeF( startPoint->x() - event->scenePos().x(),
                            startPoint->y() - event->scenePos().y() );
        }
        //drag down left
        else if( event->scenePos().x() < startPoint->x() &&
                 event->scenePos().y() > startPoint->y() )
        {
            topLeft = QPointF( event->scenePos().x(), startPoint->y() );
            size = QSizeF( startPoint->x() - event->scenePos().x(),
                                event->scenePos().y() - startPoint->y() );
        }
        return QRectF( topLeft, size );
    }
};

#endif // SHAPEUTILS_H
