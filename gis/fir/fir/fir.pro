QT += core gui widgets sql
TARGET = vyborg_fir_fir
TEMPLATE = app
CONFIG += vyborg
DESTDIR = /home/debian/Programming/bin

include(src/files.pri)

OBJECTS_DIR = tmp
MOC_DIR = tmp

DISTFILES += \
    src/files.pri
