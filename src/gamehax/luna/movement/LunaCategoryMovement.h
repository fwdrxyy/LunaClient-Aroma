#pragma once

#include "../LunaCategory.h"
#include "LunaToggleAutoSprint.h"

class LunaCategoryMovement : public LunaCategory {
public:
    LunaCategoryMovement() : LunaCategory("Movement") { this->addModule(std::make_unique<LunaToggleAutoSprint>()); }
};