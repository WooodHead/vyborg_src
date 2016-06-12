QT += core gui widgets sql
QT += charts

TEMPLATE = app
CONFIG += vyborg
TARGET = vyborg_statistics_month_ct
DESTDIR = /home/debian/bin  # Rename for correct destination
OBJECTS_DIR = tmp
MOC_DIR = tmp

include(src/files.pri)

