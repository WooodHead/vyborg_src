QT += core gui widgets sql
TARGET = quota
TEMPLATE = app
DESTDIR = /home/debian/bin

MOC_DIR = tmp
OBJECTS_DIR = tmp

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

include(src/files.pri)

#DISTFILES += \
#    src/files.pri
