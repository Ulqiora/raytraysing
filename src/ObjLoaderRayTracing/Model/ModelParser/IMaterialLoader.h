#pragma once
#include "Vectors.h"
#include <string>
#include <vector>
namespace s21{
    namespace algorithm{
        std::string getToken(std::string& str){
            if (!str.empty()) {
                size_t token_start = str.find_first_not_of(" \t");
                size_t token_end = str.find_first_of(" \t", token_start);
                if (token_start != std::string::npos && token_end != std::string::npos) {
                    std::string temp=str;
                    str = str.substr(token_end + 1);
                    return temp.substr(token_start, token_end - token_start);
                } else if (token_start != std::string::npos) {
                    str = str.substr(token_end + 1);
                    return str.substr(token_start);
                }
            }
            return "";
        }
    }
class IMaterialLoader{
public:
    struct MaterialData{
            std::string name;    // название материала
            vec3 Ka;		// цвет окружающей среды
            vec3 Kd;		// цвет рассеивания
            vec3 Ks;     // цвет зеркального отражения
            vec3 Ke;     // Коэффициет излучения
            float Ns;      // коэффициент зеркального  отражения
            float Ni;    //    оптическая плотность
            float d;    //    Прочрачность
            int illum;     // Освещение   
            std::string map_Ka;    //    Карта текстур  отражения
            std::string map_Kd;    //    Карта диффузионной текстуры
            std::string map_Ks;    //    карта зеркальной текстуры
            std::string map_Ns;    //     спекулярная карта света
            std::string map_d;    //    карта альфа текстур
            std::string map_bump;    //    Карта неровностей
    };
    virtual std::vector<MaterialData>* start(const std::string& materialFileName) = 0;
};
}