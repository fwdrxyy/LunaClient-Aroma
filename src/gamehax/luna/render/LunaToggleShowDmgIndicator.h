#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleShowDmgIndicator : public LunaToggle {
public:
    LunaToggleShowDmgIndicator() : LunaToggle("Show Damage Indicator", false) {}

    void onEnable() override {
        Poke32(0x02EA06D8, 0x38600001);
        Poke32(0x02EA072C, 0x38600001);
        Poke32(0x02EA07A0, 0xFC203890);
        Poke32(0x02EA08A0, 0xFC203890);
        Poke32(0x02EA0980, 0xFC203890);
    }
    void onDisable() override {
        Poke32(0x02EA06D8, 0x4E800421);
        Poke32(0x02EA072C, 0x4E800421);
        Poke32(0x02EA07A0, 0x4E800421);
        Poke32(0x02EA08A0, 0x4E800421);
        Poke32(0x02EA0980, 0x4E800421);
    }
};