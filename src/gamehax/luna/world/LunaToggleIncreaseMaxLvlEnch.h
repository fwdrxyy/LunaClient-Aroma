#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleIncreaseMaxLvlEnch : public LunaToggle {
public:
    LunaToggleIncreaseMaxLvlEnch() : LunaToggle("Increase Max Lvl Ench", false) {}

    void onEnable() override {
        Poke32(0x02081C9C, 0x38600008);
        Poke32(0x02081FFC, 0x38600006);
        Poke32(0x02278618, 0x38600008);
        Poke32(0x022DDAC4, 0x38600006);
        Poke32(0x022E0680, 0x38600008);
        Poke32(0x02377B0C, 0x38600005);
        Poke32(0x02426D84, 0x38600006);
        Poke32(0x0244A47C, 0x38600004);
        Poke32(0x02510714, 0x38600005);
        Poke32(0x025E6710, 0x38600005);
        Poke32(0x0277EDEC, 0x38600005);
        Poke32(0x027F2CCC, 0x38600008);
        Poke32(0x029F2474, 0x38600005);
        Poke32(0x029F3080, 0x38600008);
        Poke32(0x029F31F8, 0x38600005);
        Poke32(0x029F2D48, 0x38600005);
        Poke32(0x02AA824C, 0x38600005);
    }
    void onDisable() override {
        Poke32(0x02081C9C, 0x38600005);
        Poke32(0x02081FFC, 0x38600002);
        Poke32(0x02278618, 0x38600005);
        Poke32(0x022DDAC4, 0x38600003);
        Poke32(0x022E0680, 0x38600005);
        Poke32(0x02377B0C, 0x38600002);
        Poke32(0x02426D84, 0x38600003);
        Poke32(0x0244A47C, 0x38600002);
        Poke32(0x02510714, 0x38600002);
        Poke32(0x025E6710, 0x38600003);
        Poke32(0x0277EDEC, 0x38600003);
        Poke32(0x027F2CCC, 0x38600004);
        Poke32(0x029F2474, 0x38600003);
        Poke32(0x029F3080, 0x38600005);
        Poke32(0x029F31F8, 0x38600003);
        Poke32(0x029F2D48, 0x38600003);
        Poke32(0x02AA824C, 0x38600003);
    }
};