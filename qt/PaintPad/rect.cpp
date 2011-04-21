#include <QGraphicsSceneEvent>
#include "rect.h"
#include "shapeutils.h"

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
Rect::Rect()
{
}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
Rect::~Rect()
{
}

// ---------------------------------------------------------------------------
// Begin to draw rect
// ---------------------------------------------------------------------------
//
void Rect::beginDraw( QGraphicsSceneMouseEvent* event )
{
    //set the started point
    m_startPoint = event->scenePos();
    setRect( QRectF( m_startPoint, QSizeF( 0, 0) ) );
}

// ---------------------------------------------------------------------------
// drawing rect
// ---------------------------------------------------------------------------
//
void Rect::drawing( QGraphicsSceneMouseEvent* event )
{
    setRect( ShapeUtils::rect( &m_startPoint, event ) );
}

