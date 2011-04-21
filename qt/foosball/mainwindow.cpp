#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

const QString KTeamPrefixText( QObject::tr( "Team%1" ) );
const QString KRoundPrefixText( QObject::tr( "Round%1" ) );
const QString KTeamsFile( "teams.txt" );
const QString KRoundsFile( "rounds.txt" );
const QString KParticipantsFile( "participants.txt" );

MainWindow::MainWindow( QWidget* parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow ),
    mTeamCount( 0 )
{
    ui->setupUi( this );

    ui->generateRoundsButton->setVisible( false );
    ui->treeWidgetRound->setVisible( false );

    reset();

    connect( ui->generateTeamsButton, SIGNAL( clicked() ), this, SLOT( generateTeams() ) );
    connect( ui->generateRoundsButton, SIGNAL( clicked() ), this, SLOT( generateSchedule() ) );
    connect( ui->resetButton, SIGNAL( clicked() ), this, SLOT( reset() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeList()
{
    qDebug() << __FUNCTION__;

    mParticipants.clear();
    ui->listWidget->clear();

    QFile file( KParticipantsFile );
    if ( file.open( QFile::ReadOnly | QFile::Text ) )
    {
        QTextStream textStream( &file );
        while ( !textStream.atEnd() )
        {
            QString participant = textStream.readLine().trimmed();
//            qDebug() << "participant: " << participant;
            if ( !participant.isEmpty() )
            {
                mParticipants.append( participant );
                ui->listWidget->addItem( participant );
            }
        }
        mTeamCount = mParticipants.count() / 2;

        file.close();
    }
}

void MainWindow::initializeTree()
{
    qDebug() << __FUNCTION__;
    ui->treeWidget->clear();

    QList<QTreeWidgetItem*> items;
    for ( int i = 0; i < mTeamCount; ++i )
    {
        QTreeWidgetItem* treeItem = new QTreeWidgetItem( ui->treeWidget );
        treeItem->setText( 0, KTeamPrefixText.arg( i + 1 ) );
        treeItem->setExpanded( true );

        QList<QTreeWidgetItem*> childItems;
        childItems.append(
            new QTreeWidgetItem( treeItem,
                                QStringList( mParticipants[i*2] ) ) );
        childItems.append(
            new QTreeWidgetItem( treeItem,
                                QStringList( mParticipants[i*2 + 1] ) ) );

        treeItem->addChildren( childItems );

        items.append( treeItem );
    }

    ui->treeWidget->insertTopLevelItems( 0, items );
}

void MainWindow::initializeScheduleTree()
{
    qDebug() << __FUNCTION__;

    ui->treeWidgetRound->clear();

    QList<QTreeWidgetItem*> items;
    for ( int i = 1; i <= mRounds.count(); ++i )
    {
        QTreeWidgetItem* treeItem = new QTreeWidgetItem( ui->treeWidgetRound );
        treeItem->setText( 0, KRoundPrefixText.arg( i ) );
        treeItem->setExpanded( true );

        QList<QTreeWidgetItem*> childItems;

        const QList<int>& gamesList = mRounds[KRoundPrefixText.arg( i )];
        int gamesListLength = gamesList.length();
        for ( int j = 0; j < gamesListLength / 2; ++ j )
        {
            QString game = KTeamPrefixText.arg( gamesList[j] ) + " vs "
                    + KTeamPrefixText.arg( gamesList[gamesListLength - 1 - j] );
            childItems.append(
                new QTreeWidgetItem( treeItem, QStringList( game ) ) );
        }

        treeItem->addChildren( childItems );

        items.append( treeItem );
    }

    ui->treeWidgetRound->insertTopLevelItems( 0, items );
    ui->treeWidgetRound->setVisible( true );
}

void MainWindow::generateTeams()
{
    qDebug() << __FUNCTION__;

    int count = mParticipants.count();
    int times = count;

    qsrand( QDateTime::currentMSecsSinceEpoch() );
    for ( int i = 0; i < times; ++i )
    {
        int randIndex = qrand() % count ;
        int cIndex = i % count;

        if ( cIndex != randIndex )
        {
            qSwap( mParticipants[cIndex], mParticipants[randIndex] );
        }
    }

    QFile file( KTeamsFile );
    if ( file.open( QFile::WriteOnly | QFile::Text ) )
    {
        QTextStream textStream( &file );
        for ( int i = 0; i < mTeamCount; ++i )
        {
            textStream << KTeamPrefixText.arg( i + 1 )
                       << ":\n\t* "
                       << mParticipants[ i*2 ]
                       << "\n\t* "
                       << mParticipants[ i*2 + 1 ]
                       << "\n\n";
        }
        textStream.flush();
        file.close();
    }

    initializeTree();

    ui->generateTeamsButton->setDisabled( true );
    ui->generateRoundsButton->setVisible( true );
    ui->resetButton->setDisabled( false );

}

void MainWindow::reset()
{
    qDebug() << __FUNCTION__;

    initializeList();

    ui->treeWidget->clear();
    ui->treeWidgetRound->clear();
    ui->treeWidgetRound->setVisible( false );

    QFile file( KTeamsFile );
    file.remove();

    QFile roundFile( KRoundsFile );
    roundFile.remove();

    ui->generateTeamsButton->setDisabled( false );
    ui->generateRoundsButton->setDisabled( false );
    ui->generateRoundsButton->setVisible( false );
    ui->resetButton->setDisabled( true );
}

void MainWindow::generateSchedule()
{
    qDebug() << __FUNCTION__;

    ui->generateRoundsButton->setDisabled( true );
    mRounds.clear();

    QList<int> gamesList;
    for ( int i = 1; i <= mTeamCount; ++i )
    {
        gamesList.append( i );
    }

    if ( mTeamCount % 2 != 0 )
    {
        gamesList.append( 0 );
    }

    mRounds[KRoundPrefixText.arg( 1 )] = gamesList;

    for ( int i = 2; i < gamesList.count() ; ++i )
    {
        int temp = gamesList.takeLast();
        gamesList.insert( 1, temp );
        mRounds[KRoundPrefixText.arg( i )] = gamesList;
    }

    QString round;
    foreach ( round, mRounds.keys() )
    {
        qDebug() << "round: " << round
                << "\nmRounds:" << mRounds[round];
    }

    QFile file( KRoundsFile );
    if ( file.open( QFile::WriteOnly | QFile::Text ) )
    {
        QTextStream textStream( &file );
        for ( int i = 1; i <= mRounds.count(); ++i )
        {
            textStream << KRoundPrefixText.arg( i ) << ":\n\t ";
            const QList<int>& gamesList = mRounds[KRoundPrefixText.arg( i )];
            int gamesListLength = gamesList.length();
            for ( int j = 0; j < gamesListLength / 2; ++ j )
            {
                QString game = KTeamPrefixText.arg( gamesList[j] ) + " vs "
                        + KTeamPrefixText.arg( gamesList[gamesListLength - 1 - j] );

                textStream << game << "\n\t ";
            }
        }
        textStream.flush();
        file.close();
    }

    initializeScheduleTree();
}
