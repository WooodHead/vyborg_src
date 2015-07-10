QT       += core gui widgets

TARGET = wiipuriTest
TEMPLATE = app

INCLUDEPATH += ..


SOURCES += main.cpp\
    dialog.cpp \
    ../navigationbuttonbox.cpp \
    ../yearmonth.cpp \
    ../yearmonthwidget.cpp \
    ../maindialogcontrolbuttonbox.cpp \
    ../mapperdialogcontrolbuttonbox.cpp \
    ../mapperdialog.cpp

HEADERS  += dialog.h \
    ../navigationbuttonbox.h \
    ../yearmonth.h \
    ../yearmonthwidget.h \
    ../maindialogcontrolbuttonbox.h \
    ../mapperdialogcontrolbuttonbox.h \
    ../mapperdialog.h

RESOURCES += \
    ../resource.qrc
