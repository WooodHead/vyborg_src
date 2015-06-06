#INCLUDEPATH += $$PWD
#DEPENDPATH += $$PWD

HEADERS += \
    src/declarations.h \
    src/tablemodel.h \
    src/tableviewdelegate.h \
    src/md_shiftnum.h \
    src/maindialog.h \
    src/mapperdialog.h

SOURCES += \
    src/main.cpp \
    src/tablemodel.cpp \
    src/tableviewdelegate.cpp \
    src/md_shiftnum.cpp \
    src/maindialog.cpp \
    src/mapperdialog.cpp

#SOURCES += $$system(ls $$PWD/src/*.cpp)
#HEADERS += $$system(ls src/*.h)
