QT       += core gui widgets sql

TARGET = sector
TEMPLATE = app

OBJECTS_DIR = tmp
MOC_DIR = tmp


include(src/files.pri)
SUBDIRS = src

#DISTFILES += \
#    src/files.pri

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg
