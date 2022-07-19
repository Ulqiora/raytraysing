#include "ObjLoader.h"
namespace s21{
void ObjLoader::parserForF(std::stringstream &ss)
{
    int counter = 0,temp_int;
    while (ss >> temp_int) {
        if (counter == 0) vertex_position_indicies.push_back(temp_int);
        else if (counter == 1) vertex_texcoord_indicies.push_back(temp_int);
        else if (counter == 2) vertex_normal_indicies.push_back(temp_int);
        if (ss.peek() == '/') {
            ++counter;
            ss.ignore(1, '/');
        } else if (ss.peek() == ' ') {
            ++counter;
            ss.ignore(1, ' ');
        }
        if (counter > 2)
            counter = 0;
    }
}

void ObjLoader::dataGenerate(std::vector<Vertex> *data)
{
    data->resize(vertex_position_indicies.size(), Vertex());
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        (*data)[i].position = vertices[vertex_position_indicies[i] - 1];
        if(tex_coords.size()!=0)
            (*data)[i].texcoord = tex_coords[vertex_texcoord_indicies[i] - 1];
        if(normales.size()!=0)
            (*data)[i].normal = normales[vertex_normal_indicies[i] - 1];
        (*data)[i].color = vec3(1.f, 1.f, 1.f);
    }
}

std::vector<Vertex>*ObjLoader::chooseFile(const std::string &filename)
{
    std::vector<Vertex>* data= new std::vector<Vertex>;
    vec3 temp_vec3;
    vec2 temp_vec2;
    std::ifstream fileStream(filename);
    if (fileStream.fail()) std::invalid_argument("This file is not to be opened");
    std::string line,prefix;
    std::stringstream ss;
    while (std::getline(fileStream,line)){
        ss.clear();
        ss.str(line);
        ss>>prefix;
        if (prefix == "#"){
        }else if (prefix == "o"){
        }else if (prefix == "s"){
        }else if (prefix == "use_mtl"){
        }else if (prefix=="v"){
            ss>>temp_vec3.x>>temp_vec3.y>>temp_vec3.z;
            vertices.push_back(temp_vec3);
        }else if(prefix=="vt"){
            ss >> temp_vec2.x >> temp_vec2.y;
            tex_coords.push_back(temp_vec2);
        } else if (prefix=="vn"){
            ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
            normales.push_back(temp_vec3);
        } else if (prefix == "f"){
            parserForF(ss);
        } else {
            std::invalid_argument("Wrong file format!");
        }
    }
    dataGenerate(data);
    vertices.clear();
    normales.clear();
    tex_coords.clear();
    vertex_position_indicies.clear();
    vertex_texcoord_indicies.clear();
    vertex_normal_indicies.clear();
    return data;
}


}
