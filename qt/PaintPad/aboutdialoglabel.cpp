#include <QPainter>
#include "aboutdialoglabel.h"

const qreal PENWIDTH = 2;
const qreal ORIGINX = 0;
const qreal ORIGINY = 0;
const qreal GRADIENTSTART = 0.2;
const qreal GRADIENTMID = 0.6;
const qreal GRADIENTEND = 1;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
AboutDialogLabel::AboutDialogLabel( QWidget* parent ) :
        QWidget( parent )
{

}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
AboutDialogLabel::~AboutDialogLabel()
{

}

// ---------------------------------------------------------------------------
// Set the label's text
// ---------------------------------------------------------------------------
//
void AboutDialogLabel::setText( const QString& text )
{
    if( m_text == text )
        return;

    m_text = text;
    updateTextPath();
    update();
}

// ---------------------------------------------------------------------------
// get the label's text
// ---------------------------------------------------------------------------
//
QString AboutDialogLabel::text() const
{
    return m_text;
}

// ---------------------------------------------------------------------------
// update the text's painter path
// ---------------------------------------------------------------------------
//
void AboutDialogLabel::updateTextPath()
{
    // Figure out the font size based on the height of the widget
    QFontMetrics fm = this->fontMetrics();
    QRect actualTextRect = fm.boundingRect( m_text );
    QRect requiredRect = this->rect();

    double zoomFactor = 1;
    if( actualTextRect.width() > actualTextRect.height() )
    {
        zoomFactor = requiredRect.height() / actualTextRect.height();
    }
    else
    {
        zoomFactor = requiredRect.width() / actualTextRect.width();
    }
    zoomFactor /= 4;

    // Create a font of that size first
    QFont font = this->font();
    font.setPointSize( font.pointSize() * int( zoomFactor ) );

    // Find out the rectangle of the text
    QRect textRect = QFontMetrics( font ).boundingRect( m_text );

    // Place the textRect at the center.
    QPoint disp = this->rect().center() - textRect.center();
    textRect.moveTopLeft( textRect.topLeft() + disp );

    // Create a path for the text path
    QPainterPath path;
    path.addText( textRect.bottomLeft(), font, m_text );

    m_textPath = path;

    update();
}

// ---------------------------------------------------------------------------
// Paint event handler
// ---------------------------------------------------------------------------
//
void AboutDialogLabel::paintEvent( QPaintEvent* paintEvent )
{
    Q_UNUSED( paintEvent );

    QPainter painter( this );
    painter.setRenderHint( QPainter::Antialiasing, true );

    // Now create the gradient
    QLinearGradient gradient( ORIGINX, ORIGINY, width(), height() );
    gradient.setColorAt( GRADIENTSTART, Qt::red );
    gradient.setColorAt( GRADIENTMID, Qt::green );
    gradient.setColorAt( GRADIENTEND, Qt::blue );
    QBrush brush( gradient );
    QPen pen( brush, PENWIDTH );
    pen.setStyle( Qt::SolidLine );
    painter.setPen( pen );

    painter.drawPath( m_textPath );
}

// ---------------------------------------------------------------------------
// Resize event handler
// ---------------------------------------------------------------------------
//
void AboutDialogLabel::resizeEvent( QResizeEvent* resizeEvent )
{
    Q_UNUSED( resizeEvent );
    updateTextPath();
}
