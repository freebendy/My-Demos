#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QNetworkAccessManager;
class TestThread;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void addTask( int aNum );

private slots:
    void onHttpButtonClicked();

private:
    Ui::MainWindow *ui;
    QScopedPointer<QNetworkAccessManager> mNetworkAccessManager;
    QScopedPointer<TestThread> mTestThread;

};

#endif // MAINWINDOW_H
