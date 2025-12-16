#include "MapPalette.h"

#include <Link/Link.h>

#include "../../utils/HashMap.h"

namespace mc {
    HashMap<uint32_t, uint8_t> *hashMap = nullptr;

    // https://github.com/Bukkit/Bukkit/blob/master/src/main/java/org/bukkit/map/MapPalette.java
    double MapPalette::getDistance(const Color &c1, const Color &c2) {
        double r = Link::toFloat(c1.r) - Link::toFloat(c2.r);
        double g = Link::toFloat(c1.g) - Link::toFloat(c2.g);
        double b = Link::toFloat(c1.b) - Link::toFloat(c2.b);
        return r * r + g * g + b * b;
    }

    uint8_t MapPalette::matchColor(const Color &color) {
        if (color.a < 128) return BLACK;

        uint32_t hexColor = color.asHex();
        if (hexColor == 0xFFFFFFFF) return WHITE;
        else if (hexColor == 0x000000FF)
            return BLACK;

        size_t hashIndex = -1;
        if (hashMap->contains(hexColor, hashIndex))
            return hashMap->getIndexed(hashIndex);

        auto convert = [&hexColor](int index,
                                   bool leftEarly = false) -> uint8_t {
            uint8_t result =
                    (uint8_t) (index < 128 ? index : -129 + (index - 127));
            hashMap->insert(hexColor, result);
            return result;
        };

        int index   = 0;
        double best = -1;
        for (int i = 4; i < (int) ARR_LEN(mapPaletteColors); i++) {
            double distance = getDistance(color, mapPaletteColors[i]);
            if (distance < 50.0) return convert(i, true);

            if (distance < best || best == -1) {
                best  = distance;
                index = i;
            }
        }

        uint8_t result = convert(index);
        return result;
    }

    void MapPalette::initColorPalette() {
        hashMap = new HashMap<uint32_t, uint8_t>(256);

        Color newPalette[144] = {Color(0, 0, 0, 0),    Color(0, 0, 0, 0),
                                 Color(0, 0, 0, 0),    Color(0, 0, 0, 0),
                                 Color(89, 125, 39),   Color(109, 153, 48),
                                 Color(127, 178, 56),  Color(67, 94, 29),
                                 Color(174, 164, 115), Color(213, 201, 140),
                                 Color(247, 233, 163), Color(130, 123, 86),
                                 Color(117, 117, 117), Color(144, 144, 144),
                                 Color(167, 167, 167), Color(88, 88, 88),
                                 Color(180, 0, 0),     Color(220, 0, 0),
                                 Color(255, 0, 0),     Color(135, 0, 0),
                                 Color(112, 112, 180), Color(138, 138, 220),
                                 Color(160, 160, 255), Color(84, 84, 135),
                                 Color(117, 117, 117), Color(144, 144, 144),
                                 Color(167, 167, 167), Color(88, 88, 88),
                                 Color(0, 87, 0),      Color(0, 106, 0),
                                 Color(0, 124, 0),     Color(0, 65, 0),
                                 Color(180, 180, 180), Color(220, 220, 220),
                                 Color(255, 255, 255), Color(135, 135, 135),
                                 Color(115, 118, 129), Color(141, 144, 158),
                                 Color(164, 168, 184), Color(86, 88, 97),
                                 Color(129, 74, 33),   Color(157, 91, 40),
                                 Color(183, 106, 47),  Color(96, 56, 24),
                                 Color(79, 79, 79),    Color(96, 96, 96),
                                 Color(112, 112, 112), Color(59, 59, 59),
                                 Color(45, 45, 180),   Color(55, 55, 220),
                                 Color(64, 64, 255),   Color(33, 33, 135),
                                 Color(73, 58, 35),    Color(89, 71, 43),
                                 Color(104, 83, 50),   Color(55, 43, 26),
                                 Color(180, 177, 172), Color(220, 217, 211),
                                 Color(255, 252, 245), Color(135, 133, 129),
                                 Color(152, 89, 36),   Color(186, 109, 44),
                                 Color(216, 127, 51),  Color(114, 67, 27),
                                 Color(125, 53, 152),  Color(153, 65, 186),
                                 Color(178, 76, 216),  Color(94, 40, 114),
                                 Color(72, 108, 152),  Color(88, 132, 186),
                                 Color(102, 153, 216), Color(54, 81, 114),
                                 Color(161, 161, 36),  Color(197, 197, 44),
                                 Color(229, 229, 51),  Color(121, 121, 27),
                                 Color(89, 144, 17),   Color(109, 176, 21),
                                 Color(127, 204, 25),  Color(67, 108, 13),
                                 Color(170, 89, 116),  Color(208, 109, 142),
                                 Color(242, 127, 165), Color(128, 67, 87),
                                 Color(53, 53, 53),    Color(65, 65, 65),
                                 Color(76, 76, 76),    Color(40, 40, 40),
                                 Color(108, 108, 108), Color(132, 132, 132),
                                 Color(153, 153, 153), Color(81, 81, 81),
                                 Color(53, 89, 108),   Color(65, 109, 132),
                                 Color(76, 127, 153),  Color(40, 67, 81),
                                 Color(89, 44, 125),   Color(109, 54, 153),
                                 Color(127, 63, 178),  Color(67, 33, 94),
                                 Color(36, 53, 125),   Color(44, 65, 153),
                                 Color(51, 76, 178),   Color(27, 40, 94),
                                 Color(72, 53, 36),    Color(88, 65, 44),
                                 Color(102, 76, 51),   Color(54, 40, 27),
                                 Color(72, 89, 36),    Color(88, 109, 44),
                                 Color(102, 127, 51),  Color(54, 67, 27),
                                 Color(108, 36, 36),   Color(132, 44, 44),
                                 Color(153, 51, 51),   Color(81, 27, 27),
                                 Color(17, 17, 17),    Color(21, 21, 21),
                                 Color(25, 25, 25),    Color(13, 13, 13),
                                 Color(176, 168, 54),  Color(215, 205, 66),
                                 Color(250, 238, 77),  Color(132, 126, 40),
                                 Color(64, 154, 150),  Color(79, 188, 183),
                                 Color(92, 219, 213),  Color(48, 115, 112),
                                 Color(52, 90, 180),   Color(63, 110, 220),
                                 Color(74, 128, 255),  Color(39, 67, 135),
                                 Color(0, 153, 40),    Color(0, 187, 50),
                                 Color(0, 217, 58),    Color(0, 114, 30),
                                 Color(14, 14, 21),    Color(18, 17, 26),
                                 Color(21, 20, 31),    Color(11, 10, 16),
                                 Color(79, 1, 0),      Color(96, 1, 0),
                                 Color(112, 2, 0),     Color(59, 1, 0)};

        for (int i = 0; i < (int) ARR_LEN(newPalette); i++)
            mapPaletteColors[i] = newPalette[i];
    }
} // namespace mc