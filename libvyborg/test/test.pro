QT       += core gui widgets

TARGET = wiipuriTest
TEMPLATE = app

INCLUDEPATH += ..


SOURCES += main.cpp\
        dialog.cpp \
    ../navigationbuttonbox.cpp \
    ../yearmonth.cpp \
    ../yearmonthwidget.cpp \
    ../controlbuttonbox.cpp \
    ../mappercontrolbuttonbox.cpp \
    ../mapperdialog.cpp

HEADERS  += dialog.h \
    ../navigationbuttonbox.h \
    ../yearmonth.h \
    ../yearmonthwidget.h \
    ../controlbuttonbox.h \
    ../mappercontrolbuttonbox.h \
    ../mapperdialog.h

RESOURCES += \
    ../resource.qrc
