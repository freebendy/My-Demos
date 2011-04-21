#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget* parent = 0 );
    ~MainWindow();

private:

    void initializeList();
    void initializeTree();

private slots:

    void generateTeams();

    void reset();

private:
    Ui::MainWindow* ui;
    QStringList mParticipants;
    QStringList mGenerated;
    int mTeamCount;
};

#endif // MAINWINDOW_H
