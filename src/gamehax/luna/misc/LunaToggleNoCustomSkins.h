#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleNoCustomSkins : public LunaToggle {
public:
    LunaToggleNoCustomSkins() : LunaToggle("No Custom Skins", false) {}

    void onEnable() override { Poke32(0x02F5E19C, 0x38600001); }
    void onDisable() override { Poke32(0x02F5E19C, 0x7FE3FB78); }
};