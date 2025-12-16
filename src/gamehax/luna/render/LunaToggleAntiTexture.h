#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleAntiTexture : public LunaToggle {
public:
    LunaToggleAntiTexture() : LunaToggle("Anti Texture", false) {}

    void onEnable() override { Poke32(0x033982B4, 0x480000BC); }
    void onDisable() override { Poke32(0x033982B4, 0x41820080); }
};