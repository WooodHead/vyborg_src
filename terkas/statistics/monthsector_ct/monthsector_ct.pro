QT += core gui widgets sql
TARGET = monthsector_ct
TEMPLATE = app
DESTDIR = /home/debian/bin
#CONFIG += vyborg

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

#OBJECTS_DIR = tmp
#MOC_DIR = tmp


include(src/files.pri)

