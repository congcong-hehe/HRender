// make by hyq
// 2022/3/19

#include "vec4.h"
#include "vec3.h"
#include <math.h>

namespace Math{

struct Mat4
{
    float arr[4][4];

    Mat4() {
        arr[0][0] = arr[1][1] = arr[2][2] = arr[3][3] = 1.0f;
        arr[0][1] = arr[0][2] = arr[0][3] = 0.0f;
        arr[1][0] = arr[1][2] = arr[1][3] = 0.0f;
        arr[2][0] = arr[2][1] = arr[2][3] = 0.0f;
        arr[3][0] = arr[3][1] = arr[3][2] = 0.0f;
    }

    Mat4 operator + (const Mat4 &mat) const {
        Mat4 ans;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                ans.arr[i][j] = this->arr[i][j] + mat.arr[i][j];
            }
        }
        return ans;
    }

    Mat4 operator * (const Mat4 &mat) const {
        Mat4 ans;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                ans.arr[i][j] = 0.0f;
                for(int p = 0; p < 4; ++p)
                    ans.arr[i][j] += this->arr[i][p] * mat.arr[j][p];
            }
        }
        return ans;
    }

    Vec4f operator * (const Vec4f &vec) const {
        Vec4f ans;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                ans[i] = arr[i][j] * vec[j];
            }
        }
        return ans;
    }
};

inline Mat4 translate(Vec3f &vec) {
    Mat4 mat;
    mat.arr[0][3] = vec[0];
    mat.arr[1][3] = vec[1];
    mat.arr[2][3] = vec[2];

    return mat;
}

inline Mat4 scale(Vec3f &vec) {
    Mat4 mat;
    mat.arr[0][0] = vec[0];
    mat.arr[1][1] = vec[1];
    mat.arr[2][2] = vec[2];

    return mat;
}

enum AXIS {X, Y, Z};

// theta是弧度值
inline Mat4 rotate(Vec3f &vec, AXIS I, float theta) {
    Mat4 mat;
    float cos_theta = cos(theta);
    float sin_theta = sin(theta);
    switch (I)
    {
    case AXIS::X :
        mat.arr[1][1] = cos_theta;
        mat.arr[1][2] = -sin_theta;
        mat.arr[2][1] = sin_theta;
        mat.arr[2][2] = cos_theta;
        break;
    case AXIS::Y :
        mat.arr[0][0] = cos_theta;
        mat.arr[0][2] = sin_theta;
        mat.arr[2][0] = -sin_theta;
        mat.arr[2][2] = cos_theta;
        break;

    case AXIS::Z :
        mat.arr[0][0] = cos_theta;
        mat.arr[0][1] = -sin_theta;
        mat.arr[1][0] = sin_theta;
        mat.arr[1][1] = cos_theta;
        break;
    default:
        break;
    }
    return mat;
}

    Mat4 ortho(float left, float right, float bottom, float top, float znear, float zfar) {
        Mat4 ans;

        return ans;
    }

    Mat4 perspective(float fovx, float aspect, float znear, float zfar) {
        Mat4 ans;

        return ans;
    }

}