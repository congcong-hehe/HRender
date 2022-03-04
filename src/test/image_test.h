#pragma once

#include "../render/image.h"
#include "../base.h"

using namespace std;
using namespace Math;

void imageTest() {
    Image image;

    // 基本读写
    {
        // 文件读取
        image.read(current_path + "assets/wall.jpg");
        // 文件写入
        image.write(current_path + "result/wall.png");
    }

    // 取像素
    // {
    //     // 文件读取
    //     image.read(current_path + "image/texture/wall.jpg");
    //     // 逐像素读取
    //     Vec3f color = image.getColor(0.5f, 0.5f);
    //     printf("%f %f %f\n", color.x, color.y, color.z);
    // }

    // 写入像素
    // {
    //     image.setWidth(400);
    //     image.setHeight(400);
    //     image.init();
    //     for(int i = 0; i < 400; ++i) {
    //         for(int j = 0; j < 400; ++j) {
    //             image.setColor(i, j, Vec3f(static_cast<float>(i + j) / 800, 0.0f, 0.0f));
    //         }
    //     }
    //     image.write(current_path + "result/red.png");
    // }

    // 写入像素2，检查是否颠倒与颜色是否正确
    // {
    //     image.read(current_path + "assets/awesomeface.png");
    //     printf("%d %d %d\n", image.getWidth(), image.getHeight(), image.getChannels());
    //     for(int i = 0; i < image.getHeight(); ++i) {
    //         for(int j = 0; j < image.getWidth(); ++j) {
    //             image.setColor(i, j, image.getColor(i, j));
    //         }
    //     }
    //     image.write(current_path + "result/awesomeface_copy.png");
    // }

    // 使用某一种颜色刷新
    // {
    //     image.setWidth(400);
    //     image.setHeight(400);
    //     image.init();
    //     image.setBackColor(Math::Vec3f(1.0, 0.0, 0.0));
    //     image.write(current_path + "result/red.png");
    // }

}