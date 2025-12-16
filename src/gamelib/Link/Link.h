#pragma once

#include <utils/Types.h>

#include "Random.h"

namespace Link {
    template<typename ret, uint32_t _addr, typename... Args>
    class Func {
    public:
        inline constexpr uint32_t addr() const { return _addr; }
        inline constexpr ret operator()(Args... args) { return ((ret (*)(Args...))(_addr))(args...); }
    };

    class Mem {
    public:
        Mem(uint32_t addr);
        Mem operator[](int offset) const;

        template<typename T>
        T &as() const {
            return *reinterpret_cast<T *>(base);
        }

    private:
        uint32_t base;
    };

    int toInt(float input);
    float toFloat(int input);
    double toDouble(int input);
} // namespace Link