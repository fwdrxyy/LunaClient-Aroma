#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleUntreasureMend : public LunaToggle {
public:
    LunaToggleUntreasureMend() : LunaToggle("Untreasure Mending", false) {}

    void onEnable() override { Poke32(0x0261B3B8, 0x38600000); }
    void onDisable() override { Poke32(0x0261B3B8, 0x38600001); }
};