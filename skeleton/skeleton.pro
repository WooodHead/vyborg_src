QT += core gui widgets sql
# Uncomment to include QtCharts module
# Qt += charts

TEMPLATE = app
CONFIG += vyborg
TARGET = vyborg_skeleton  # Rename for correct application name
DESTDIR = /home/debian/bin  # Rename for correct destination
OBJECTS_DIR = tmp
MOC_DIR = tmp

include(src/files.pri)

