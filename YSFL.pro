#-------------------------------------------------
#
# Project created by QtCreator 2016-06-17T00:11:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YSFL
TEMPLATE = app


SOURCES += main.cpp\
        maindisplayport.cpp \
    class_cellular_automata.cpp \
    identity.cpp

HEADERS  += maindisplayport.hpp \
    class_cellular_automata.hpp \
    identity.h

FORMS    += maindisplayport.ui

RESOURCES += \
    res.qrc \
    imagefile.qrc


