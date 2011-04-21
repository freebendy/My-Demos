#include <QFileDialog>
#include <QMouseEvent>
#include <QColorDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "listviewdialog.h"
#include "scene.h"

const qreal SCENERECTX = -500;
const qreal SCENERECTY = -400;
const qreal SCENERECTWIDTH = 1000;
const qreal SCENERECTHEIGHT = 800;

const QString APPNAME = QObject::tr( "PaintPad");
const QString IMAGEFILTER =
        QObject::tr("Images") + QLatin1String("(*.bmp *.jpg *.png)" );
const QString OPENWINTITLE = QObject::tr( "Open Image" );
const QString SAVEWINTITLE = QObject::tr( "Save Image As" );
const QString DEFAULTPATH = QObject::tr( "." );

const double DEFAULTOPACITY = 0.5;
const double DEFAULTLINESIZE = 12;
const double DEFAULTEDGESIZE = 2;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------
//
MainWindow::MainWindow( QWidget* parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow ),
    m_aboutDialog( NULL ),
    m_listViewDialog( NULL ),
    m_activeColorButton( NULL ),
    m_activeToolButton( NULL )
{
    ui->setupUi( this );

    initSetting();

    initBF();

    initPalette();

    ui->graphicsView->setRenderHints( QPainter::Antialiasing );
    Scene* scene = new Scene( *this, ui->graphicsView );
    scene->setSceneRect( SCENERECTX,
                         SCENERECTY,
                         SCENERECTWIDTH,
                         SCENERECTHEIGHT );
    ui->graphicsView->setScene( scene );

    connect( this, SIGNAL( changeCurrentShape( Shape::Code ) ),
            scene, SLOT( setCurrentShape( Shape::Code ) ) );
    connect( this, SIGNAL( drawText() ),scene, SLOT( drawText() ) );
    connect( this, SIGNAL( drawImg( QIcon ) ),
            scene, SLOT( drawImg( QIcon ) ) );
    connect( this, SIGNAL( loadImage( QImage ) ),
            scene, SLOT( loadImage( QImage ) ) );
    connect( this, SIGNAL( saveImage( const QString& ) ),
            scene, SLOT( saveImage( const QString& ) ) );

}

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------------------------------------------------------------------
// Get the opactity of setting
// ---------------------------------------------------------------------------
//
float MainWindow::opacity()
{
    return ui->doubleSpinBox_opacity->value();
}

// ---------------------------------------------------------------------------
// Get the line Szie of setting
// ---------------------------------------------------------------------------
//
int MainWindow::lineSize()
{
    return ui->doubleSpinBox_linesize->value();
}

// ---------------------------------------------------------------------------
// Get the edge size of setting
// ---------------------------------------------------------------------------
//
int MainWindow::edgeSize()
{
    return ui->doubleSpinBox_edgesize->value();
}

// ---------------------------------------------------------------------------
// Get the edge color of setting
// ---------------------------------------------------------------------------
//
QColor MainWindow::edgeColor()
{
    return ui->pushButton_edgecolor->palette().button().color();

}

// ---------------------------------------------------------------------------
// Get the frontground color of setting
// ---------------------------------------------------------------------------
//
QColor MainWindow::fbColor()
{
    return ui->pushButton_f->palette().button().color();
}


// ---------------------------------------------------------------------------
// Event filter
// ---------------------------------------------------------------------------
//
bool MainWindow::eventFilter( QObject* obj, QEvent* event )
{
    //whether the obj's parent is frame_palette.
    if ( obj->parent() == ui->frame_palette && obj->inherits( "QLabel" ) )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>( event );

            QLabel* label = static_cast<QLabel*>( obj );
            if( mouseEvent->button() == Qt::LeftButton )
            {
                ui->pushButton_f->setPalette( label->palette() );
            }
            else
            {
                ui->pushButton_b->setPalette( label->palette() );
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter( obj, event );
    }
}

// menu
void MainWindow::on_actionNew_triggered()
{
    ui->graphicsView->scene()->clear();
}

void MainWindow::on_actionOpen_triggered()
{
    /* Open a file dialog for loading. The default directory is the
     * current directory, the filter *.bmp.
     */
    QString fileName =
            QFileDialog::getOpenFileName(
                    this,
                    OPENWINTITLE,
                    DEFAULTPATH,
                    IMAGEFILTER );

    if ( !fileName.isEmpty() )
    {
        // load the image:
        QImage image;
        if ( !image.load( fileName ) )
        {
            QMessageBox::warning( this, "Load error", "Could not load file" );
            return;
        }
        emit loadImage( image );
    }
}

void MainWindow::on_actionSave_triggered()
{
    /* Open a file dialog for saving. The default directory is the
     * current directory, the filter *.bmp.
     */
    QString fileName =
            QFileDialog::getSaveFileName(
                    this,
                    SAVEWINTITLE,
                    DEFAULTPATH,
                    IMAGEFILTER );

    if( !fileName.isEmpty() )
    {
        emit saveImage( fileName );
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::exit( 0 );
}

void MainWindow::on_actionAbout_triggered()
{
    if( !m_aboutDialog )
    {
        m_aboutDialog = new AboutDialog( this );
        m_aboutDialog->setWindowTitle( APPNAME );
        m_aboutDialog->setModal( true );
    }
    m_aboutDialog->show();
}

// toolButtons
void MainWindow::on_toolButton_line_clicked()
{
    if( ui->toolButton_line->isDown() )
    {
        return;
    }

    setActiveToolButton( ui->toolButton_line );

    ui->label_opacity->setVisible( true );
    ui->doubleSpinBox_opacity->setVisible( true );
    ui->label_linesize->setVisible( true );
    ui->doubleSpinBox_linesize->setVisible( true );
    ui->label_edgesize->setVisible( false );
    ui->doubleSpinBox_edgesize->setVisible( false );
    ui->label_edgecolor->setVisible( false );
    ui->pushButton_edgecolor->setVisible( false );
    ui->frame_setting->setVisible( true );

    emit changeCurrentShape( Shape::Line );
}

void MainWindow::on_toolButton_text_clicked()
{
    setActiveToolButton( NULL );

    ui->frame_setting->setVisible( false );

    emit drawText();
    emit changeCurrentShape( Shape::None );
}

void MainWindow::on_toolButton_oval_clicked()
{
    if( ui->toolButton_oval->isDown() )
    {
        return;
    }

    setActiveToolButton( ui->toolButton_oval );

    ui->label_opacity->setVisible( true );
    ui->doubleSpinBox_opacity->setVisible( true );
    ui->label_linesize->setVisible( false );
    ui->doubleSpinBox_linesize->setVisible( false );
    ui->label_edgesize->setVisible( true );
    ui->doubleSpinBox_edgesize->setVisible( true );
    ui->label_edgecolor->setVisible( true );
    ui->pushButton_edgecolor->setVisible( true );
    ui->frame_setting->setVisible( true );

    emit changeCurrentShape( Shape::Oval );
}

void MainWindow::on_toolButton_rect_clicked()
{
    if( ui->toolButton_rect->isDown() )
    {
        return;
    }

    setActiveToolButton( ui->toolButton_rect );

    ui->label_opacity->setVisible( true );
    ui->doubleSpinBox_opacity->setVisible( true );
    ui->label_linesize->setVisible( false );
    ui->doubleSpinBox_linesize->setVisible( false );
    ui->label_edgesize->setVisible( true );
    ui->doubleSpinBox_edgesize->setVisible( true );
    ui->label_edgecolor->setVisible( true );
    ui->pushButton_edgecolor->setVisible( true );
    ui->frame_setting->setVisible( true );

    emit changeCurrentShape( Shape::Rect );
}

void MainWindow::on_toolButton_star_clicked()
{
    if( ui->toolButton_star->isDown() )
    {
        return;
    }

    setActiveToolButton( ui->toolButton_star );

    ui->label_opacity->setVisible( true );
    ui->doubleSpinBox_opacity->setVisible( true );
    ui->label_linesize->setVisible( false );
    ui->doubleSpinBox_linesize->setVisible( false );
    ui->label_edgesize->setVisible( true );
    ui->doubleSpinBox_edgesize->setVisible( true );
    ui->label_edgecolor->setVisible( true );
    ui->pushButton_edgecolor->setVisible( true );
    ui->frame_setting->setVisible( true );

    emit changeCurrentShape( Shape::Star );
}

void MainWindow::on_toolButton_img_clicked()
{
    setActiveToolButton( NULL );

    ui->frame_setting->setVisible( false );

    if( !m_listViewDialog )
    {
        m_listViewDialog = new ListViewDialog( this );
        m_listViewDialog->setModal( true );
    }

    if( QDialog::Accepted == m_listViewDialog->exec() )
    {
       emit drawImg( m_listViewDialog->icon() );
    }

    emit changeCurrentShape( Shape::None );
}

// color
void MainWindow::on_pushButton_f_clicked()
{
    m_activeColorButton = ui->pushButton_f;
    selecteColor();
}

void MainWindow::on_pushButton_b_clicked()
{
    m_activeColorButton = ui->pushButton_b;
    selecteColor();
}

void MainWindow::on_pushButton_edgecolor_clicked()
{
    m_activeColorButton = ui->pushButton_edgecolor;
    selecteColor();
}

// ---------------------------------------------------------------------------
// Init the palette area widgets
// ---------------------------------------------------------------------------
//
void MainWindow::initPalette()
{
    int init_palette_values[][3] =
        {
        {255, 255, 255},
        {190, 190, 190},
        {255, 0,   0  },
        {255, 255, 0  },
        {0,   255, 0  },
        {0,   255, 255},
        {0,   0,   255},
        {255, 0,   255},
        {255, 255, 121},
        {0,   255, 121},
        {121, 255, 255},
        {134, 125, 255},
        {255, 0,   121},
        {255, 125, 65 },
        {0,   0,   0  },
        {121, 125, 121},
        {121, 0,   0  },
        {121, 130, 0  },
        {0,   125, 0  },
        {0,   125, 121},
        {0,   0,   121},
        {121, 0,   121},
        {121, 125, 65 },
        {0,   65,  65 },
        {0,   130, 255},
        {65,  0,   255},
        {0,   125, 65 },
        {18,  52,  86 }
        };

    int palette_number =
            sizeof( init_palette_values )/sizeof( *init_palette_values );
    for(int i=0; i< palette_number; i++)
    {
        int red   = init_palette_values[i][0];
        int green = init_palette_values[i][1];
        int blue  = init_palette_values[i][2];
        QString label_name = QString( "label_%1" ).arg( i + 1 );
        QLabel* label = ui->frame_palette->findChild<QLabel*>( label_name );
        label->setPalette( QPalette( QColor( red, green, blue ) ) );
        label->setAutoFillBackground( true );
        label->setText( "" );
        label->installEventFilter( this );
    }
}

// ---------------------------------------------------------------------------
// Init the B/F area widgets
// ---------------------------------------------------------------------------
//
void MainWindow::initBF()
{
    ui->pushButton_f->setPalette( QPalette( QColor( Qt::black ) ) );
    ui->pushButton_b->setPalette( QPalette( QColor( Qt::white ) ) );
}

// ---------------------------------------------------------------------------
// Init the setting area widgets
// ---------------------------------------------------------------------------
//
void MainWindow::initSetting()
{
    ui->doubleSpinBox_opacity->setValue( DEFAULTOPACITY );
    ui->doubleSpinBox_linesize->setValue( DEFAULTLINESIZE );
    ui->doubleSpinBox_edgesize->setValue( DEFAULTEDGESIZE );
    ui->pushButton_edgecolor->setPalette( QPalette( QColor( Qt::black ) ) );
    ui->frame_setting->setVisible( false );
}

// ---------------------------------------------------------------------------
// Set the active toolbutton
// ---------------------------------------------------------------------------
//
void MainWindow::setActiveToolButton( QToolButton* toolButton )
{
    if( m_activeToolButton != toolButton )
    {
        if( m_activeToolButton &&  m_activeToolButton->isDown() )
        {
            m_activeToolButton->setDown( false );
        }

        m_activeToolButton = toolButton;

        if( m_activeToolButton )
        {
            m_activeToolButton->setDown( true );
        }
    }
}

// ---------------------------------------------------------------------------
// select color from the color dialog and set the button's palette
// ---------------------------------------------------------------------------
//
void MainWindow::selecteColor()
{
    QColor color = QColorDialog::getColor( Qt::black, this );
    if( color.isValid() && m_activeColorButton )
    {
        m_activeColorButton->setPalette( QPalette( color ) );
    }
}
