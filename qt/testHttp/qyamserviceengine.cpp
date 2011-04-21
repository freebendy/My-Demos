#include "qyamserviceengine.h"
#include "qyamhttpengine.h"

QYamServiceEngine::QYamServiceEngine( QObject* aParent ):
    QObject( aParent )
{
}

void QYamServiceEngine::getRequestToken()
{
    QYamHttpEngine* httpEngine = new QYamHttpEngine();
}
