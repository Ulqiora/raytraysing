#pragma once
#include <vector>
#include <sstream>
namespace s21{
struct vec3 {
    float x, y, z;
   public:
    vec3()=default;
    vec3(float value) : x(value), y(value), z(value) {}
    vec3(float xNew, float yNew, float zNew) : x(xNew), y(yNew), z(zNew) {}
    vec3(const vec3& other) = default;
    vec3& operator=(const vec3& other)=default;
    vec3 operator+(const vec3& other)const{
        vec3 sum;
        sum.x=this->x+other.x;
        sum.y=this->y+other.y;
        sum.z=this->z+other.z;
        return sum;
    }
    void initByString(const std::string& str){
        std::stringstream ss(str);
        ss>>x>>y>>z;
    }
};

struct vec2 {
   float x, y;
   public:
    vec2()=default;
    vec2(float value) : x(value), y(value) {}
    vec2(float xNew, float yNew) : x(xNew), y(yNew) {}
    vec2(const vec2& other) = default;
    vec2& operator=(const vec2& other)=default;
    vec2 operator+(const vec2& other)const{
        vec2 sum;
        sum.x=this->x+other.x;
        sum.y=this->y+other.y;
        return sum;
    }
};

}    //    namespace s21
