QT += core gui widgets sql
TARGET = safety
TEMPLATE = app

OBJECTS_DIR = tmp
MOC_DIR = tmp

INCLUDEPATH += /usr/local/include/vyborg
LIBS += -L/usr/local/lib/vyborg -lvyborg

include(src/files.pri)
#DISTFILES += \
#    src/files.pri

