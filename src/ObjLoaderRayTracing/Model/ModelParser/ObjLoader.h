#ifndef OBJLOADER_H
#define OBJLOADER_H
#include "I3DGeometryLoader.h"
namespace s21{
class ObjLoader : public I3DGeometryLoader
{
public:
    virtual std::vector<Vertex>* chooseFile(const std::string& filename)override;
};
}   //    namespace s21
#endif // OBJLOADER_H
