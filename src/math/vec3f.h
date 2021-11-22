// created by hyq
// 2021/10/22

# pragma once

#include <cmath>

namespace Math{
class Vec3f {
public:
    Vec3f() : x(0), y(0), z(0)  {}
    Vec3f(float _x, float _y , float _z) : x(_x), y(_y), z(_z) {}

    inline Vec3f operator + (const float a) const       { return Vec3f(x + a, y + a, z + a); }
    inline Vec3f operator - (const float a) const       { return Vec3f(x - a, y - a, z - a); }
    inline Vec3f operator * (const float a) const       { return Vec3f(x * a, y * a, z * a); }
    inline Vec3f operator / (const float a) const       { return Vec3f(x / a, y / a, z / a); }

    inline Vec3f& operator += (const float a)     { x += a; y += a; z += a; return *this; }
    inline Vec3f& operator -= (const float a)     { x -= a; y -= a; z -= a; return *this; }
    inline Vec3f& operator *= (const float a)     { x *= a; y *= a; z *= a; return *this; }
    inline Vec3f& operator /= (const float a)     { x /= a; y /= a; z /= a; return *this; }

    inline Vec3f operator + (const Vec3f &v) const      { return Vec3f(x + v.x, y + v.y, z + v.z); }
    inline Vec3f operator - (const Vec3f &v) const      { return Vec3f(x - v.x, y - v.y, z - v.z); }
    inline Vec3f operator * (const Vec3f &v) const      { return Vec3f(x * v.x, y * v.y, z * v.z); }

    inline Vec3f& operator += (const Vec3f &v)      { x+= v.x; y += v.y; z += v.z; return *this; }
    inline Vec3f& operator -= (const Vec3f &v)      { x-= v.x; y -= v.y; z -= v.z; return *this; }
    inline Vec3f& operator *= (const Vec3f &v)      { x*= v.x; y *= v.y; z *= v.z; return *this; }

    inline bool operator == (const Vec3f &v) const      { return x == v.x && y == v.y && z == v.z; }
    inline bool operator != (const Vec3f &v) const      { return x != v.x && y != v.y && z != v.z; }

    inline float norm() const     { return sqrt(normSquare()); }
    inline float normSquare() const     { return x * x + y * y + z * z; }

public:
    union {
        struct { float x, y, z; };
        struct { float r, g, b; };
        struct { float vec[3];    };
    };

};

inline float dot(const Vec3f &v1, const Vec3f &v2)      { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; } 
inline Vec3f cross(const Vec3f &v1, const Vec3f &v2) {
    return Vec3f(v1.y * v2.z - v2.y * v1.z, v1.z * v2.x - v2.z * v1.x, v1.x * v2.y - v2.x * v1.y);
}

}