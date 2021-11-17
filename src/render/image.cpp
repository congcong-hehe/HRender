// make by hyq
// 2021/11/16

#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../third_party/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../../third_party/stb_image_write.h"
#include <iostream>
#include <string>
using namespace std;
using namespace Math;

Image::Image() {
    
}

Image::~Image() {
    stbi_image_free(data_);
}

bool Image::read(const string file_path) {
    data_ = stbi_load(file_path.c_str(), &width_, &height_, &channels_, channels_);
    if(!data_) {
        printf("ERROR: Could not load image file %s\n", file_path.c_str());
        return false;
    } else {
        printf("LOG: Load image file %s\n", file_path.c_str());
        return true;
    }
}

// 暂时全部保存为png形式
bool Image::write(const string file_path) {
    int tag = stbi_write_png(file_path.c_str(), width_, height_, channels_, data_, width_ * channels_);
    if(0 == tag) {
        printf("ERROR: Could not write image file %s\n", file_path.c_str());
        return false;
    } else {
        printf("LOG: Write image file %s\n", file_path.c_str());
        return true;
    }
}

inline int Image::getHeight() const {
    return height_;
}

inline int Image::getWidth() const {
    return width_;
}

inline int Image::getChannels() const {
    return channels_;
}

inline void Image::setWidth(const int w) {
    width_ = w;
}

inline void Image::setHeight(const int h) {
    height_ = h;
}

inline void Image::setChannels(const int c) {
    channels_ = c;
}

Math::Vec3f Image::getColor(const int u, const int v) const {
    return Vec3f();
}

Math::Vec3f Image::getColor(const float u, const float v) const {
    return Vec3f();
}

inline bool Image::empty() const {
    return !data_;
}