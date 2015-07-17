QT      += core gui widgets sql
TARGET   = monthsector
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mapperdialog.cpp \
    tabledelegate.cpp

HEADERS  += dialog.h \
    declarations.h \
    mapperdialog.h \
    tabledelegate.h

MOC_DIR = tmp
OBJECTS_DIR = tmp

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg
