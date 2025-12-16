#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleFishingRodDmg : public LunaToggle {
public:
    LunaToggleFishingRodDmg() : LunaToggle("Fishing Rod Damage", false) {}

    void onEnable() override { Poke32(0x0241D80C, 0xC0250AD4); }
    void onDisable() override { Poke32(0x0241D80C, 0xC0250AB8); }
};