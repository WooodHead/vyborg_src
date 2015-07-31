QT += core gui widgets sql
TARGET = safety
TEMPLATE = app

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg


SOURCES += main.cpp \
    maindialog.cpp \
    mapperdialog.cpp

HEADERS  += \
    maindialog.h \
    declarations.h \
    mapperdialog.h
