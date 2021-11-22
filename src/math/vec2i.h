// created by hyq
// 2021/11/17

# pragma once

#include <cmath>

namespace Math{

class Vec2i
{
public:
    Vec2i() : x(0), y(0)  {}
    Vec2i(int _x, int _y) : x(_x), y(_y) {}

public:
    union {
        struct { int  x, y; };
        struct { int  u, v; };
        struct { int  vec[2]; };
    };

};

}