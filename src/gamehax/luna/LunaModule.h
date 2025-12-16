#pragma once

#include <string>

class LunaModule {
public:
    LunaModule(const std::string &_name) { this->name = _name; }

    virtual void _onPress() { DEBUG_FUNCTION_LINE("%s: _onPress() not implemented", this->name.c_str()); }
    virtual void onPress() { DEBUG_FUNCTION_LINE("%s: onPress() not implemented", this->name.c_str()); }
    [[nodiscard]] virtual int32_t getId() = 0;

    [[nodiscard]] virtual bool isSlider() const { return false; }
    virtual void sliderIncrease() {}
    virtual void sliderDecrease() {}

    virtual void composeLine(wchar_t *out, size_t outLen, bool selected) const { mc_swprintf(out, outLen, L"%s%s", selected ? "> " : "", this->name.c_str()); }

    std::string name;
};
