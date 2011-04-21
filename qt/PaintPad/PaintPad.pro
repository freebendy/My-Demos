#-------------------------------------------------
#
# Project created by QtCreator 2010-06-29T16:41:51
#
#-------------------------------------------------

QT       += core gui

TARGET = PaintPad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        aboutdialog.cpp \
        scene.cpp \
        rect.cpp \
        line.cpp \
        oval.cpp \
        star.cpp \
        aboutdialoglabel.cpp \
        listviewdialog.cpp

HEADERS  += mainwindow.h \
        aboutdialog.h \
        scene.h \
        line.h \
        rect.h \
        shape.h \
        oval.h \
        star.h \
        shapesetting.h \
        aboutdialoglabel.h \
        aboutdialoglabel.h \
        listviewdialog.h \
        shapeutils.h

FORMS    += mainwindow.ui

RESOURCES += \
        paintpad.qrc
