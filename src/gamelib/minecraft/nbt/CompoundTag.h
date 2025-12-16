#pragma once

#include <utils/Types.h>

#include "Tag.h"

#include "../client/resource/vector.h"
#include "../client/resource/wstring.h"

namespace mc {
    class ListTag;
    class ByteArrayTag;

    class CompoundTag : public Tag {
    public:
        CompoundTag();

        static inline CompoundTag *Ctor(void *ptr) { return Link::Func<CompoundTag *, 0x022182C0, void *>()(ptr); }

        void putLong(const mstd::wstring &str, long long l);
        void putInt(const mstd::wstring &str, int b);
        void putFloat(const mstd::wstring &str, float f);
        void putDouble(const mstd::wstring &str, double f);
        void putString(const mstd::wstring &str, const mstd::wstring &str2);
        void putBoolean(const mstd::wstring &str, bool b);
        void putShort(const mstd::wstring &str, int16_t b);
        void put(const mstd::wstring &str, Tag *tag);
        void putByte(const mstd::wstring &str, uint8_t b);
        bool contains(const mstd::wstring &str);
        bool equals(Tag *tag);
        void remove(const mstd::wstring &str);
        ListTag *getList(const mstd::wstring &str, int unk);
        CompoundTag *getCompound(const mstd::wstring &str);
        ByteArrayTag *getByteArray(const mstd::wstring &str);
        void getString(const mstd::wstring &ret, const mstd::wstring &str);
        bool getBoolean(const mstd::wstring &str);
        void toString(const mstd::wstring &output_str);
        int getInt(const mstd::wstring &str);
        CompoundTag *copy();
        void merge(CompoundTag *toMerge);
        mstd::vector<mstd::wstring> *getAllKeys();
        Tag *get(const mstd::wstring &key);
        uint32_t getTagType(const mstd::wstring &key);

        static constexpr int getId() { return 0xA; }

        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t entries;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
    };
} // namespace mc