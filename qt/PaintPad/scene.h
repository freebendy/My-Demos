#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QIcon>
#include "shape.h"
#include "shapesetting.h"

class QIcon;

/**
* graphics scene maintaining the items
*/
class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /**
    * constructor
    *
    * @param parent parent of the window
    **/
    Scene( ShapeSetting& aShapeSetting, QObject* parent = 0 );

    /**
    * destructor
    **/
    ~Scene();

public slots:
    /**
    * set the shape
    **/
    void setCurrentShape( Shape::Code shape );

    /**
    * draw text
    **/
    void drawText();

    /**
    * draw image
    *
    * @param icon the icon to drawed
    **/
    void drawImg( QIcon icon );

    /**
    * load image
    *
    * @param image the image to load
    **/
    void loadImage( QImage image );

    /**
    * save image
    *
    * @param fileName the file's name to save the image
    **/
    void saveImage( const QString& fileName );

protected:
    /**
    * From QGraphicsScene
    * mouse press event handler
    *
    * @param event event need handled
    **/
    void mousePressEvent( QGraphicsSceneMouseEvent* event );

    /**
    * From QGraphicsScene
    * mouse move event handler
    *
    * @param event event need handled
    **/
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event );

    /**
    * From QGraphicsScene
    * mouse release event handler
    *
    * @param event event need handled
    **/
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event );

private:
    /**
    * set the item pos randomly
    *
    * @param item the item to set pos
    **/
    void randomItemPos( QGraphicsItem* item );

private:
    /**
    * current shape code
    **/
    Shape::Code m_currShapeCode;

    /**
    * current shape item
    **/
    Shape* m_currItem;

    /**
    * shape setting
    **/
    ShapeSetting& m_shapeSetting;

    /**
    * whether permit to draw
    **/
    bool m_perm;

};

#endif // SCENE_H
