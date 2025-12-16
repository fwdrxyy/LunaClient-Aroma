#pragma once

#include "../LunaCategory.h"
#include "LunaToggleNoCustomSkins.h"

class LunaCategoryMisc : public LunaCategory {
public:
    LunaCategoryMisc() : LunaCategory("Misc") { this->addModule(std::make_unique<LunaToggleNoCustomSkins>()); }
};