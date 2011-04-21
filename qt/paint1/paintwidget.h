#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QtGui>
#include <QDebug>
#include "shape.h"
#include "line.h"
#include "rect.h"

class PaintWidget : public QWidget
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
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Shape::Code currShapeCode;
    Shape *shape;
    bool perm;
    QList<Shape*> shapeList;
};

#endif // PAINTWIDGET_H
