// make by hyq
// 2021/11/17

#pragma once

enum class Mode { WIRE, FILL};

class Context {
public:
    Mode mode;

    Context();
    ~Context();
    void reset();
};