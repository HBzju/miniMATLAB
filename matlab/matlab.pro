#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T00:23:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = matlab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculus.cpp \
    integrate.cpp

HEADERS  += mainwindow.h \
    calculus.h \
    integrate.h

FORMS    += mainwindow.ui
