// make by hyq
// 2021/11/20

#pragma once

#include "../math/vec4.h"

class Shader {
public:
    virtual void execute() = 0;
};

class VertexShader : public Shader {
public:
     Math::Vec4f gl_position; 
};

class FragmentShader : public Shader {
public:
    
};


