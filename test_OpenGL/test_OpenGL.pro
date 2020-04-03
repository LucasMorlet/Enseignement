QT += core gui
CONFIG += c++11

#***** Les bibliothèques Windows *****#
win32:LIBS += C:\Windows\System32\opengl32.dll
win32:LIBS += C:\Windows\System32\freeglut.dll
win32:LIBS += C:\Windows\System32\glew32.dll

#***** Les bibliothèques Unix *****#
unix:LIBS += /usr/lib/x86_64-linux-gnu/libGL.so
unix:LIBS += /usr/lib/x86_64-linux-gnu/libGLU.so
unix:LIBS += /usr/lib/x86_64-linux-gnu/libglut.so
unix:LIBS += /usr/lib/x86_64-linux-gnu/libGLEW.so

#***** L'application de test *****#
TARGET = test_OpenGL
TEMPLATE = app

HEADERS += GL/freeglut.h
HEADERS += GL/freeglut_std.h
HEADERS += GL/freeglut_ext.h
HEADERS += GL/glew.h
HEADERS += GL/wglew.h

SOURCES += src/main.cpp
SOURCES += src/test_glut.cpp
SOURCES += src/test_glew.cpp
SOURCES += src/test_glm.cpp
SOURCES += src/test_eigen.cpp
