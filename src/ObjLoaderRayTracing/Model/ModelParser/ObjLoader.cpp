#include "ObjLoader.h"
namespace s21{
std::vector<Vertex>*ObjLoader::chooseFile(const std::string &filename)
{
    std::vector<Vertex>* data= new std::vector<Vertex>;
    std::vector<vec3> vertices;
    std::vector<vec3> normales;
    std::vector<vec2> tex_coords;
    vec3 temp_vec3;
    vec2 temp_vec2;
    std::vector<int> vertex_position_indicies;
    std::vector<int> vertex_texcoord_indicies;
    std::vector<int> vertex_normal_indicies;
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
            int counter = 0,temp_int;
            while (ss >> temp_int)
            {
                //Pushing indices into correct arrays
                if (counter == 0)
                    vertex_position_indicies.push_back(temp_int);
                else if (counter == 1)
                    vertex_texcoord_indicies.push_back(temp_int);
                else if (counter == 2)
                    vertex_normal_indicies.push_back(temp_int);
                //Handling characters
                if (ss.peek() == '/')
                {
                    ++counter;
                    ss.ignore(1, '/');
                }
                else if (ss.peek() == ' ')
                {
                    ++counter;
                    ss.ignore(1, ' ');
                }
                //Reset the counter
                if (counter > 2)
                    counter = 0;
            }
        }
    }
    data->resize(vertex_position_indicies.size(), Vertex());

    //Load in all indices
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        (*data)[i].position = vertices[vertex_position_indicies[i] - 1];
        (*data)[i].texcoord = tex_coords[vertex_texcoord_indicies[i] - 1];
        (*data)[i].normal = normales[vertex_normal_indicies[i] - 1];
        (*data)[i].color = vec3(1.f, 1.f, 1.f);
    }

    //DEBUG
    std::cout << "Nr of vertices: " << vertices.size() << "\n";

    //Loaded success
    std::cout << "OBJ file loaded!" << "\n";
    return data;
}
}
