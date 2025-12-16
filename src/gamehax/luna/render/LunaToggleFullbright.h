#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleFullbright : public LunaToggle {
public:
    LunaToggleFullbright() : LunaToggle("Fullbright", false) {}

    void onEnable() override { Poke32(0x108C7C2C, 0x60000000); }
    void onDisable() override { Poke32(0x038076C4, 0x48000044); }
};
