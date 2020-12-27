#-------------------------------------------------
#
# Project created by QtCreator 2013-11-01T11:13:40
#
#-------------------------------------------------

QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets

TARGET = FR
TEMPLATE = app


SOURCES += main.cpp\
	mainwindow.cpp\
	detectObject.cpp\
	preprocessFace.cpp\
	loadSave.cpp \
	recognizer.cpp \
	collecter.cpp

HEADERS  += mainwindow.h\
	    detectObject.h\
	    preprocessFace.h\
	    loadSave.h\
	    recognizer.h \
	    collecter.h

FORMS    += mainwindow.ui

unix {
	CONFIG += link_pkgconfig
	PKGCONFIG += opencv
}
