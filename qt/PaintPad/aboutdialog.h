#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

/**
* about dialog of paintpad
*/
class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    /**
    * constructor
    *
    * @param parent parent of the dialog
    **/
    AboutDialog( QWidget* parent = 0 );

    /**
    * Destructor
    **/
    ~AboutDialog();

};

#endif // ABOUTDIALOG_H
