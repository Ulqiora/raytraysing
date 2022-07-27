#include "ObjLoader.h"
namespace s21{

std::vector<IMesh*>* ObjLoader::chooseFile(const std::string &filename)
{
    std::vector<IMesh*>* data= new std::vector<Vertex>;
    vec3 temp_vec3;
    vec2 temp_vec2;
    std::ifstream fileStream(filename);
    if (fileStream.fail()) std::invalid_argument("This file is not to be opened");
    std::string line;
    std::stringstream ss;
    while (std::getline(fileStream,line)){
        std::string token=algorithm::getToken(line);
        if (token == "#"){
        } else if (token == "o"){
        } else if (token == "s"){
        } else if (token == "use_mtl"){
        } else if (token=="v"){
        } else if(token=="vt"){
        } else if (token=="vn"){
        } else if (token == "f"){
        } else {
            std::invalid_argument("Wrong file format!");
        }
    }
    return data;
}


}
