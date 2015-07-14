QT      += core gui widgets
TARGET   = monthsector
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

MOC_DIR = tmp
OBJECTS_DIR = tmp

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg
