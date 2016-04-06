QT -= gui
QT += widgets sql
CONFIG += install
TARGET = vyborg
TEMPLATE = lib
VERSION = 1.5
DEFINES += LIBVYBORG_LIBRARY

OBJECTS_DIR = tmp
MOC_DIR = tmp

SUBDIRS = test

include(src/files.pri)

DIR_PREFIX = /usr/local
HEADERS_INSTALL_DIR = $$DIR_PREFIX/include/$$TARGET
LIBS_INSTALL_DIR = $$DIR_PREFIX/lib/$$TARGET

unix {
    headers.extra = mkdir -p $$HEADERS_INSTALL_DIR
    headers.files = $$HEADERS
    headers.path = $$HEADERS_INSTALL_DIR
    INSTALLS += headers

    features.extra = echo $$TARGET.prf
    features.files = vyborg.prf
    features.path = $$QMAKESPEC/../features/unix
    INSTALLS += features

#    endup.extra = make install
##    endup.path = $$PWD
#    INSTALLS += endup
}

DESTDIR = $$LIBS_INSTALL_DIR

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    vyborg.prf

