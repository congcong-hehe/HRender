// make by hyq
// 2021/11/16

#include "texture.h"
#include "builtin_fun.h"

// 参考 https://blog.csdn.net/weixin_39978257/article/details/110900870

Math::Vec3f Texture::sample(float u, float v) const {
    if(TextureMode::LINEAR == mode_) {  // 计算双线性插值
        u = u * image_.getHeight() - 0.5f;
        float u_f = fract(u);
        v = v * image_.getWidth() - 0.5f;
        float v_f = fract(v);

        int x = static_cast<int>(u) % image_.getWidth();
        int y = static_cast<int>(v) % image_.getHeight();

        // 边缘情况特殊处理
        if(u < 0 || v < 0) return image_.getColor(x, y);
        if(x == image_.getHeight() - 1 || y == image_.getWidth() - 1) return image_.getColor(x, y);
        
        Math::Vec3f c1 = image_.getColor(x, y);
        Math::Vec3f c2 = image_.getColor(x + 1, y);
        Math::Vec3f c3 = image_.getColor(x, y + 1);
        Math::Vec3f c4 = image_.getColor(x + 1, y + 1);

        return lerp(lerp(c1, c2, u_f), lerp(c3, c4, u_f), v_f);
    } else { // Nearest: 得到最近的像素点的颜色
        int x = static_cast<int>(u * image_.getHeight()) % image_.getHeight();
        int y = static_cast<int>(v * image_.getWidth()) % image_.getWidth();
        return image_.getColor(x, y);
    }
}

void Texture::load(const std::string &file_path)
{
    image_.read(file_path);
}