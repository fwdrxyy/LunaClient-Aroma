#include "CompoundTag.h"

#include <Link/Link.h>

namespace mc {
    CompoundTag::CompoundTag() { Link::Func<void, 0x022182C0, CompoundTag *>()(this); }

    void CompoundTag::putLong(const mstd::wstring &str, long long l) { Link::Func<void, 0x0221aeb4, CompoundTag *, const mstd::wstring &, long long>()(this, str, l); }

    void CompoundTag::putInt(const mstd::wstring &str, int b) { Link::Func<void, 0x0221ae10, CompoundTag *, const mstd::wstring &, int>()(this, str, b); }

    void CompoundTag::putFloat(const mstd::wstring &str, float f) { Link::Func<void, 0x0221AF68, CompoundTag *, const mstd::wstring &, float>()(this, str, f); }

    void CompoundTag::putDouble(const mstd::wstring &str, double f) { Link::Func<void, 0x0221b01c, CompoundTag *, const mstd::wstring &, double>()(this, str, f); }

    void CompoundTag::putString(const mstd::wstring &str, const mstd::wstring &str2) {
        Link::Func<void, 0x022189dc, CompoundTag *, const mstd::wstring &, const mstd::wstring &>()(this, str, str2);
    }

    void CompoundTag::putBoolean(const mstd::wstring &str, bool b) { Link::Func<void, 0x0221B23C, CompoundTag *, const mstd::wstring &, bool>()(this, str, b); }

    void CompoundTag::putShort(const mstd::wstring &str, int16_t b) { Link::Func<void, 0x0221ad6c, CompoundTag *, const mstd::wstring &, int16_t>()(this, str, b); }

    void CompoundTag::put(const mstd::wstring &str, Tag *tag) { Link::Func<void, 0x02218A80, CompoundTag *, const mstd::wstring &, Tag *>()(this, str, tag); }

    void CompoundTag::putByte(const mstd::wstring &str, uint8_t b) { Link::Func<void, 0x0221acc8, CompoundTag *, const mstd::wstring &, uint8_t>()(this, str, b); }

    bool CompoundTag::contains(const mstd::wstring &str) { return Link::Func<bool, 0x02218400, CompoundTag *, const mstd::wstring &>()(this, str); }

    bool CompoundTag::equals(Tag *tag) { return Link::Func<bool, 0x0221c284, CompoundTag *, Tag *>()(this, tag); }

    void CompoundTag::remove(const mstd::wstring &str) { Link::Func<void, 0x0221be6c, CompoundTag *, const mstd::wstring &>()(this, str); }

    ListTag *CompoundTag::getList(const mstd::wstring &str, int unk) {
        return Link::Func<ListTag *, 0x0221b99c, CompoundTag *, const mstd::wstring &, int>()(this, str, unk);
    }

    CompoundTag *CompoundTag::getCompound(const mstd::wstring &str) { return Link::Func<CompoundTag *, 0x02218350, CompoundTag *, const mstd::wstring &>()(this, str); }

    class ByteArrayTag *CompoundTag::getByteArray(const mstd::wstring &str) {
        return Link::Func<class ByteArrayTag *, 0x0221b5e8, CompoundTag *, const mstd::wstring &>()(this, str);
    }

    void CompoundTag::getString(const mstd::wstring &ret, const mstd::wstring &str) {
        return Link::Func<void, 0x02218874, CompoundTag *, const mstd::wstring &, const mstd::wstring &>()(this, ret, str);
    }

    bool CompoundTag::getBoolean(const mstd::wstring &str) { return Link::Func<bool, 0x0221bbd8, CompoundTag *, const mstd::wstring &>()(this, str); }

    void CompoundTag::toString(const mstd::wstring &output_str) { Link::Func<void, 0x0221c024, CompoundTag *, const mstd::wstring &>()(this, output_str); }

    int CompoundTag::getInt(const mstd::wstring &str) { return Link::Func<int, 0x0221b37c, CompoundTag *, const mstd::wstring &>()(this, str); }

    CompoundTag *CompoundTag::copy() { return Link::Func<CompoundTag *, 0x0221c05c, CompoundTag *>()(this); }

    void CompoundTag::merge(mc::CompoundTag *toMerge) { Link::Func<void, 0x0221c924, CompoundTag *, CompoundTag *>()(this, toMerge); }

    mstd::vector<mstd::wstring> *CompoundTag::getAllKeys() { return Link::Func<mstd::vector<mstd::wstring> *, 0x0221AB80, CompoundTag *>()(this); }

    Tag *CompoundTag::get(const mstd::wstring &key) { return Link::Func<Tag *, 0x0221898c, CompoundTag *, const mstd::wstring &>()(this, key); }

    uint32_t CompoundTag::getTagType(const mstd::wstring &key) { return Link::Func<uint32_t, 0x02217308, CompoundTag *, const mstd::wstring &>()(this, key); }
} // namespace mc