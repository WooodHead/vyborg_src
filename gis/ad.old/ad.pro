QT += core gui widgets sql
TARGET = node_ad
TEMPLATE = app

include(src/files.pri)

CONFIG(release) {
    DESTDIR = ../.build/build-$$TARGET-Release
}

OUT_PWD = $$DESTDIR
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui

#DISTFILES += \
#    src/files.pri
