#pragma once
#include <vector>
namespace s21{
struct vec3 {
    float x, y, z;

   public:
    vec3()=default;
    vec3(float value) : x(value), y(value), z(value) {}
    vec3(float xNew, float yNew, float zNew) : x(xNew), y(yNew), z(zNew) {}
    vec3(const vec3& other) = default;
    vec3& operator=(const vec3& other)=default;
};

struct vec2 {
   float x, y;

   public:
    vec2()=default;
    vec2(float value) : x(value), y(value) {}
    vec2(float xNew, float yNew) : x(xNew), y(yNew) {}
    vec2(const vec2& other) = default;
    vec2& operator=(const vec2& other)=default;
};

struct Vertex{
    vec3 position;
    vec3 color;
    vec2 texcoord;
    vec3 normal;
};

}    //    namespace s21
