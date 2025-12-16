#pragma once

#include <utils/Kernel.h>

#include "../LunaToggle.h"

class LunaToggleNoHitDelay : public LunaToggle {
public:
    LunaToggleNoHitDelay() : LunaToggle("No Hit Delay", false) {}

    void onEnable() override { Poke32(0x10665E20, 0x44000000); }

    void onDisable() override { Poke32(0x10665E20, 0x3F000000); }
};