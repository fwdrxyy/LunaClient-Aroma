#pragma once

#include <utils/Types.h>

namespace mc {
    class UIControl_MultiList;

    class MultiListSliderLogic {
    public:
        MultiListSliderLogic();

        void AddTo(UIControl_MultiList &list, int32_t param_2);

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
    };
} // namespace mc