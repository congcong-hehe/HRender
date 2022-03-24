#pragma once

#include "../math/vec.h"

const float PI = 3.1415926535898f;

template<typename T>
inline T lerp(T &a, T &b, float weight) {
    return (1.0f - weight) * a + weight * b;
}

// 得到正数浮点数的小数部分
inline float fract(const float f) {
    return f - static_cast<int>(f);
}

inline float radians(float angle) {
    return angle * PI / 180.0f;
}
