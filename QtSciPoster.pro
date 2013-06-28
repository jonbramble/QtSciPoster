#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T15:14:06
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSciPoster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    projectmodel.cpp \
    projectitem.cpp \
    posterwebpage.cpp

HEADERS  += mainwindow.h \
    projectmodel.h \
    projectitem.h \
    posterwebpage.h

FORMS    += mainwindow.ui
