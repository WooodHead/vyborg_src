QT += core gui widgets sql
TARGET = node_ad
TEMPLATE = app
CONFIG += vyborg
DESTDIR = /home/debian/Programming/bin

include(src/files.pri)

#CONFIG(release) {
#    DESTDIR = ../.build/build-$$TARGET-Release
#}

#OUT_PWD = $$DESTDIR
OBJECTS_DIR = tmp
MOC_DIR = tmp
#RCC_DIR = $$DESTDIR/.rcc
#UI_DIR = $$DESTDIR/.ui

#DISTFILES += \
#    src/files.pri

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg


