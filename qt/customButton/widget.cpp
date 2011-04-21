#include "widget.h"
#include <QLabel>
#include <QHBoxLayout>

Button::Button(QWidget *parent)
    : QPushButton(parent)
{
    setObjectName(QString::fromUtf8("button"));

    mLeftLabel = new QLabel( this );
    mLeftLabel->setMinimumSize( 40,40 );
    mLeftLabel->setText( tr( "Left1111111111111111111111" ) );
    mLeftLabel->setStyleSheet( "QLabel { width:10px; text-overflow:ellipsis; white-space:nowrap;overflow:hidden; }" );

    mRightLabel = new QLabel( this );
    mRightLabel->setMinimumSize( 40,40 );
    mRightLabel->setText( tr( "Right" ) );

    QHBoxLayout* mainHLayout = new QHBoxLayout( this );
    mainHLayout->addWidget( mLeftLabel );
    mainHLayout->addWidget( mRightLabel );

}

Button::~Button()
{

}
