//#include "View/ViewApplication.h"

#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <filesystem>
//#include "Model/ModelParser/ModelData.h"
//#include "Model/Model.h"
#include "Model/ModelParser/MaterialLoader.h"
int main(int argc,char** argv)
{
    using  namespace s21;
    QApplication app(argc, argv);
    std::string  materialfile=QFileDialog::getOpenFileName().toStdString();
    IMaterialLoader* loader=new MaterialLoader();
    auto temp = loader->start(materialfile);
    qDebug()<< temp->size();
    return app.exec();
}
//QApplication app(argc, argv);
//QSurfaceFormat format;
//format.setDepthBufferSize(24);
//QSurfaceFormat::setDefaultFormat(format);

//app.setApplicationName("cube");
//app.setApplicationVersion("0.1");

//s21::Model("");
//Window w;
//w.show();
//return app.exec();
