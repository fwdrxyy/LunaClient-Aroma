#pragma once

#include <utils/Types.h>

#include "UIControl_Base.h"

namespace mc {
    class UIString;

    class UIControl_List : public UIControl_Base {
    public:
        void init(int param_1);
        void SetItemLabel(uint32_t id, UIString *str, bool param_3);

        uint32_t field_0x5C;
    };
} // namespace mc