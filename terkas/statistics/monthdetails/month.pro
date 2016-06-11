QT       += core gui sql widgets
TARGET   =  statistics_month
TEMPLATE =  app
DESTDIR = /home/debian/bin

QMAKESPEC += $$QT_INSTALL_DIR/qtbase/mkspecs/features/
CONFIG += vyborg

OBJECTS_DIR = tmp
MOC_DIR = tmp

DEPENDPATH += . \
    src

#DISTFILES += \
#    src/files.pri

include(src/files.pri)

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg



