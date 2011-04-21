#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <math.h>
#include "star.h"
#include "shapeutils.h"

#define DEG2RAD(x) ( ( x ) * 3.1415 / 180.0 )

const int TIMERINTERNAL = 10;
const qreal ROTATIONANGLE = 1;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
Star::Star( QObject* parent ) :
        QObject( parent )
{
    startTimer( TIMERINTERNAL );
}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
Star::~Star()
{
}

// ---------------------------------------------------------------------------
// Begin to draw star
// ---------------------------------------------------------------------------
//
void Star::beginDraw( QGraphicsSceneMouseEvent* event )
{
    //set the started point
    m_startPoint = event->scenePos();
    setRect( QRectF( m_startPoint, QSizeF( 0, 0) ) );
}

// ---------------------------------------------------------------------------
// Drawing star
// ---------------------------------------------------------------------------
//
void Star::drawing( QGraphicsSceneMouseEvent* event )
{
    setRect( ShapeUtils::rect( &m_startPoint, event ) );
}

// ---------------------------------------------------------------------------
// Set rect for star
// ---------------------------------------------------------------------------
//
void Star::setRect( const QRectF& rect )
{
    if( m_rect == rect )
        return;

    prepareGeometryChange();

    m_rect = rect;

    // Create a square inside the rectangle
    QRectF square;
    if( rect.width() == rect.height() )
        square = rect;
    else
    {
        QPointF center = rect.center();
        qreal size = rect.height();

        if( rect.width() < rect.height() )
            size = rect.width();

        square = QRectF( center - QPointF( size / 2, size / 2 ),
                         QSize( size, size ) );
    }

    // We need two circles in the square that forms the star
    QPointF center = square.center();
    qreal innerRadius = ( square.width() / 2 ) * 0.5;
    qreal outerRadius = ( square.height() / 2 ) * 1.0;

    // Lets say the star has 5 gears. Each gear tip is angleStep degrees away
    const int nrGears = 5;
    qreal angleStep = 360.0 / qreal( nrGears );
    qreal halfAngleStep = angleStep / 2;

    // Now construct the star
    QPainterPath path;
    qreal angle = 0;
    for( int i = 0; i < nrGears * 2; i++ )
    {
        qreal r = ( i % 2 ) ? innerRadius : outerRadius;
        qreal x = center.x() + r * cos( DEG2RAD( angle ) );
        qreal y = center.y() + r * sin( DEG2RAD( angle ) );

        if( !i )
            path.moveTo( x, y );
        else
            path.lineTo( x, y );

        angle += halfAngleStep;
    }
    path.closeSubpath();

    m_shape = path;

    update();
}

// ---------------------------------------------------------------------------
// Get the painter path
// ---------------------------------------------------------------------------
//
QPainterPath Star::shape () const
{
    return m_shape;
}

// ---------------------------------------------------------------------------
// Get the bounding rect
// ---------------------------------------------------------------------------
//
QRectF Star::boundingRect() const
{
    return m_rect;
}

// ---------------------------------------------------------------------------
// Paints the contents of an item in local coordinates
// ---------------------------------------------------------------------------
//
void Star::paint( QPainter* painter,
                 const QStyleOptionGraphicsItem* opt,
                 QWidget* widget )
{
    Q_UNUSED( opt );
    Q_UNUSED( widget );

    painter->save();

    painter->setPen( this->pen() );
    painter->setBrush( this->brush() );
    painter->drawPath( m_shape );

    painter->restore();
}

// ---------------------------------------------------------------------------
// Time event handler
// ---------------------------------------------------------------------------
//
void Star::timerEvent( QTimerEvent* timerEvent )
{
    Q_UNUSED( timerEvent );

    setTransformOriginPoint( m_rect.center() );
    setRotation( rotation() + ROTATIONANGLE );
}
