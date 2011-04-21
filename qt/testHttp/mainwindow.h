#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QYamHttpEngine;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QYamHttpEngine* mHttpEngine;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
};

#endif // MAINWINDOW_H
