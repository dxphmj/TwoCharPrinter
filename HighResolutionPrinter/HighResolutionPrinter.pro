#-------------------------------------------------
#
# Project created by QtCreator 2020-01-04T22:02:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HighResolutionPrinter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filemanageform.cpp \
    paramsettingform.cpp

HEADERS  += mainwindow.h \
    filemanageform.h \
    paramsettingform.h

FORMS    += mainwindow.ui \
    filemanageform.ui \
    paramsettingform.ui

RESOURCES += \
    Res.qrc
