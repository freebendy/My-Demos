#include <QGraphicsSceneEvent>
#include "oval.h"
#include "shapeutils.h"

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
Oval::Oval()
{
}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
Oval::~Oval()
{
}

// ---------------------------------------------------------------------------
// Begin to draw oval
// ---------------------------------------------------------------------------
//
void Oval::beginDraw( QGraphicsSceneMouseEvent* event )
{
    //set the started point
    m_startPoint = event->scenePos();
    setRect( QRectF( m_startPoint, QSizeF( 0, 0) ) );
}

// ---------------------------------------------------------------------------
// drawing oval
// ---------------------------------------------------------------------------
//
void Oval::drawing( QGraphicsSceneMouseEvent* event )
{
    setRect( ShapeUtils::rect( &m_startPoint, event ) );
}

