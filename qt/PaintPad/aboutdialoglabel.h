#ifndef DIALOGLABEL_H
#define DIALOGLABEL_H

#include <QWidget>

/**
* label of the about dialog
*/
class AboutDialogLabel : public QWidget
{
public:
    /**
    * constructor
    *
    * @param parent parent of the label
    **/
    AboutDialogLabel( QWidget* parent = 0 );

    /**
    * destructor
    **/
    ~AboutDialogLabel();

    /**
    * set text of the label
    *

    **/
    void setText( const QString& text );

    /**
    * get text of the label
    **/
    QString text() const;

protected:
    /**
    * update the text's painter path
    **/
    void updateTextPath();

    /**
    * From QWidget
    * paint event handler
    *
    * @param paintEvent the paint event
    **/
    void paintEvent( QPaintEvent* paintEvent );

    /**
    * From QWidget
    * resize event handler
    *
    * @param resizeEvent the resize event
    **/
    void resizeEvent( QResizeEvent* resizeEvent );

private:
    /**
    * text of label
    */
    QString m_text;

    /**
    * text's painter path of label
    */
    QPainterPath m_textPath;

    /**
    * text's Gradient of label
    */
    QLinearGradient m_textGradient;

};

#endif // DIALOGLABEL_H
