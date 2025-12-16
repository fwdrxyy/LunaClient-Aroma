#pragma once

#include <utils/Types.h>

namespace mc {
    class C4JThreadImpl {
    public:
        C4JThreadImpl(int (*func)(void *), void *data, const char *name, int stack_size);

        void SetDeleteOnExit(bool ex);
        void Run();
        bool isRunning();

        uint8_t data[0x78];
    };
} // namespace mc