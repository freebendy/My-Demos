#ifndef QYAMHTTPENGINE_H
#define QYAMHTTPENGINE_H

#include <QObject>
#include <QScopedPointer>
//#include <QNetworkReply>

class QUrl;
class QNetworkReply;
class QNetworkRequest;
class QYamHttpThread;
class QNetworkAccessManager;

class QYamHttpEngine : public QObject
{
    Q_OBJECT
public:

    /**
     * Constructor.
     */
    explicit QYamHttpEngine(QObject *parent = 0);

    /**
     * Destructor.
     */
    ~QYamHttpEngine();

public:

    /**
     * Create the http engine.
     */
    int create();

    void getVerifier();

    void getRequestToken();

private:
    void printRequestHeaders( const QNetworkRequest& aRequest );
    void printReplyHeaders( const QNetworkReply& aReply );

    void printRequestCookies( const QNetworkRequest& aRequest );
    void printCookieJar( const QUrl& aUrl );

Q_SIGNALS:

public slots:

    /**
     * Slot to process reply when the QNetworkAccessManager::finished signal is
     * received, the HTTP request is completed.
     *
     * @param reply Pointer to http reply, we take ownership of the reply object
     *              and therefore need to handle deletion.
     */
    void slotFinished( QNetworkReply* reply );


private: // Data

    /**
     * Http thread.
     */
    QScopedPointer<QYamHttpThread>  mThread;

    QScopedPointer<QNetworkAccessManager> mNetAccessMgr;

    QByteArray mAccessToken;

    QNetworkReply* mReply;

    QString mRequestToken;
    QString mRequestSecret;

};

#endif // QYAMHTTPENGINE_H
