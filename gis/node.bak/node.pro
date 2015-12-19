QT       += core gui sql widgets

TARGET = terkas_node
TEMPLATE = app


SOURCES +=\
    src/coord.cpp \
    src/coordwidget.cpp \
    src/dialog.cpp \
    src/geomdelegate.cpp \
    src/main.cpp \
    src/mapperdialog.cpp \
    src/relationaltablemodel.cpp

HEADERS  += \
    src/coord.h \
    src/coordwidget.h \
    src/declarations.h \
    src/dialog.h \
    src/geomdelegate.h \
    src/mapperdialog.h \
    src/relationaltablemodel.h


OBJECTS_DIR = tmp
MOC_DIR = tmp
