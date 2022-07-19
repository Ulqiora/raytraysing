#ifndef OBJLOADER_H
#define OBJLOADER_H
#include "I3DGeometryLoader.h"
namespace s21{
class ObjLoader : public I3DGeometryLoader
{
private:
    std::vector<QVector3D> vertices;
    std::vector<QVector3D> normales;
    std::vector<QVector2D> tex_coords;
    std::vector<int> vertex_position_indicies;
    std::vector<int> vertex_texcoord_indicies;
    std::vector<int> vertex_normal_indicies;
private:
    void parserForF(std::stringstream&);
    void dataGenerate(std::vector<Vertex>*);
public:
    virtual std::vector<Vertex>* chooseFile(const std::string& )override;
};
}   //    namespace s21
#endif // OBJLOADER_H
