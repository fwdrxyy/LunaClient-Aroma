#pragma once

#include <utils/Types.h>

namespace mc {
    class CInput {
    public:
        enum KeyboardMode : int { FULL = 0, NUMPAD = 1, UTF8 = 2, NNID = 3 };

        static CInput *GetInput();

        void GetText(const wchar_t *buffer, int32_t length);
        bool RequestKeyboard(const wchar_t *nothing, const wchar_t *default_text, uint32_t unk_Ui0, uint32_t max_size, int (*call_back)(void *, bool), void *arg1,
                             KeyboardMode eKeyboardMode);
    };
} // namespace mc