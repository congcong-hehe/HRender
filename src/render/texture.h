// make by hyq
// 2021/11/16

#pragma once

#include "image.h"
#include "context.h"

class Texture {
public:
    Math::Vec3f sample(const float u, const float v) const;
    void load(const std::string &file_path);
    void setMode(TextureMode mode) { mode_ = mode; }

private:
    TextureMode mode_ = TextureMode::LINEAR;
    Image image_;
};