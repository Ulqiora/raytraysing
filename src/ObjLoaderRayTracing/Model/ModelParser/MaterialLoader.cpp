#include "MaterialLoader.h"
namespace s21 {

std::vector<MaterialLoader::MaterialData>* MaterialLoader::start(const std::string& materialFileName) {
    std::vector<MaterialData>* data = new std::vector<MaterialData>();
    std::ifstream file(materialFileName);
    std::string currentStr;
    while (std::getline(file, currentStr)) {
        std::string token=getToken(currentStr);
        if (token == "newmtl") {
            data->push_back(MaterialData());
            data->back().name = getToken(currentStr);
        } else if (token == "#") {

        } else if (token == "Ks") {
            data->back().Ks.initByString(currentStr);
        } else if (token == "Ke") {
            data->back().Ke.initByString(currentStr);
        } else if (token == "Kd") {
            data->back().Kd.initByString(currentStr);
        } else if (token == "Ka") {
            data->back().Ka.initByString(currentStr);
        } else if (token == "Ns") {
            data->back().Ns = std::stod(currentStr);
        } else if (token == "Ni") {
            data->back().Ni = std::stod(currentStr);
        } else if (token == "d") {
            data->back().d = std::stod(currentStr);
        } else if (token == "Ns") {
            data->back().Ns = std::stod(currentStr);
        } else if (token == "illum") {
            data->back().illum = std::stoi(currentStr);
        } else if (token == "map_Ka") {
            data->back().map_Ka = getToken(currentStr);
        } else if (token == "map_Kd") {
            data->back().map_Kd = getToken(currentStr);
        } else if (token == "map_Ks") {
            data->back().map_Ks = getToken(currentStr);
        } else if (token == "map_Ns") {
            data->back().map_Ns = getToken(currentStr);
        } else if (token == "map_d") {
            data->back().map_d = getToken(currentStr);
        } else if (token.empty()) {

        } else if (std::string temp = token;
                   temp == "map_Bump" || temp == "map_bump" || temp == "bump") {
            data->back().map_bump = getToken(currentStr);
        } else {
            delete data;
            throw std::invalid_argument("This file have undefined symbol:" + token+currentStr);
        }
    }
    return data;
}

}  // namespace s21
