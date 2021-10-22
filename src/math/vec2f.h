# pragma once

#include <cmath>

namespace Math{

class Vec2f
{
public:
    Vec2f() : x(0), y(0)  {}
    Vec2f(float _x, float _y) : x(_x), y(_y) {}

    inline Vec2f operator + (const float a) const       { return Vec2f(x + a, y + a); }
    inline Vec2f operator - (const float a) const       { return Vec2f(x - a, y - a); }
    inline Vec2f operator * (const float a) const       { return Vec2f(x * a, y * a); }
    inline Vec2f operator / (const float a) const       { return Vec2f(x / a, y / a); }

    inline Vec2f& operator += (const float a)     { x += a; y += a; return *this; }
    inline Vec2f& operator -= (const float a)     { x -= a; y -= a; return *this; }
    inline Vec2f& operator *= (const float a)     { x *= a; y *= a; return *this; }
    inline Vec2f& operator /= (const float a)     { x /= a; y /= a; return *this; }

    inline Vec2f operator + (const Vec2f &v) const      { return Vec2f(x + v.x, y + v.y); }
    inline Vec2f operator - (const Vec2f &v) const      { return Vec2f(x - v.x, y - v.y); }
    inline Vec2f operator * (const Vec2f &v) const      { return Vec2f(x * v.x, y * v.y); }

    inline Vec2f& operator += (const Vec2f &v)      { x+= v.x; y += v.y; return *this; }
    inline Vec2f& operator -= (const Vec2f &v)      { x-= v.x; y -= v.y; return *this; }
    inline Vec2f& operator *= (const Vec2f &v)      { x*= v.x; y *= v.y; return *this; }

    inline bool operator == (const Vec2f &v) const      { return x == v.x && y == v.y; }
    inline bool operator != (const Vec2f &v) const      { return x != v.x && y != v.y; }

    inline float norm() const     { return sqrt(normSquare()); }
    inline float normSquare() const     { return x * x + y * y; }

public:
    union {
        struct { float x, y; };
        struct { float u, v; };
        struct { float v[2]; };
    };

};

}