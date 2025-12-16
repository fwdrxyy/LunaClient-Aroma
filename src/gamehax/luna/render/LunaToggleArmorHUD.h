#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleArmorHUD : public LunaToggle {
public:
    LunaToggleArmorHUD() : LunaToggle("ArmorHUD", false) {}

    void onEnable() override { Poke32(0x02E9B1B0, 0x7FE4FB78); }
    void onDisable() override { Poke32(0x02E9B1B0, 0x7FC4F378);; }
};





