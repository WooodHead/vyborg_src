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

SOURCES += \
    src/libvyborg.cpp \
    src/vyborg_maindialog.cpp \
    src/vyborg_mapperdialog.cpp \
    src/vyborg_mappercontrolbuttonbox.cpp \
    src/vyborg_navigationbuttonbox.cpp \
    src/vyborg_maindialogcontrolbuttonbox.cpp \
    src/vyborg_yearmonth.cpp \
    src/vyborg_yearmonthday.cpp \
    src/vyborg_yearmonthwidget.cpp \
    src/vyborg_sortdialog.cpp \
    src/vyborg_filterdialog.cpp \
    src/vyborg_aboutdialog.cpp

INCLUDEPATH += include
HEADERS += \
    include/libvyborg.h\
    include/libvyborg_global.h \
    include/vyborg_maindialog.h \
    include/vyborg_mapperdialog.h \
    include/vyborg_connection.h \
    include/vyborg_mappercontrolbuttonbox.h \
    include/vyborg_navigationbuttonbox.h \
    include/vyborg_maindialogcontrolbuttonbox.h \
    include/vyborg_yearmonth.h \
    include/vyborg_yearmonthday.h \
    include/vyborg_yearmonthwidget.h \
    include/vyborg_sortdialog.h \
    include/vyborg.h \
    include/vyborg_filterdialog.h \
    include/vyborg_aboutdialog.h


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
