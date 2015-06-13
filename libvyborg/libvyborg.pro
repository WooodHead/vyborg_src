QT -= gui
QT += widgets sql
CONFIG += install
TARGET = vyborg
TEMPLATE = lib

OBJECTS_DIR = tmp
MOC_DIR = tmp

DEFINES += LIBVYBORG_LIBRARY

SUBDIRS += src \
    include \
    test
test.depends = $$SUBDIRS

INCLUDEPATH += include
include(src/files.pri)


HEADERS_INSTALL_DIR = /usr/local/include/$$TARGET
LIBS_INSTALL_DIR = /usr/local/lib/$$TARGET
QT_INSTALL_DIR = /usr/local/src/Qt/Qt5.5.0/5.5/Src/
FEATURES_INSTALL_DIR = $$QT_INSTALL_DIR/qtbase/mkspecs/features/unix

unix {
    headers.extra = mkdir -p $$HEADERS_INSTALL_DIR
    headers.files = $$HEADERS
    headers.path = $$HEADERS_INSTALL_DIR
    INSTALLS += headers

    features.files = features/vyborg.prf
    features.path = $$FEATURES_INSTALL_DIR
    INSTALLS += features
}

DESTDIR = $$LIBS_INSTALL_DIR

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    features/vyborg.prf

#DISTFILES += \
#    src/files.pri
