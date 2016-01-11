QT     += core gui widgets sql
CONFIG += vyborg
TARGET = person
TEMPLATE = app
DESTDIR = /home/debian/Programming/bin


OBJECTS_DIR = tmp
MOC_DIR = tmp


QMAKESPEC = /usr/src/vyborg/libvyborg/

include(src/files.pri)


INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

