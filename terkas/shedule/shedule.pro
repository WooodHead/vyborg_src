QT       += core gui widgets sql
CONFIG   += vyborg
TARGET   = shedule
TEMPLATE = app

OBJECTS_DIR = tmp
MOC_DIR = tmp

include(src/files.pri)

QMAKESPEC += /home/kubuntu/Programming/Qt/qt5/qtbase/mkspecs/features/unix
