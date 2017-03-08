#-------------------------------------------------
#
# Project created by QtCreator 2017-03-04T23:39:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = file_system_info
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treeview_filesystem.cpp \
    panel_buttons.cpp \
    business_logic.cpp \
    listwidget_files_info.cpp \
    dir_csv_exporter.cpp

HEADERS  += mainwindow.h \
    treeview_filesystem.h \
    panel_buttons.h \
    business_logic.h \
    listwidget_files_info.h \
    dir_csv_exporter.h
