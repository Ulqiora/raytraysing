#include "CustomOpenGlWidget.h"

CustomOpenGlWidget::CustomOpenGlWidget(QWidget *parent):QOpenGLWidget(parent){}

void CustomOpenGlWidget::initializeGL()
{
    initializeOpenGLFunctions();
    shaderProgramm = new QOpenGLShaderProgram();
    initShaderProgramm();
    glEnable(GL_DEPTH_TEST);
}

void CustomOpenGlWidget::initShaderProgramm()
{
    if(!shaderProgramm->addShaderFromSourceFile(QOpenGLShader::Vertex,":/shaders/vertexShader.glsl"))
        close();
    if (!shaderProgramm->addShaderFromSourceFile(QOpenGLShader::Fragment,":/shaders/fragmentShader.glsl"))
        close();
    if(!shaderProgramm->link())
        close();
    if(!shaderProgramm->bind())
        close();
}

void CustomOpenGlWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
}

void CustomOpenGlWidget::paintGL()
{

}


