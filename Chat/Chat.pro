#-------------------------------------------------
#
# Project created by QtCreator 2023-06-12T10:45:12
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    ../Server/source/ServerAPI.cpp \
        main.cpp \
        mainwindow.cpp \
    chatwindow.cpp \
    creators.cpp \
    about.cpp

HEADERS += \
    ../Server/headers/ServerAPI.h \
        mainwindow.h \
    chatwindow.h \
    creators.h \
    about.h

FORMS += \
        mainwindow.ui \
    chatwindow.ui \
    creators.ui \
    about.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
