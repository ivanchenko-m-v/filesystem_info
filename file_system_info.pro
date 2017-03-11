#-------------------------------------------------
#
# Project created by QtCreator 2017-03-04T23:39:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = file_system_info
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treeview_filesystem.cpp \
    panel_buttons.cpp \
    business_logic.cpp \
    dir_csv_exporter.cpp \
    treeitem.cpp \
    treemodel_fileinfo.cpp \
    treeview_fileinfo.cpp

HEADERS  += mainwindow.h \
    treeview_filesystem.h \
    panel_buttons.h \
    business_logic.h \
    dir_csv_exporter.h \
    treeitem.h \
    treemodel_fileinfo.h \
    treeview_fileinfo.h
