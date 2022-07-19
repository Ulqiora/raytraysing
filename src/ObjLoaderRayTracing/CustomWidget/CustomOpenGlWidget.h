#ifndef CUSTOMOPENGLWIDGET_H
#define CUSTOMOPENGLWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>



class CustomOpenGlWidget: public QOpenGLWidget,protected QOpenGLFunctions
{
public:
    explicit CustomOpenGlWidget(QWidget* parent=nullptr);

    // QOpenGLWidget interface
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    void initShaderProgramm();
private:
    QOpenGLShaderProgram* shaderProgramm=nullptr;
//    std::vector<Model>
};

#endif // CUSTOMOPENGLWIDGET_H
