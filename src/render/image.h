// make by hyq
// 2021/11/16

#pragma once

#include <string>
#include "../math/vec3f.h"

class Image {
public:
    Image();
    ~Image();
    bool read(const std::string file_path);
    bool write(const std::string file_path);
    int getWidth() const;
    int getHeight() const;
    int getChannels() const;
    void setWidth(const int w);
    void setHeight(const int h);
    void setChannels(const int c);
    Math::Vec3f getColor(const int u, const int v) const;
    Math::Vec3f getColor(const float u, const float v) const;
    bool empty() const;
private:
    int width_ = 800;
    int height_ = 600;
    int channels_ = 0;
    unsigned char *data_ = nullptr;
};