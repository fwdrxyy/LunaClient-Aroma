#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleNoDmgTilt : public LunaToggle {
public:
    LunaToggleNoDmgTilt() : LunaToggle("No Damage Tilt", false) {}

    void onEnable() override { Poke32(0x03100550, 0x3B600000); }
    void onDisable() override { Poke32(0x03100550, 0x553BDFFE); }
};