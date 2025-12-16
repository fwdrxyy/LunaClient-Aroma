#pragma once

#include "../LunaCategory.h"
#include "LunaToggleNoHitDelay.h"
#include "LunaToggleSignCommand.h"
#include "LunaToggleFishingRodDmg.h"
#include "LunaToggleUntreasureMend.h"
#include "LunaToggleIncreaseMaxLvlEnch.h"

class LunaCategoryWorld : public LunaCategory {
public:
    LunaCategoryWorld() : LunaCategory("World") {
        this->addModule(std::make_unique<LunaToggleNoHitDelay>());
        this->addModule(std::make_unique<LunaToggleSignCommand>());
        this->addModule(std::make_unique<LunaToggleFishingRodDmg>());
        this->addModule(std::make_unique<LunaToggleUntreasureMend>());
        this->addModule(std::make_unique<LunaToggleIncreaseMaxLvlEnch>());

    }
};