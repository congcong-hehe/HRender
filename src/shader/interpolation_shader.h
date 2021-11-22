// make by hyq
// 2021/11/22

#pragma once

#include "shader.h"
#include "../math/vec3f.h"

// 插值三角形的三个顶点
class InterVSShader : public VertexShader{
public:
    // in
    Math::Vec3f pos;

    // out

    void execute() override {
        gl_position = Math::Vec4f(pos.x, pos.y, pos.z, 1.0f);
    }
};

class InterFSShader : public FragmentShader {
public:
    // in
    Math::Vec3f color;

    // out
    Math::Vec3f frag_color; 

    void execute() override {
        frag_color = color;
    };
};