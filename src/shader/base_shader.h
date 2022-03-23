// make by hyq
// 2021/11/20

#pragma once

#include "shader.h"
#include "../math/vec3.h"
#include "../render/texture.h"
#include "../render/builtin_fun.h"
#include "../math/mat4.h"

// 对应 https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
// 正交变换画出基本的三角形

class BaseVSShader : public VertexShader{
public:
    // in
    Math::Mat4 rotate;
    Math::Vec3f pos;
    Math::Vec2f uv;

    // out

    void execute() override {
        gl_position = rotate * Math::Vec4f(pos.x, pos.y, pos.z, 1.0f) / 10.f;
    }
};

class BaseFSShader : public FragmentShader {
public:
    Texture* texture1;
    Texture* texture2;
    // out
    Math::Vec3f frag_color; 
    Math::Vec2f uv;

    void execute() override {
        frag_color = lerp<Math::Vec3f>(texture1->sample(uv.u, uv.v), texture2->sample(uv.u, uv.v), 0.2);
        //frag_color = texture1->sample(uv.u, uv.v);
    };
};