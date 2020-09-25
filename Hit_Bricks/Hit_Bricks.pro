#-------------------------------------------------
#
# Project created by QtCreator 2020-09-17T14:29:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hit_Bricks
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    chooselevelwindow.cpp \
    playwindow.cpp \
    ball.cpp \
    platform.cpp \
    dataconfig.cpp \
    brick.cpp \
    item.cpp

HEADERS += \
        mainwindow.h \
    chooselevelwindow.h \
    playwindow.h \
    ball.h \
    platform.h \
    dataconfig.h \
    brick.h \
    item.h

FORMS += \
        mainwindow.ui \
    chooselevelwindow.ui

RESOURCES += \
    res.qrc

