#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Vectors.h"
#include "Vertex.h"
#include "Mesh.h"
namespace s21{

enum class geomLoadStrategy{
    ObjLoader=1
};

class I3DGeometryLoader{
public:
    virtual std::vector<IMesh*>* chooseFile(const std::string& filename )=0;
};
}    //     namespace  s21
