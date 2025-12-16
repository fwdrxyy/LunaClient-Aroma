#pragma once

#include <utils/Types.h>

namespace mc {
    class Color {
    public:
        Color(uint8_t r, uint8_t g, uint8_t b);
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        Color(uint32_t rgba);
        Color();

        // In RGBA Format
        uint32_t asHex() const;

        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
} // namespace mc