#-------------------------------------------------
#
# Project created by QtCreator 2017-02-23T20:02:48
#
#-------------------------------------------------

QT       += core gui
QT       += sql
INCLUDEPATH+="C:\Program Files (x86)\mysql-5.6.24-win32\include"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kernoSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        maindialog.cpp \
    sign_in.cpp \
    sign_out.cpp \
    your_information.cpp\
    SCard.cpp \
    Record.cpp \
    StudentDao.cpp \
    DatabaseConnection.cpp \
    Util.cpp \
    Student.cpp \
    Register.cpp \
    ReadCard.cpp \
    RecordDao.cpp



HEADERS  += maindialog.h \
    sign_in.h \
    sign_out.h \
    your_information.h \
    SCard.h \
    WINSCARD.H \
    Record.h \
    StudentDao.h \
    DatabaseConnection.h \
    Util.h \
    Student.h \
    Register.h \
    ReadCard.h \
    RecordDao.h \
    const.h

FORMS    += maindialog.ui \
    sign_in.ui \
    sign_out.ui \
    your_information.ui \
    register.ui

DISTFILES += \
    Winscard.lib \
    kernoSystem.pro.user \
    libmysql.dll \
    libmysqld.dll
