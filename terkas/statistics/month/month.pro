QT += core gui widgets charts sql
TEMPLATE = app
CONFIG += vyborg
TARGET = vyborg_statistics_month
DESTDIR = /home/debian/Programming/bin
OBJECTS_DIR = tmp
MOC_DIR = tmp

include(src/files.pri)

