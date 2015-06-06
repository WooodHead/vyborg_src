TEMPLATE = app
TARGET = terkas_safety
QT += widgets sql

DEPENDPATH += $$PWD/include
VPATH += $$PWD/src
INCLUDEPATH += /usr/include/vyborg/ \
    $$PWD/src
LIBS += -L/usr/lib/vyborg -lvyborg
#SUBDIRS += . $$PWD/src

QMAKESPEC += /usr/src/vyborg/mkspecs/features/unix

OBJECTS_DIR = tmp
MOC_DIR = tmp


include(src/files.pri)


## Input
#HEADERS += declarations.h \
#    tablemodel.h \
#    tableviewdelegate.h \
#    md_shiftnum.h \
#    maindialog.h \
#    mapperdialog.h

#SOURCES += src/main.cpp \
#    src/tablemodel.cpp \
#    src/tableviewdelegate.cpp \
#    src/md_shiftnum.cpp \
#    src/maindialog.cpp \
#    src/mapperdialog.cpp

#SOURCES += main.cpp \
#    tablemodel.cpp \
#    tableviewdelegate.cpp \
#    md_shiftnum.cpp \
#    maindialog.cpp \
#    mapperdialog.cpp


#OTHER_FILES += \
#    files.pri



#VPATH += $$PWD/src

#HEADERS += \
##    src/declarations.h \
##    src/tablemodel.h \
##    src/tableviewdelegate.h \
##    src/md_shiftnum.h \
##    src/maindialog.h \
##    src/mapperdialog.h
#    declarations.h \
#    tablemodel.h \
#    tableviewdelegate.h \
#    md_shiftnum.h \
#    maindialog.h \
#    mapperdialog.h

#SOURCES += \
#    src/main.cpp \
#    src/tablemodel.cpp \
#    src/tableviewdelegate.cpp \
#    src/md_shiftnum.cpp \
#    src/maindialog.cpp \
#    src/mapperdialog.cpp
