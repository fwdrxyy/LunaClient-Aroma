#include "Link.h"

namespace Link {
    Mem::Mem(uint32_t addr) { base = addr; }

    Mem Mem::operator[](int offset) const { return Mem(as<uint32_t>() + offset); }

    int toInt(float input) {
        bool negative = input < 0.0f;
        if (negative) input *= -1.0f;

        uint32_t output = static_cast<uint32_t>(input);
        if (negative) {
            output -= 0x80000000;
            output = 0x80000000 - output;
            output -= 1;
        }

        return output;
    }

    float toFloat(int input) {
        bool negative           = 0 > input;
        unsigned int output_tmp = negative ? -input : input;
        float output            = static_cast<float>(output_tmp);
        return negative ? -output : output;
    }

    double toDouble(int input) {
        bool negative     = input < 0;
        uint32_t absInput = negative ? -static_cast<uint32_t>(input) : static_cast<uint32_t>(input);
        double output     = static_cast<double>(absInput);
        return negative ? -output : output;
    }
} // namespace Link