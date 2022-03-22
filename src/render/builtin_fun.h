#pragma once

#include "../math/vec.h"

template<typename T>
inline T lerp(T &a, T &b, float weight) {
    return (1.0f - weight) * a + weight * b;
}

// 得到正数浮点数的小数部分
inline float fract(const float f) {
    return f - static_cast<int>(f);
}
