#-------------------------------------------------
#
# Project created by QtCreator 2016-02-07T16:45:16
#
#-------------------------------------------------

QT       -= gui

TARGET = libavia
TEMPLATE = lib

DEFINES += LIBAVIA_LIBRARY

SOURCES += libavia.cpp

HEADERS += libavia.h\
        libavia_global.h

unix {
    target.path = /usr/local/lib/avia
    INSTALLS += target
}
