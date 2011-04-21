#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

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

    void initializeScheduleTree();

private slots:

    void generateTeams();

    void reset();

    void generateSchedule();

private:
    Ui::MainWindow* ui;
    QStringList mParticipants;
    int mTeamCount;
    QMap< QString,QList<int> > mRounds;
};

#endif // MAINWINDOW_H
