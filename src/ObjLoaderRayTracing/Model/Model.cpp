#include "Model.h"
namespace s21{

void Model::chooseStrategy(const std::string &filePath)
{
    if(filePath.substr(filePath.find_last_of(".")+1) == "obj"){
        loader=new ObjLoader();
    } else {
        throw std::invalid_argument("Undefined file format");
    }
}

void Model::initVAO()
{
    arrayBuf=QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    indexBuf=QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    VAO.create(),indexBuf.create(),indexBuf.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&VAO);
    arrayBuf.bind(),VAO.bind();
    arrayBuf.allocate(mesh->data(),mesh->size());
    indexBuf.allocate(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
//    //Color
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
//    glEnableVertexAttribArray(1);
//    //Texcoord
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
//    glEnableVertexAttribArray(2);
//    //Normal
//    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
//    glEnableVertexAttribArray(3);
}

void Model::render(QOpenGLShaderProgram& shaderProgramm)
{
    shaderProgramm.bind();
    VAO.bind();
    glDrawElements(GL_TRIANGLES, mesh->size(), GL_UNSIGNED_INT, 0);
    shaderProgramm.release();
}

Model::Model(const std::string &filePath):
    indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();
    arrayBuf.create();
    indexBuf.create();
    try {
        chooseStrategy(filePath);
    } catch (const std::exception e) {
        throw e;
    }

    mesh= loader->chooseFile(filePath);
    initVAO();
}

}
