#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T21:55:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mmglgui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spheredialog.cpp \
    pointlightdialog.cpp \
    cameradialog.cpp \
    ambientlightdialog.cpp \
    triangledialog.cpp

HEADERS  += mainwindow.h \
    spheredialog.h \
    pointlightdialog.h \
    cameradialog.h \
    ambientlightdialog.h \
    triangledialog.h

FORMS    += mainwindow.ui \
    spheredialog.ui \
    pointlightdialog.ui \
    cameradialog.ui \
    ambientlightdialog.ui \
    triangledialog.ui

LIBS += -L/usr/local/lib -lmmgl

INCLUDEPATH += /usr/local/include
