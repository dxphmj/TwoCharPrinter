#-------------------------------------------------
#
# Project created by QtCreator 2020-01-06T09:37:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HighResolutionPrinter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filemanageform.cpp \
    paramsettingform.cpp \
    fileeditchild.cpp \
    filemanagechild.cpp \
    printsetting.cpp \
    syssetting.cpp \
    countsetting.cpp \
    aboutmac.cpp \
    variblewidget.cpp

HEADERS  += mainwindow.h \
    filemanageform.h \
    paramsettingform.h \
    fileeditchild.h \
    filemanagechild.h \
    printsetting.h \
    syssetting.h \
    countsetting.h \
    aboutmac.h \
    variblewidget.h

FORMS    += mainwindow.ui \
    filemanageform.ui \
    paramsettingform.ui \
    filemanagechild.ui \
    fileeditchild.ui \
    printsetting.ui \
    syssetting.ui \
    countsetting.ui \
    aboutmac.ui \
    variblewidget.ui

RESOURCES += \
    Res.qrc
