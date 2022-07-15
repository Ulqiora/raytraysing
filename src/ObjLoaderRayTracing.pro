QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/ObjLoaderRayTracing/main.cpp \
 \#    ../src/ObjLoaderRayTracing/View/ViewApplication.cpp
    ObjLoaderRayTracing/Model/ModelParser/ObjLoader.cpp

HEADERS += \
    ObjLoaderRayTracing/Model/ModelParser/I3DGeometryLoader.h \
    ObjLoaderRayTracing/Model/ModelParser/ObjLoader.h \
 \#    ../src/ObjLoaderRayTracing/View/ViewApplication.h
    ObjLoaderRayTracing/Model/ModelParser/ModelData.h

FORMS += \
#    ../src/ObjLoaderRayTracing/UiFiles/ViewApplication.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
