#pragma once

#include <utils/Types.h>

#include "../../utils/Color.h"
#include "../../utils/Common.h"

namespace mc {
    static Color mapPaletteColors[144];

    // https://github.com/Bukkit/Bukkit/blob/master/src/main/java/org/bukkit/map/MapPalette.java
    class MapPalette {
    public:
        static double getDistance(const Color &c1, const Color &c2);
        static uint8_t matchColor(const Color &color);

        static const uint8_t TRANSPARENT = 0;
        static const uint8_t LIGHT_GREEN = 4;
        static const uint8_t LIGHT_BROWN = 8;
        static const uint8_t GRAY_1      = 12;
        static const uint8_t RED         = 16;
        static const uint8_t PALE_BLUE   = 20;
        static const uint8_t GRAY_2      = 24;
        static const uint8_t DARK_GREEN  = 28;
        static const uint8_t WHITE       = 32;
        static const uint8_t LIGHT_GRAY  = 36;
        static const uint8_t BROWN       = 40;
        static const uint8_t DARK_GRAY   = 44;
        static const uint8_t BLUE        = 48;
        static const uint8_t DARK_BROWN  = 52;
        static const uint8_t BLACK       = 116;

        static void initColorPalette();
    };
} // namespace mc