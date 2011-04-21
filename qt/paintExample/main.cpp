#include <QtGui/QApplication>
#include <QGraphicsView>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a( argc, argv );
    MainWindow w;
    w.show();

    QGraphicsScene* scene = new QGraphicsScene;
    scene->addLine( 10, 10, 150, 300 );
    QGraphicsView* view = new QGraphicsView( scene );
    view->resize( 500, 500 );
    view->setWindowTitle( "Graphics View" );
    //view->setAlignment( Qt::AlignLeft );
    view->show();

    return a.exec();
}
