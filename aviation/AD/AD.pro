QT += core gui widgets sql
TARGET = AD
TEMPLATE = app


SOURCES += main.cpp \
    ADwidget.cpp \
    sortdialog.cpp \
    filterdialog.cpp \
    mapperdialog.cpp \
    proxymodel.cpp \
    tablemodel.cpp \
    rus.cpp \
    querymodel.cpp

HEADERS  += \
    declarations.h \
    ADwidget.h \
    sortdialog.h \
    filterdialog.h \
    mapperdialog.h \
    proxymodel.h \
    tablemodel.h \
    rus.h \
    querymodel.h


CONFIG(release) {
    DESTDIR = ../.build/build-$$TARGET-Release
}
OUT_PWD = $$DESTDIR
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui
