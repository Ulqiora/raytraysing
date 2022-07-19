#include "View/ViewApplication.h"

#include <QApplication>
#include <QFileDialog>
//#include "Model/ModelParser/ModelData.h"
#include "Model/Model.h"

int main(int argc,char** argv)
{
    QApplication app(argc, argv);
//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    QSurfaceFormat::setDefaultFormat(format);

//    app.setApplicationName("cube");
//    app.setApplicationVersion("0.1");

//    s21::Model("");
    Window w;
    w.show();
    return app.exec();
}
//QApplication a(argc, argv);
//ViewApplication w;
//w.show();
//return a.exec();
