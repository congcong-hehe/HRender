// make by hyq
// 2021/11/20

#pragma once

#include "shader.h"
#include "../math/vec3f.h"

// 对应 https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
// 正交变换画出基本的三角形

class BaseVSShader : public VertexShader{
public:
    // in
    Math::Vec3f pos;

    // out

    void execute() override {
        gl_position = Math::Vec4f(pos.x, pos.y, pos.z, 1.0f);
    }
};

class BaseFSShader : public FragmentShader {
public:

    // out
    Math::Vec3f frag_color; 

    void execute() override {
        frag_color = Math::Vec3f(1.0f, 0.5f, 0.2f);
    };
};