QT      += core gui widgets sql
TARGET   = monthsector
TEMPLATE = app
DESTDIR  = /home/debian/bin

include(src/files.pri)

MOC_DIR = tmp
OBJECTS_DIR = tmp

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

#DISTFILES += \
#    src/files.pri
