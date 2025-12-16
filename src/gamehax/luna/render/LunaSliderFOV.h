#pragma once

#include <utils/Logger.h>

#include "../LunaSlider.h"

class LunaSliderFOV : public LunaSlider<float32_t> {
public:
    LunaSliderFOV() : LunaSlider("FOV", 1.0f, 0.25f, 0.0f, 1.5f) {}

    void onUpdate() override { *(float32_t *) 0x1088E7D0 = this->value; }
};
