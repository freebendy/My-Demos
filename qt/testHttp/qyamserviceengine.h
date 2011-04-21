#ifndef QYAMSERVICEENGINE_H
#define QYAMSERVICEENGINE_H

#include <QObject>
#include "yamserviceengine_global.h"

class QYamServiceEngine: public QObject
{
    Q_OBJECT

public:

    QYamServiceEngine( QObject* aParent = 0 );

public: // New functions

    void login( const QString& aAccount, const QString& aPassword );

private: // New functions

    void getRequestToken();

    void getAcessToken();

private Q_SLOTS:


Q_SIGNALS:


private:


};

#endif // QYAMSERVICEENGINE_H
