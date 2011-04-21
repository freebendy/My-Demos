#include <QDialogButtonBox>
#include <QVBoxLayout>
#include "aboutdialog.h"
#include "aboutdialoglabel.h"

const int MINWIDTH = 700;
const int MINHEIGHT = 300;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
AboutDialog::AboutDialog( QWidget* parent ) :
        QDialog( parent )
{
    AboutDialogLabel* label = new AboutDialogLabel( this );
    label->setText( tr("Tieto (Beijing) Qt internal trainning") );
    setMinimumSize( MINWIDTH, MINHEIGHT );

    QDialogButtonBox* buttons = new QDialogButtonBox( QDialogButtonBox::Ok );
    connect( buttons, SIGNAL( accepted() ), this, SLOT( accept() ) );

    QVBoxLayout* vlay = new QVBoxLayout( this );
    vlay->addWidget( label );
    vlay->addWidget( buttons );
}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
AboutDialog::~AboutDialog()
{

}
