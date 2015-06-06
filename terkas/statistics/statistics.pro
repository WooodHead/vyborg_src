QT       += core gui sql widgets

TARGET   =  terkas_statistics
TEMPLATE =  app

OBJECTS_DIR = tmp
MOC_DIR = tmp


SOURCES +=  \
    src/main.cpp \
    src/maindialog.cpp \
    src/mapperdialog.cpp \
    src/tabledelegate.cpp

HEADERS  += \
    src/declarations.h \
    src/maindialog.h \
    src/mapperdialog.h \
    src/tabledelegate.h

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg
