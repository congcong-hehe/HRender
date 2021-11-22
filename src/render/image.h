// make by hyq
// 2021/11/16

#pragma once

#include <string>
#include "../math/vec3f.h"

class Image {
public:
    Image();
    ~Image();
    bool read(const std::string &file_path);
    bool write(const std::string &file_path);
    Math::Vec3f getColor(const int u, const int v) const;
    Math::Vec3f getColor(const float u, const float v) const;
    void setColor(const int u, const int v, const Math::Vec3f &color) const;
    bool init();

    inline int getHeight() const { return height_; }
    inline int getWidth() const { return width_; }
    inline int getChannels() const { return channels_; } 
    inline void setWidth(const int w) { width_ = w; }
    inline void setHeight(const int h) { height_ = h; }
    inline void setChannels(const int c) { channels_ = c; }
    inline bool empty() const {return !data_; };

private:
    int width_ = 800;
    int height_ = 600;
    int channels_ = 3;
    unsigned char *data_ = nullptr;
};