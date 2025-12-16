#pragma once

#include <utils/Logger.h>

#include "LunaModule.h"

#include <minecraft/Minecraft.h>

using namespace mc;

template<typename T>
class LunaSlider : public LunaModule {
public:
    LunaSlider(const std::string &_name, T _value, T _increment, T _min, T _max) : LunaModule(_name) {
        this->value     = _value;
        this->increment = _increment;
        this->min       = _min;
        this->max       = _max;
    }

    bool isSlider() const override { return true; }

    void sliderIncrease() override {
        if (this->value == this->max) this->value = this->min;
        else
            this->value += this->increment;

        onUpdate();
    }

    void sliderDecrease() override {
        if (this->value == this->min) this->value = this->max;
        else
            this->value -= this->increment;

        onUpdate();
    }

    void composeLine(wchar_t *out, size_t outSize, bool selected) const override {
        if constexpr (std::is_floating_point_v<T>) {
            wchar_t valBuf[32];
            double v = (float64_t) this->value;
            mc_swprintf(valBuf, sizeof(valBuf) / sizeof(wchar_t), L"%.10g", v);
            mc_swprintf(out, outSize, L"%s(%ls) %hs", selected ? "> " : "", valBuf, this->name.c_str());
        } else
            mc_swprintf(out, outSize, L"%s(%d) %hs", selected ? "> " : "", (int32_t) this->value, this->name.c_str());
    }


    virtual void onUpdate() { DEBUG_FUNCTION_LINE("%s: onUpdate() not implemented", this->name.c_str()); }

    int32_t getId() override { return 2; }

    T value;
    T increment;
    T min;
    T max;
};
