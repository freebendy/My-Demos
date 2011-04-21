#include <QtCore/QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkRequest nr;
    nr.setUrl( QUrl("https://encrypted.google.com/") );
    QNetworkAccessManager nam;
    QNetworkReply* reply = nam.get( nr );

    std::cerr << "11" << std::endl;

    if ( reply )
    {
        std::cerr << "22" << std::endl;
        while( true )
        {
            std::cerr << "33" << std::endl;
            if ( reply->isFinished() )
            {
                qDebug("finish");
                break;
            }
        }
    }

    return a.exec();
}
