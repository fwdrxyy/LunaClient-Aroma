#pragma once

#include "../LunaCategory.h"
#include "LunaSliderFOV.h"
#include "LunaToggleFullbright.h"
#include "LunaToggleAntiTexture.h"
#include "LunaToggleNoDmgTilt.h"
#include "LunaToggleShowDmgIndicator.h"

class LunaCategoryRender : public LunaCategory {
public:
    LunaCategoryRender() : LunaCategory("Render") {
        this->addModule(std::make_unique<LunaSliderFOV>());
        this->addModule(std::make_unique<LunaToggleFullbright>());
        this->addModule(std::make_unique<LunaToggleAntiTexture>());
        this->addModule(std::make_unique<LunaToggleNoDmgTilt>());
        this->addModule(std::make_unique<LunaToggleShowDmgIndicator>());
    }
};
