#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shape.h"
#include "shapesetting.h"

class QPushButton;
class QToolButton;
class AboutDialog;
class ListViewDialog;

namespace Ui
{
    class MainWindow;
}

/**
* application main window
*/
class MainWindow : public QMainWindow, public ShapeSetting
{
    Q_OBJECT

public:
    /**
    * constructor
    *
    * @param parent parent of the window
    **/
    explicit MainWindow( QWidget* parent = 0 );

    /**
    * Destructor
    **/
    ~MainWindow();

    /**
    * From ShapeSetting
    * get the opactity of setting
    **/
    float opacity();

    /**
    * From ShapeSetting
    * get the line Szie of setting
    **/
    int lineSize();

    /**
    * From ShapeSetting
    * get the edge size of setting
    **/
    int edgeSize();

    /**
    * From ShapeSetting
    * get the edge color of setting
    **/
    QColor edgeColor();

    /**
    * From ShapeSetting
    * get the frontground color of setting
    **/
    QColor fbColor();

signals:
    /**
    * current shape change signal
    **/
    void changeCurrentShape( Shape::Code );

    /**
    * draw text signal
    **/
    void drawText();

    /**
    * draw image signal
    **/
    void drawImg( QIcon );

    /**
    * load image signal
    **/
    void loadImage( QImage );

    /**
    * save image signal
    **/
    void saveImage( const QString& );

protected:
    /**
    * From QObject
    * event filter
    *
    * @param obj the object posting the event
    * @param event the event to be handled
    **/
     bool eventFilter( QObject* obj, QEvent* event );

private slots:
    // menu
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();

    // toolButtons
    void on_toolButton_line_clicked();
    void on_toolButton_text_clicked();
    void on_toolButton_oval_clicked();
    void on_toolButton_rect_clicked();
    void on_toolButton_star_clicked();
    void on_toolButton_img_clicked();

    // B/F color
    void on_pushButton_f_clicked();
    void on_pushButton_b_clicked();

    //edge color
    void on_pushButton_edgecolor_clicked();

private:
    /**
    * init palette area widgets
    **/
    void initPalette();

    /**
    * init B/F area widgets
    */
    void initBF();

    /**
    * init setting area widgets
    */
    void initSetting();

    /**
    * set the active toolbutton
    *
    * @param toolButton a tool button
    */
    void setActiveToolButton( QToolButton* toolButton );

    /**
    * select color from the color dialog and set the button's palette
    */
    void selecteColor();

private:
    /**
    * point of Ui MainWindow
    */
    Ui::MainWindow* ui;

    /**
    * about dialog
    */
    AboutDialog* m_aboutDialog;

    /**
    * list view dialog
    */
    ListViewDialog* m_listViewDialog;

    /**
    * the button opening the color dialog
    */
    QPushButton* m_activeColorButton;

    /**
    * the active tool button
    */
    QToolButton* m_activeToolButton;

};

#endif // MAINWINDOW_H
