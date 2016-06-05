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
    integrate.cpp \
    Matrix_YW.cpp \
    matrix.cpp \
    number.cpp \
    option.cpp \
    equation_xs.cpp \
    linearequtions.cpp \
    praser.cpp \
    rank.cpp \
    eqution.cpp

HEADERS  += mainwindow.h \
    calculus.h \
    integrate.h \
    Matrix_YW.h \
    matrix.h \
    number.h \
    option.h \
    eqution.h \
    lparse.h \
    myerror.h \
    node.h \
    equation_xs.h \
    linearequtions.h \
    lineareuqtions.h \
    rank.h \
    super_eqution.h

FORMS    += \
    matrix.ui \
    number.ui \
    option.ui

CONFIG +=C++11

INCLUDEPATH += E:\myGSL\mygsl\include
LIBS      += -L E:\myGSL\mygsl\lib\libgsl.dll.a
LIBS      += -L E:\myGSL\mygsl\lib\libgslcblas.dll.a
LIBS      += -L E:\myGSL\mygsl\lib\libmygsl.dll.a
LIBS      += -L E:\myGSL\mygsl\lib\libgsl.a
LIBS      += -L E:\myGSL\mygsl\lib\libgslcblas.a
LIBS      += -L E:\myGSL\mygsl\lib\libnlopt-0.a

RESOURCES += \
    exeicon.qrc \
    exeicon.qrc

RC_FILE += exeicon.rc

DISTFILES += \
    exeicon.rc


