#pragma once

#include <utils/Types.h>

#include "UIControl.h"

namespace mc {
    class UIControl_Base : public UIControl {
    public:
        uint8_t filler[0xC];
    };
} // namespace mc