#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QtGui>
#include <QDebug>

#include "shape.h"
#include "line.h"
#include "rect.h"

class PaintWidget : public QGraphicsScene
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = 0);

public slots:
    void setCurrentShape(Shape::Code s)
    {
        if(s != currShapeCode) {
            currShapeCode = s;
        }
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Shape::Code currShapeCode;
    Shape *currItem;
    bool perm;
};

#endif // PAINTWIDGET_H
