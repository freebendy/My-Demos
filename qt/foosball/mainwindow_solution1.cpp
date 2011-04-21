#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

const QString KTeamPrefixText( QObject::tr( "Team%1" ) );
const QString KTeamsFile( "teams.txt"  );
const QString KParticipantsFile( "participants.txt" );

MainWindow::MainWindow( QWidget* parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow ),
    mTeamCount( 0 )
{
    ui->setupUi( this );

    initializeList();

    connect( ui->generateButton, SIGNAL( clicked() ), this, SLOT( generateTeams() ) );
    connect( ui->resetButton, SIGNAL( clicked() ), this, SLOT( reset() ) );

    ui->resetButton->setDisabled( true );
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
            QString participant = textStream.readLine();
            qDebug() << "participant: " << participant;
            mParticipants.append( participant );
            ui->listWidget->addItem( participant );
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
                                QStringList( mParticipants[ mGeneratedIndex[ i*2 ] ] ) ) );
        childItems.append(
            new QTreeWidgetItem( treeItem,
                                QStringList( mParticipants[ mGeneratedIndex[ i*2 + 1 ] ] ) ) );

        treeItem->addChildren( childItems );

        items.append( treeItem );
    }

    ui->treeWidget->insertTopLevelItems( 0, items );
}

void MainWindow::generateTeams()
{
    qDebug() << __FUNCTION__;

    mGeneratedIndex.clear();
    int count = ui->listWidget->count();

    while ( mGeneratedIndex.count() < count )
    {
        int i = qrand() % count ;
        if ( mGeneratedIndex.indexOf( i ) == -1 )
        {
            qDebug() << "i: " << i;
            mGeneratedIndex.append( i );
        }
    }

    QFile file( KTeamsFile );
    if ( file.open( QFile::WriteOnly | QFile::Text ) )
    {
        QTextStream textStream( &file );
        for ( int i = 0; i < mTeamCount; ++i )
        {
            textStream << KTeamPrefixText.arg( i + 1 )
                       << ": "
                       << mParticipants[ mGeneratedIndex[ i*2 ] ]
                       << " & "
                       << mParticipants[ mGeneratedIndex[ i*2 + 1 ] ]
                       << "\n";
        }
        textStream.flush();
        file.close();
    }

    initializeTree();

    ui->generateButton->setDisabled( true );
    ui->resetButton->setDisabled( false );
}

void MainWindow::reset()
{
    qDebug() << __FUNCTION__;

    initializeList();

    ui->treeWidget->clear();

    QFile file( KTeamsFile );
    file.remove();

    ui->generateButton->setDisabled( false );
}
