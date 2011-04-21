#-------------------------------------------------
#
# Project created by QtCreator 2011-01-12T15:54:03
#
#-------------------------------------------------

QT       += core gui
QT       += network xml

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qyamhttpengine.cpp \
    qyamhttpthread.cpp \
    qyamserviceengine.cpp

HEADERS  += mainwindow.h \
    qyamhttpengine.h \
    qyamhttpthread.h \
    yamserviceengine_global.h \
    qyamserviceengine.h

FORMS    += mainwindow.ui
