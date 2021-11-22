// created by hyq
// 2021/11/17

# pragma once

namespace Math{
class Vec3i {
public:
    Vec3i() : x(0), y(0), z(0)  {}
    Vec3i(int _x, int _y , int _z) : x(_x), y(_y), z(_z) {}

public:
    union {
        struct { int x, y, z; };
        struct { int vec[3];    };
    };

};

}