#pragma once
#include "../math/vec3.h"
#include "../math/mat4.h"
#include <stdio.h>

using namespace Math;

void mathTest() {
    Mat4 mat1 = getTranslate(Vec3f(1.0f, 2.0f, 3.0f));
    Mat4 mat2 = getScale(Vec3f(2.0f, 2.0f, 2.0f));
    Mat4 mat3 = mat1 * mat2;

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            printf("%.4f ", mat3.arr[i][j]);
        }
        printf("\n");
    }
}
