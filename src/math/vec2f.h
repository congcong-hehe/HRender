// created by hyq
// 2021/10/22

# pragma once

#include <cmath>

namespace Math{

class Vec2f
{
public:
    Vec2f() : x(0), y(0)  {}
    Vec2f(float _x, float _y) : x(_x), y(_y) {}
    Vec2f(const Vec2f &v) { x = v.x; y = v.y; }

    Vec2f operator + (const float a) const       { return Vec2f(x + a, y + a); }
    Vec2f operator - (const float a) const       { return Vec2f(x - a, y - a); }
    Vec2f operator * (const float a) const       { return Vec2f(x * a, y * a); }
    Vec2f operator / (const float a) const       { return Vec2f(x / a, y / a); }

    Vec2f& operator += (const float a)     { x += a; y += a; return *this; }
    Vec2f& operator -= (const float a)     { x -= a; y -= a; return *this; }
    Vec2f& operator *= (const float a)     { x *= a; y *= a; return *this; }
    Vec2f& operator /= (const float a)     { x /= a; y /= a; return *this; }

    Vec2f operator + (const Vec2f &v) const      { return Vec2f(x + v.x, y + v.y); }
    Vec2f operator - (const Vec2f &v) const      { return Vec2f(x - v.x, y - v.y); }
    Vec2f operator * (const Vec2f &v) const      { return Vec2f(x * v.x, y * v.y); }

    Vec2f& operator += (const Vec2f &v)      { x+= v.x; y += v.y; return *this; }
    Vec2f& operator -= (const Vec2f &v)      { x-= v.x; y -= v.y; return *this; }
    Vec2f& operator *= (const Vec2f &v)      { x*= v.x; y *= v.y; return *this; }

    bool operator == (const Vec2f &v) const      { return x == v.x && y == v.y; }
    bool operator != (const Vec2f &v) const      { return x != v.x && y != v.y; }

    float norm() const     { return sqrt(normSquare()); }
    float normSquare() const     { return x * x + y * y; }

public:
    union {
        struct { float x, y; };
        struct { float u, v; };
        struct { float vec[2]; };
    };

};

}