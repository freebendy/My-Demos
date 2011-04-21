#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QListWidget>
#include "listviewdialog.h"

const QSize LISTICONSIZE( 30, 30 );
const int LISTFONTPIXELSIZE = 18;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
ListViewDialog::ListViewDialog( QWidget* parent) :
        QDialog( parent )
{
    QDialogButtonBox* buttons =
            new QDialogButtonBox(
                    QDialogButtonBox::Ok | QDialogButtonBox::Cancel );

    m_listWidget = new QListWidget( this );
    m_listWidget->setIconSize( LISTICONSIZE );
    QFont font;
    font.setPixelSize( LISTFONTPIXELSIZE );
    font.setBold( true );
    m_listWidget->setFont( font );

    createListWidgetItem(
            QString::fromUtf8( ":/paintpad/resources/tool_img.png" ) );
    createListWidgetItem(
            QString::fromUtf8( ":/paintpad/resources/ship0021.png" ) );
    createListWidgetItem(
            QString::fromUtf8( ":/paintpad/resources/tool_star.png" ) );
    createListWidgetItem(
            QString::fromUtf8(
                    ":/paintpad/resources/kontact_contacts.png" ) );
    createListWidgetItem(
            QString::fromUtf8( ":/paintpad/resources/QT_original_R.png" ) );
    createListWidgetItem(
            QString::fromUtf8( ":/paintpad/resources/kopeteavailable.png" ) );
    createListWidgetItem(
            QString::fromUtf8( ":/paintpad/resources/head.png" ) );

    QVBoxLayout* vlay = new QVBoxLayout( this );
    vlay->addWidget( m_listWidget );
    vlay->addWidget( buttons );

    connect( buttons, SIGNAL( accepted() ), this, SLOT( accept() ) );
    connect( buttons, SIGNAL( rejected() ), this, SLOT( reject() ) );
}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
ListViewDialog::~ListViewDialog()
{

}

// ---------------------------------------------------------------------------
// Get the selected icon
// ---------------------------------------------------------------------------
//
QIcon ListViewDialog::icon()
{
    return m_listWidget->currentItem()->icon();
}

// ---------------------------------------------------------------------------
// Create a ListWidget Item by the given file name
// ---------------------------------------------------------------------------
//
void ListViewDialog::createListWidgetItem( const QString& fileName )
{
    new QListWidgetItem(
                        QIcon( fileName ),
                        fileName,
                        m_listWidget,
                        QListWidgetItem::UserType);
}
