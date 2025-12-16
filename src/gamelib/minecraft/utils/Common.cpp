#include "Common.h"

#include <cstring>

namespace mc {
    uint32_t getR1Register() {
        uint32_t value;
        asm volatile("mr %0, 1" : "=r"(value));
        return value;
    }

    int isinf(double x) {
        union {
            uint64_t u;
            double f;
        } ieee754;
        ieee754.f = x;
        return ((unsigned) (ieee754.u >> 32) & 0x7fffffff) == 0x7ff00000 && ((unsigned) ieee754.u == 0);
    }

    int isnan(double x) {
        union {
            uint64_t u;
            double f;
        } ieee754;
        ieee754.f = x;
        return ((unsigned) (ieee754.u >> 32) & 0x7fffffff) + ((unsigned) ieee754.u != 0) > 0x7ff00000;
    }

    void toCStr(float input, char *result, int decimalPlaces) {
        uint32_t a0;
        memcpy(&a0, &input, sizeof(float));
        bool isNegative = (a0 & 0x80000000) == 0x80000000;
        if (isNegative) a0 -= 0x80000000;
        float a1;
        memcpy(&a1, &a0, sizeof(float));
        uint32_t multip = 1;
        for (int i = 0; i < decimalPlaces; i++) multip *= 10;
        uint32_t a     = static_cast<uint32_t>(a1 * Link::toFloat(multip));
        uint32_t a_dec = a % multip;
        a              = (a - a_dec) / multip;
        if (isnan(input)) {
            mc_snprintf(result, 0x20, "NaN");
        } else if (isinf(input)) {
            mc_snprintf(result, 0x20, "Inf");
        } else if (isNegative) {
            char strTemp2[0x20];
            mc_snprintf(strTemp2, 0x20, "-%d.%s0%dd", a, "%", decimalPlaces);
            mc_snprintf(result, 0x20, strTemp2, a_dec);
        } else {
            char strTemp2[0x20];
            mc_snprintf(strTemp2, 0x20, "%d.%s0%dd", a, "%", decimalPlaces);
            mc_snprintf(result, 0x20, strTemp2, a_dec);
        }
    }
} // namespace mc