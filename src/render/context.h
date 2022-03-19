// make by hyq
// 2021/11/17

#pragma once

enum class Mode { WIRE, FILL};

enum class TextureMode { LINEAR, NEAREST };

class Context {
public:
    Mode mode;  // 绘制的模式：线框还是填充

    Context();
    ~Context();
    void reset();
};