#-------------------------------------------------
#
# Project created by QtCreator 2014-04-03T20:39:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor
TEMPLATE = app


SOURCES += main.cpp\
        text_editor.cpp \
    exitdialog.cpp \
    insertwidget.cpp \
    deletewidget.cpp \
    showfile.cpp \
    filestatistics.cpp \
    searchforword.cpp \
    replacewidget.cpp

HEADERS  += text_editor.h \
    exitdialog.h \
    insertwidget.h \
    deletewidget.h \
    showfile.h \
    filestatistics.h \
    searchforword.h \
    replacewidget.h

FORMS    += text_editor.ui \
    exitdialog.ui \
    insertwidget.ui \
    deletewidget.ui \
    searchforword.ui \
    replacewidget.ui
