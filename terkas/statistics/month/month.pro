QT += core gui widgets sql
TEMPLATE = app
CONFIG += vyborg
TARGET = vyborg_statistics_month
DESTDIR = /home/debian/Programming/bin

OBJECTS_DIR = tmp
MOC_DIR = tmp

include(src/files.pri)

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

#DISTFILES += \
#    src/files.pri


