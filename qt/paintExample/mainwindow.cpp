#include <QPainter>
#include <QPicture>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget* parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi(this);

    QPicture picture;
    QPainter painter;
    painter.begin( &picture );              // paint in picture
    painter.drawEllipse( 10, 20, 80, 70 ); // draw an ellipse
    painter.end();                           // painting done
    picture.save( "drawing.pic" );         // save picture
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent( QPaintEvent * paintEvent )
{
    QPicture picture;
    picture.load( "drawing.pic" );          // load picture
    QPainter painter;
    painter.begin( this );            // paint in myImage
    painter.drawPicture( 0, 0, picture ); // draw the picture at (0,0)
    painter.end();
}
