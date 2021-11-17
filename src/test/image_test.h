#pragma once

#include "../render/image.h"
#include "../base.h"

using namespace std;
using namespace Math;

void imageTest() {
    // 文件读取
    Image image;
    image.read(current_path + "image/texture/wall.jpg");
    // 文件写入
    image.write(current_path + "image/result/wall.png");
}