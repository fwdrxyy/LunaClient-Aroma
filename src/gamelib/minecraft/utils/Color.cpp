#include "Color.h"

namespace mc {
    Color::Color(uint8_t r, uint8_t g, uint8_t b) : r{r}, g{g}, b{b}, a{0xFF} {}

    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r{r}, g{g}, b{b}, a{a} {}

    Color::Color(uint32_t rgba) {
        this->r = (rgba >> 24) & 0xFF;
        this->g = (rgba >> 16) & 0xFF;
        this->b = (rgba >> 8)  & 0xFF;
        this->a = (rgba >> 0)  & 0xFF;
    }

    Color::Color() {
        r = 0;
        g = 0;
        b = 0;
        a = 0xFF;
    }

    uint32_t Color::asHex() const {
        uint32_t ret;
        ((uint8_t*) &ret)[0] = r;
        ((uint8_t*) &ret)[1] = g;
        ((uint8_t*) &ret)[2] = b;
        ((uint8_t*) &ret)[3] = a;
        return ret;
    }
}