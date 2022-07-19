#pragma once
#include <vector>
#include <QVector3D>
#include <QVector2D>
#include
namespace s21{
struct Vertex{
    QVector3D position;
    QVector3D color;
    QVector2D texcoord;
    QVector3D normal;
};

}    //    namespace s21
