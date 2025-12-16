#pragma once

namespace mc {
    enum ETagType {
        BYTE_TAG       = 0x1,
        SHORT_TAG      = 0x2,
        INT_TAG        = 0x3,
        LONG_TAG       = 0x4,
        FLOAT_TAG      = 0x5,
        DOUBLE_TAG     = 0x6,
        BYTE_ARRAY_TAG = 0x7,
        STRING_TAG     = 0x8,
        LIST_TAG       = 0x9,
        COMPOUND_TAG   = 0xA
    };

    class VTable_Tag;

    class Tag {
    public:
        Tag();

        VTable_Tag *vtable;
    };
} // namespace mc