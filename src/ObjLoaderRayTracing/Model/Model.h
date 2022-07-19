#pragma once
#include "ModelParser/ObjLoader.h"
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <string>
namespace  s21{

class IModel {
    virtual void render(QOpenGLShaderProgram&) = 0;
};

class Model: protected QOpenGLFunctions, public IModel {
private:
    std::vector<Vertex>* mesh;
    QOpenGLVertexArrayObject VAO;
    QOpenGLBuffer arrayBuf, indexBuf;
private:
    void chooseStrategy(const std::string& filePath);
    void initVAO();
public:
    Model(const std::string& filePath);
    I3DGeometryLoader* loader = nullptr;
    virtual void render(QOpenGLShaderProgram&)override;
    virtual ~Model(){
        delete mesh;
        arrayBuf.destroy();
        indexBuf.destroy();
    }
};
}
