#pragma once

#include "LunaModule.h"

#include <minecraft/Minecraft.h>

using namespace mc;

class LunaButton : public LunaModule {
public:
    LunaButton(const std::string &_name) : LunaModule(_name) {}

    void _onPress() override {
        onPress();
        ConsoleUIController::getInstance()->PlayUISFX(SoundEvent::MG03_emeraldPointTick);
    }

    int32_t getId() override { return 0; }
};
