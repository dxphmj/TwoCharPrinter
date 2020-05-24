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
    ClassMessage.cpp \
    roll.cpp \
    paramsettingform.cpp \
    fileeditchild.cpp \
    filemanagechild.cpp \
    printsetting.cpp \
    syssetting.cpp \
    countsetting.cpp \
    aboutmac.cpp \
    variblewidget.cpp \
    automessagebox.cpp \
    BarcodeOBJ.cpp \
    BmpObj.cpp \
    DMcodeOBJ.cpp \
    keyboard.cpp \
    language.cpp \
    lineedit_click.cpp \
    ModuleMain.cpp \
    numkeyboard.cpp \
    OBJ_Control.cpp \
    ParamSetting.cpp \
    PrintCreatThread.cpp \
    PrintShowThread.cpp \
    PrintThead.cpp \
    QRcodeOBJ.cpp \
    SerialOBJ.cpp \
    symbolwidget.cpp \
    TextOBJ.cpp \
    timecustom.cpp \
    TimeOBJ.cpp \
    UILanguage.cpp \
    variablebarcode.cpp \
    variabledm.cpp \
    variableqr.cpp \
    backend/2of5.c \
    backend/auspost.c \
    backend/aztec.c \
    backend/bmp.c \
    backend/codablock.c \
    backend/code.c \
    backend/code1.c \
    backend/code16k.c \
    backend/code49.c \
    backend/code128.c \
    backend/common.c \
    backend/composite.c \
    backend/dllversion.c \
    backend/dmatrix.c \
    backend/dotcode.c \
    backend/eci.c \
    backend/emf.c \
    backend/gb2312.c \
    backend/gb18030.c \
    backend/general_field.c \
    backend/gif.c \
    backend/gridmtx.c \
    backend/gs1.c \
    backend/hanxin.c \
    backend/imail.c \
    backend/large.c \
    backend/library.c \
    backend/mailmark.c \
    backend/maxicode.c \
    backend/medical.c \
    backend/pcx.c \
    backend/pdf417.c \
    backend/plessey.c \
    backend/png.c \
    backend/postal.c \
    backend/ps.c \
    backend/qr.c \
    backend/raster.c \
    backend/reedsol.c \
    backend/rss.c \
    backend/sjis.c \
    backend/svg.c \
    backend/telepen.c \
    backend/tif.c \
    backend/ultra.c \
    backend/upcean.c \
    backend/vector.c \
    qrcode/bitstream.c \
    qrcode/mask.c \
    qrcode/mmask.c \
    qrcode/mqrspec.c \
    qrcode/qrencode.c \
    qrcode/qrinput.c \
    qrcode/qrspec.c \
    qrcode/rscode.c \
    qrcode/split.c \
    wordStock/Dom.cpp \
    wordStock/GetHZinfo.cpp \
    xml/tinystr.cpp \
    xml/tinyxml.cpp \
    xml/tinyxmlerror.cpp \
    xml/tinyxmlparser.cpp

HEADERS  += mainwindow.h \
    ClassMessage.h \
    roll.h \
    filemanageform.h \
    paramsettingform.h \
    fileeditchild.h \
    filemanagechild.h \
    printsetting.h \
    syssetting.h \
    countsetting.h \
    aboutmac.h \
    variblewidget.h \
    automessagebox.h \
    BarcodeOBJ.h \
    BmpObj.h \
    DMcodeOBJ.h \
    keyboard.h \
    language.h \
    lineedit_click.h \
    ModuleMain.h \
    numkeyboard.h \
    OBJ_Type.h \
    ParamSetting.h \
    PrintCreatThread.h \
    PrintShowThread.h \
    PrintThead.h \
    QRcodeOBJ.h \
    SerialOBJ.h \
    symbolwidget.h \
    TextOBJ.h \
    timecustom.h \
    TimeOBJ.h \
    UILanguage.h \
    variablebarcode.h \
    variabledm.h \
    variableqr.h \
    backend/aztec.h \
    backend/bmp.h \
    backend/code1.h \
    backend/code49.h \
    backend/common.h \
    backend/composite.h \
    backend/dmatrix.h \
    backend/eci.h \
    backend/emf.h \
    backend/font.h \
    backend/gb2312.h \
    backend/gb18030.h \
    backend/general_field.h \
    backend/gridmtx.h \
    backend/gs1.h \
    backend/hanxin.h \
    backend/large.h \
    backend/maxicode.h \
    backend/ms_stdint.h \
    backend/pcx.h \
    backend/pdf417.h \
    backend/qr.h \
    backend/reedsol.h \
    backend/rss.h \
    backend/sjis.h \
    backend/stdint_msvc.h \
    backend/tif.h \
    backend/zint.h \
    qrcode/bitstream.h \
    qrcode/config.h \
    qrcode/mask.h \
    qrcode/mmask.h \
    qrcode/mqrspec.h \
    qrcode/qrencode.h \
    qrcode/qrencode_inner.h \
    qrcode/qrinput.h \
    qrcode/qrspec.h \
    qrcode/rscode.h \
    qrcode/split.h \
    wordStock/Dom.h \
    wordStock/GetHZinfo.h \
    xml/tinystr.h \
    xml/tinyxml.h

FORMS    += mainwindow.ui \
    filemanageform.ui \
    paramsettingform.ui \
    filemanagechild.ui \
    fileeditchild.ui \
    printsetting.ui \
    syssetting.ui \
    countsetting.ui \
    aboutmac.ui \
    variblewidget.ui \
    keyboard.ui \
    language.ui \
    numkeyboard.ui \
    symbolwidget.ui \
    timecustom.ui \
    variablebarcode.ui \
    variabledm.ui \
    variableqr.ui

RESOURCES += \
    Res.qrc

DEFINES += NO_PNG

DEFINES += BIG_CHAR

DEFINES += qtPath
