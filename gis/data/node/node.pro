QT += core gui widgets sql
TARGET = vyborg_data_node
TEMPLATE = app
CONFIG += vyborg
#CONFIG += aviawidgets
DESTDIR = /home/debian/Programming/bin

#message("$$QMAKESPEC/../features/")

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

#INCLUDEPATH += /usr/local/include/vyborg \
#    /usr/local/include/aviawidgets

#LIBS += -L/usr/local/lib/vyborg -lvyborg \
#    -L/usr/local/lib/aviawidgets -laviawidgets

#DISTFILES += \
#    src/rwwidget/files.pri
