// make by hyq
// 2021/11/17

#include "context.h"

Context::Context() {
    reset();
}

Context::~Context() {

}

void Context::reset() {
    mode = Mode::FILL;
}