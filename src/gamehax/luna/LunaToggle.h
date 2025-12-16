#pragma once

#include <utils/Logger.h>

#include "LunaModule.h"

#include <minecraft/Minecraft.h>

using namespace mc;

class LunaToggle : public LunaModule {
public:
    LunaToggle(const std::string &_name, bool _enabled) : LunaModule(_name) { this->enabled = _enabled; }

    void _onPress() override {
        onPress();

        this->enabled = !this->enabled;
        if (this->enabled) {
            onEnable();
            ConsoleUIController::getInstance()->PlayUISFX(SoundEvent::MG03_emeraldPointTick);
        } else {
            onDisable();
            ConsoleUIController::getInstance()->PlayUISFX(SoundEvent::MG03_emeraldPointTok);
        }
    }

    int32_t getId() override { return 1; }

    virtual void onEnable() { DEBUG_FUNCTION_LINE("%s: onEnable() not implemented", this->name.c_str()); }
    virtual void onDisable() { DEBUG_FUNCTION_LINE("%s: onDisable() not implemented", this->name.c_str()); }

    bool enabled;
};
