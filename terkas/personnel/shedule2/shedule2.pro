QT       += core gui widgets sql
CONFIG   += vyborg
TARGET   = shedule2
TEMPLATE = app

OBJECTS_DIR = tmp
MOC_DIR = tmp

#include(src/files.pri)

QMAKESPEC += /home/kubuntu/Programming/Qt/qt5/qtbase/mkspecs/features/unix

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

SOURCES += main.cpp \
    maindialog.cpp \
    mapperdialog.cpp \
    persontabledelegate.cpp \
    tablemodel.cpp \
    personwidget.cpp

HEADERS  += \
    maindialog.h \
    declarations.h \
    mapperdialog.h \
    persontabledelegate.h \
    tablemodel.h \
    personwidget.h
