#ifndef LISTVIEWDIALOG_H
#define LISTVIEWDIALOG_H

#include <QDialog>
#include <QIcon>

class QListWidget;
/**
* list view dialog for choosing image to draw
*/
class ListViewDialog : public QDialog
{
    Q_OBJECT

public:
    /**
    * constructor
    *
    * @param parent parent of the dialog
    **/
    ListViewDialog( QWidget* parent = 0 );

    /**
    * destructor
    **/
    ~ListViewDialog();

    /**
    * get the selected icon
    **/
    QIcon icon();

private:
    /**
    * constructor
    *
    * @param fileName file or resource name
    **/
    void createListWidgetItem( const QString& fileName );

private:
    /**
    * listwidget of the dialog
    **/
    QListWidget* m_listWidget;

};

#endif // LISTVIEWDIALOG_H
