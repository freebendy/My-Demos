#include <QtGui/QApplication>
#include <QVBoxLayout>
#include "widget.h"
#include "myframe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    MyFrame myFrame( &widget );

    Button button( &myFrame );
    button.setStyleSheet( "Button#button { border: 1px solid grey;color: darkblue; background-color: white;border-radius: 10px;} Button#button:pressed { color: white; background-color: darkblue;}" );
    button.setMinimumSize( 80, 40 );
    QVBoxLayout frameLayout( &myFrame );
    frameLayout.setContentsMargins( 0, 0, 0, 0 );
    frameLayout.setSpacing( 0 );
    frameLayout.addWidget( &button );
    QVBoxLayout widgetLayout( &widget );
    widgetLayout.setContentsMargins( 0, 0, 0, 0 );
    widgetLayout.setSpacing( 0 );
    widgetLayout.addWidget( &myFrame );
    widget.show();

    return a.exec();
}
