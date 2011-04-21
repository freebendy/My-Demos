#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qyamhttpengine.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mHttpEngine = new QYamHttpEngine( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mHttpEngine->getRequestToken();
}

void MainWindow::on_pushButton_4_clicked()
{
    mHttpEngine->getVerifier();
}
