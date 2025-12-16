#pragma once

#include <utils/Kernel.h>

#include "../LunaToggle.h"

class LunaToggleAutoSprint : public LunaToggle {
public:
    LunaToggleAutoSprint() : LunaToggle("Auto Sprint", false) {}

    void onEnable() override {
        Poke32(0x031ED0A4, 0x48000018);
        Poke32(0x031ED0C4, 0x60000000);
        Poke32(0x031A62E4, 0x38600000);
        Poke32(0x031ECF5C, 0x38000001);
    }

    void onDisable() override {
        Poke32(0x031ED0A4, 0x40820018);
        Poke32(0x031ED0C4, 0x41820050);
        Poke32(0x031A62E4, 0x4E800421);
        Poke32(0x031ECF5C, 0x881E015C);
    }
};