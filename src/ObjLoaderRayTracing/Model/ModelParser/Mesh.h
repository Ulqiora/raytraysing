#pragma once 
#include "Vertex.h"
#include "IMaterialLoader.h"
#include <vector>
#include <memory>
namespace s21{
class IMesh{
public: 
    virtual auto render() -> void = 0;
    virtual ~IMesh(){}
};
class Mesh: public IMesh{
private:
    std::unique_ptr<std::vector<Vertex>> vertices;
    std::unique_ptr<std::vector<int>> indices;
    IMaterialLoader::MaterialData material;
    std::string meshName;
public:
    Mesh()=default;
    Mesh(std::vector<Vertex>* otherVertices,std::vector<int> otherIndices){
        vertices=std::make_unique<std::vector<Vertex>>(otherVertices);
        indices=std::make_unique<std::vector<int>>(otherIndices);
    }
    auto render() -> void override;
    virtual ~Mesh(){}
};
}