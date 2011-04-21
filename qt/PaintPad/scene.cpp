#include <QMetaMethod>
#include <QPainter>
#include <QMessageBox>
#include "scene.h"
#include "line.h"
#include "rect.h"
#include "oval.h"
#include "star.h"

const QSize PIXMAPSIZE( 80, 80 );

const double MINOPACITY = 0.5;
const double MAXOPACITY = 0.8;

const double MINRGB = 0;
const double MAXRGB = 1;

const int MINFONTPIXELSIZE = 10;
const int MAXFONTPIXELSIZE = 40;

// ---------------------------------------------------------------------------
// Get a random number between min and max
// ---------------------------------------------------------------------------
//
double randomNumber (double min, double max)
{
    double rand_max = double(RAND_MAX);
    double r = double (rand());
    double value = (max - min) / (rand_max) * r + min;
    return value;
}

// ---------------------------------------------------------------------------
// Constructro
// ---------------------------------------------------------------------------
//
Scene::Scene( ShapeSetting& aShapeSetting, QObject* parent )
    : QGraphicsScene( parent ),
    m_currShapeCode( Shape::None ),
    m_currItem( NULL ),
    m_shapeSetting( aShapeSetting ),
    m_perm( false )
{

}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
Scene::~Scene()
{

}

// ---------------------------------------------------------------------------
// Set the current shape
// ---------------------------------------------------------------------------
//
void Scene::setCurrentShape( Shape::Code shape )
{
    if( shape != m_currShapeCode )
    {
        m_currShapeCode = shape;
        m_currItem = NULL;
    }
}

// ---------------------------------------------------------------------------
// Draw the text
// ---------------------------------------------------------------------------
//
void Scene::drawText()
{
    const QMetaObject* mo = metaObject();

    for( int i = 0; i < mo->methodCount(); ++i )
    {
        QMetaMethod metaMethod = mo->method( i );
        QGraphicsTextItem* textItem = new QGraphicsTextItem;
        textItem->setPlainText( metaMethod.signature() );
        QColor color;
        color.setRgbF(
                randomNumber( MINRGB, MAXRGB ),
                randomNumber( MINRGB, MAXRGB ),
                randomNumber( MINRGB, MAXRGB ),
                randomNumber( MINOPACITY, MAXOPACITY ) );
        textItem->setDefaultTextColor( color );
        QFont font;
        font.setPixelSize( randomNumber( MINFONTPIXELSIZE,
                                         MAXFONTPIXELSIZE ) );
        textItem->setFont( font );
        addItem( textItem );

        randomItemPos( textItem );
    }
}

// ---------------------------------------------------------------------------
// Draw the image
// ---------------------------------------------------------------------------
//
void Scene::drawImg( QIcon icon )
{
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem;
    pixmapItem->setPixmap(
            icon.pixmap( icon.actualSize( PIXMAPSIZE ) ) );
    addItem( pixmapItem );

    randomItemPos( pixmapItem );
}

// ---------------------------------------------------------------------------
// load image
// ---------------------------------------------------------------------------
//
void Scene::loadImage( QImage image )
{
    QPixmap pixmap( image.size() );
    pixmap.fill( Qt::white );

    QPainter painter( &pixmap );

    painter.drawImage( 0, 0, image );
    painter.end();

    clear();
    QGraphicsPixmapItem* item = addPixmap( pixmap );
    item->setPos( sceneRect().topLeft() );
}

// ---------------------------------------------------------------------------
// save image
// ---------------------------------------------------------------------------
//
void Scene::saveImage( const QString& fileName )
{
    QPixmap pixmap( sceneRect().size().toSize() );
    pixmap.fill( Qt::white );
    QPainter painter( &pixmap );

    render( &painter,
            QRectF( QPointF( 0, 0 ), sceneRect().size() ),
            sceneRect().toRect() );

    if( !pixmap.save( fileName ) )
        QMessageBox::warning( NULL, "Save error", "Could not save file" );
}

// ---------------------------------------------------------------------------
// Mouse press event handler
// ---------------------------------------------------------------------------
//
void Scene::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    switch( m_currShapeCode )
    {
    case Shape::Line:
        {
            Line* line = new Line;
            m_currItem = line;

            QColor color( m_shapeSetting.fbColor() );
            color.setAlphaF( m_shapeSetting.opacity() );
            line->setPen( QPen( color, m_shapeSetting.lineSize() ) );

            addItem( line );
            break;
        }
    case Shape::Rect:
        {
            Rect* rect = new Rect;
            m_currItem = rect;

            rect->setPen( QPen( m_shapeSetting.edgeColor(),
                                m_shapeSetting.edgeSize(),
                                Qt::SolidLine,
                                Qt::SquareCap,
                                Qt::MiterJoin ) );
            QColor color( m_shapeSetting.fbColor() );
            color.setAlphaF( m_shapeSetting.opacity() );
            rect->setBrush( color );

            addItem( rect );
            break;
        }
    case Shape::Oval:
        {
            Oval* oval = new Oval;
            m_currItem = oval;

            oval->setPen( QPen( m_shapeSetting.edgeColor(),
                                m_shapeSetting.edgeSize() ) );
            QColor color( m_shapeSetting.fbColor() );
            color.setAlphaF( m_shapeSetting.opacity() );
            oval->setBrush( color );

            addItem( oval );
            break;
        }
    case Shape::Star:
        {
            Star* star = new Star;
            m_currItem = star;

            star->setPen( QPen( m_shapeSetting.edgeColor(),
                                m_shapeSetting.edgeSize(),
                                Qt::SolidLine,
                                Qt::SquareCap,
                                Qt::MiterJoin ) );

            QColor color( m_shapeSetting.fbColor() );
            color.setAlphaF( m_shapeSetting.opacity() );
            star->setBrush( color );

            addItem( star );
            break;
        }
    default:
        break;
    }

    if( m_currItem )
    {
        m_currItem->beginDraw( event );
        m_perm = false;
    }

    QGraphicsScene::mousePressEvent( event );
}

// ---------------------------------------------------------------------------
// Mouse move event handler
// ---------------------------------------------------------------------------
//
void Scene::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    if( m_currItem && !m_perm )
    {
        m_currItem->drawing( event );
    }
    QGraphicsScene::mouseMoveEvent( event );
}

// ---------------------------------------------------------------------------
// Mouse release event handler
// ---------------------------------------------------------------------------
//
void Scene::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    m_perm = true;
    QGraphicsScene::mouseReleaseEvent( event );
}

// ---------------------------------------------------------------------------
// set the item pos randomly
// ---------------------------------------------------------------------------
//
void Scene::randomItemPos( QGraphicsItem* item )
{
    qreal itemWidth = item->boundingRect().width();
    qreal itemHeight = item->boundingRect().height();
    qreal width = sceneRect().size().width();
    qreal height = sceneRect().size().height();
    item->setPos(
            randomNumber( - width / 2, width / 2 - itemWidth ),
            randomNumber( - height / 2, height / 2 - itemHeight ) );
}
