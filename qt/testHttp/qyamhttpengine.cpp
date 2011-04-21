#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QImageReader>
#include <QImage>
#include <QTime>

#include "qyamhttpengine.h"
#include "qyamhttpthread.h"
#include <QtDebug>
#include <QDomDocument>
#include <QNetworkCookie>

QYamHttpEngine::QYamHttpEngine( QObject *parent ) :
    QObject( parent )
{
    mNetAccessMgr.reset( new QNetworkAccessManager( this ) );
    mNetAccessMgr->setCookieJar( new QNetworkCookieJar( mNetAccessMgr.data() ) );
    QObject::connect( mNetAccessMgr.data(), SIGNAL(finished(QNetworkReply*)),
             this, SLOT(slotFinished(QNetworkReply*)) );

}

QYamHttpEngine::~QYamHttpEngine()
{
}

int QYamHttpEngine::create()
{
    int ret = -1;
    mThread.reset( new QYamHttpThread() );
    if ( mThread )
    {
        mThread->start();
        ret = 0;
    }
    return ret;
}

void QYamHttpEngine::getVerifier()
{
    QUrl url("https://www.yammer.com/oauth/authorize");

    url.setHost("www.yammer.com");
    url.setPath("/oauth/authorize");
    QNetworkRequest request( url );
    request.setHeader( QNetworkRequest::ContentTypeHeader,
                       "application/x-www-form-urlencoded" );

    QByteArray params;
    QString token = "oauth_token=";
    token.append( mRequestToken );
    params.append( token );

    request.setHeader( QNetworkRequest::ContentLengthHeader,
                      params.length() );

    QList<QNetworkCookie>  cookies = mNetAccessMgr->cookieJar()->cookiesForUrl( url );
    QVariant var;
    var.setValue( cookies );

    request.setHeader( QNetworkRequest::CookieHeader, var );
    mReply = mNetAccessMgr->post( request, params );
}

void QYamHttpEngine::getRequestToken()
{
    QUrl url("https://www.yammer.com/oauth/request_token");

    url.setPath("/oauth/request_token");
    QNetworkRequest request( url );

    request.setHeader( QNetworkRequest::ContentTypeHeader,
                       "application/x-www-form-urlencoded" );

//    QString timestamp = QString::number(QDateTime::currentDateTimeUtc().toTime_t());

    QByteArray params;
    params.append("oauth_consumer_key=wwZMGhr8zFH1mDHb2nwHRw");
    params.append("&oauth_signature_method=HMAC-SHA1");
    params.append("&oauth_timestamp=1294987146" );
    params.append("&oauth_nonce=IGATyi" );
    params.append("&oauth_signature=edmVp3pThd7gdmnTw0feSPhqWYk%3D");

    request.setHeader( QNetworkRequest::ContentLengthHeader, params.length() );

    printRequestHeaders( request );

    mReply = mNetAccessMgr->post( request, params );
}

void QYamHttpEngine::printRequestHeaders( const QNetworkRequest& aRequest )
{
    qDebug() << "============request header begin=============";
    QList<QByteArray> requestHeaderList = aRequest.rawHeaderList();
    for ( int i = 0; i < requestHeaderList.count(); ++ i )
    {
        qDebug() << "header: " << requestHeaderList[i].constData();
    }
    qDebug() << "============request header end===============\n";
}

void QYamHttpEngine::printReplyHeaders( const QNetworkReply& aReply )
{
    qDebug() << "============response header begin=============";
    QList<QByteArray> replyHeaderList = aReply.rawHeaderList();
    for ( int i = 0; i < replyHeaderList.count(); ++ i )
    {
        qDebug() << "header: " << replyHeaderList[i].constData()
                << "value: " << aReply.rawHeader( replyHeaderList[i] ).constData();
    }
    qDebug() << "============response header end===============\n";
}

void QYamHttpEngine::printRequestCookies( const QNetworkRequest& aRequest )
{
    qDebug() << "============request cookies begin=============";
    QVariant cookieHeader = aRequest.header( QNetworkRequest::CookieHeader );
    QList<QNetworkCookie> cookieList;
    if ( cookieHeader.canConvert< QList<QNetworkCookie> >() )
    {
        cookieList = cookieHeader.value< QList<QNetworkCookie> >();
        for ( int i = 0; i < cookieList.count(); ++i )
        {
            QNetworkCookie cookie = cookieList[i];
            qDebug() << "cookie name: " << cookie.name().constData()
                    <<"\ncookie value: " << cookie.value().constData();
        }
    }
    qDebug() << "============request cookies end===============\n";
}

void QYamHttpEngine::printCookieJar( const QUrl& aUrl )
{
    qDebug() << "============cookie jar begin=============";
    QList<QNetworkCookie>  cookies = mNetAccessMgr->cookieJar()->cookiesForUrl(aUrl);
    qDebug() << "COOKIES for" << aUrl.host() << cookies;
    qDebug() << "============cookie jar end===============\n";
}

void QYamHttpEngine::slotFinished( QNetworkReply *reply )
{
    // Reading attributes of the reply
    // e.g. the HTTP status code
    QVariant statusCodeV =
    reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    qDebug( "statusCode=%d", statusCodeV.toInt() );
    QByteArray bytes = reply->readAll();
    QString data( bytes.constData() );
//    qDebug() << "content :\n"<< data;

    QVariant setCookieHeader = reply->header( QNetworkRequest::SetCookieHeader );

//    qDebug() << "cookie type : " << setCookieHeader.type() << "\ntypeName : "
//        << setCookieHeader.typeName() << "\nuserType: "<< setCookieHeader.userType();//setCookieHeader.toByteArray();

    QList<QNetworkCookie> cookieList;
    if ( setCookieHeader.canConvert< QList<QNetworkCookie> >() )
    {
        cookieList = setCookieHeader.value< QList<QNetworkCookie> >();

//        for ( int i = 0; i < cookieList.count(); ++i )
//        {
//            QNetworkCookie cookie = cookieList[i];
//            qDebug() << "cookie name: " << cookie.name().constData()
//                    <<"\ncookie value: " << cookie.value().constData();
//        }

//        QNetworkCookieJar* cookieJar = new QNetworkCookieJar( mNetAccessMgr );
//        cookieJar->setCookiesFromUrl( cookieList, QUrl( "https://www.yammer.com" ) );
//        mNetAccessMgr->setCookieJar( cookieJar );
    }

    if ( statusCodeV.toInt() == 302 )
    {
//        QNetworkRequest replyRequest = mReply->request();
//        qDebug() << "request.url = " << replyRequest.url().toString();

//        QVariant locationV = reply->header( QNetworkRequest::LocationHeader );
//        QString redirectString = locationV.toString();
//        qDebug() << "location : " << redirectString;

        QVariant redirectionTargetUrl =
        reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        QUrl redirectionUrl;
        if ( redirectionTargetUrl.canConvert<QUrl>() )
        {
            redirectionUrl = redirectionTargetUrl.value<QUrl>();
            qDebug()<< " redirectionUrl : " << redirectionUrl.toString();
        }

//        if ( redirectionUrl.url() == QUrl( "https://www.yammer.com/session" ) )
//        {
//             redirectionUrl.setPath("/");
//        }
//        else
            if ( redirectionUrl.toString() == "https://www.yammer.com/login" )
        {
            redirectionUrl.setPath("/login");
            QNetworkRequest request( redirectionUrl );
//            request.setHeader( QNetworkRequest::CookieHeader, setCookieHeader );

            QList<QNetworkCookie>  cookies = mNetAccessMgr->cookieJar()->cookiesForUrl( redirectionUrl );
            QVariant var;
            var.setValue( cookies );
            request.setHeader( QNetworkRequest::CookieHeader, var );

            mReply = mNetAccessMgr->get( request );
        }
        else if ( redirectionUrl.toString() == "https://www.yammer.com/" )
        {
//            redirectionUrl.setPath("/");
            redirectionUrl.setPath("/login");
            QNetworkRequest request( redirectionUrl );
//            request.setHeader( QNetworkRequest::CookieHeader, setCookieHeader );
            QList<QNetworkCookie>  cookies = mNetAccessMgr->cookieJar()->cookiesForUrl( redirectionUrl );
            QVariant var;
            var.setValue( cookies );
            mReply = mNetAccessMgr->get( request );
        }
    }
    else if ( statusCodeV.toInt() == 200 )
    {
        if ( reply->url().toString() == "https://www.yammer.com/login" )
        {
            QString subStr = "<meta name=\"authenticity_token\" id=\"authenticity_token\" content=";
            int index = data.indexOf( subStr );
            qDebug() << "index = " << index;
            int beginIndex = index + subStr.length();
            int firstQuoteIndex = data.indexOf( "\"", beginIndex );
            qDebug() << "firstQuoteIndex = " << firstQuoteIndex;
            int secondQuoteIndex = data.indexOf( "\"", firstQuoteIndex + 1 );
            qDebug() << "secondQuoteIndex = " << secondQuoteIndex;

            QString token = data.mid( firstQuoteIndex + 1, secondQuoteIndex - firstQuoteIndex - 1 );
            qDebug() << "token = " << token;

            QUrl url( "https://www.yammer.com" );
            url.setPath( "/session");
            QNetworkRequest request( url );
            request.setRawHeader("Referer", "https://www.yammer.com/login");

            QList<QNetworkCookie>  cookies = mNetAccessMgr->cookieJar()->cookiesForUrl( url );
            QVariant var;
            var.setValue( cookies );

            QByteArray params;
            QString tokenParam("authenticity_token");
            tokenParam.append( token );
            params.append( tokenParam );
            params.append("&login=Binghua.guan%40tieto.com");
            params.append("&password=test4yammer");
            mReply = mNetAccessMgr->post( request, params );
        }
        else
        {
            printCookieJar( reply->url() );
//            printRequestCookies( reply->request() );
            printReplyHeaders( *reply );

            qDebug() << "content :\n"<< data;
            QString equalMark = "=";
            QString sep = "&";
            int begin = data.indexOf( equalMark );
            int end = data.indexOf( sep );
            mRequestToken = data.mid( begin + 1, end - begin - 1 );

            begin = data.indexOf( equalMark, end );
            end = data.indexOf( sep, begin );
            mRequestSecret = data.mid( begin + 1, end - begin - 1 );
            qDebug() << "request token: " << mRequestToken << "\nrequest secret: " << mRequestSecret;
        }
    }
}

