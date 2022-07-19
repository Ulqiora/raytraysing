QT += core gui widgets opengl openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/ObjLoaderRayTracing/main.cpp \
    ../src/ObjLoaderRayTracing/Model/Model.cpp \
    ../src/ObjLoaderRayTracing/View/ViewApplication.cpp \
    ../src/ObjLoaderRayTracing/Model/ModelParser/ObjLoader.cpp

HEADERS += \
    ../src/ObjLoaderRayTracing/Model/Model.h \
    ../src/ObjLoaderRayTracing/Model/ModelParser/I3DGeometryLoader.h \
    ../src/ObjLoaderRayTracing/Model/ModelParser/ObjLoader.h \
    ../src/ObjLoaderRayTracing/View/ViewApplication.h \
    ../src/ObjLoaderRayTracing/Model/ModelParser/ModelData.h

#FORMS += \
#    ../src/ObjLoaderRayTracing/UiFiles/ViewApplication.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ObjLoaderRayTracing/Shaders.qrc
