#pragma once

#include <utils/Logger.h>

#include <Link/Link.h>

#include <minecraft/client/resource/vector.h>

template<typename Key, typename Value>
class HashMap {
public:
    HashMap(size_t initialSize = 32, float loadFactor = 0.75f)
        : table{initialSize}, loadFactor(loadFactor), count(0) {}

    ~HashMap() { table._delete(); }

    void insert(const Key &key, const Value &value) {
        if (Link::toFloat(count) / Link::toFloat(table.capacity()) > loadFactor)
            resize(table.capacity() * 2);

        size_t index = findSlot(key);
        if (!table[index].occupied) count++;

        table[index] = {key, value, true};
    }

    Value get(const Key &key) const {
        size_t index = findSlot(key);
        if (table[index].occupied) return table[index].value;

        DEBUG_FUNCTION_LINE_VERBOSE("Key not found");
        return 0;
    }

    Value getIndexed(size_t index) const {
        if (table[index].occupied) return table[index].value;

        DEBUG_FUNCTION_LINE_VERBOSE("Index Invalid");
        return 0;
    }

    bool contains(const Key &key) const {
        size_t index = findSlot(key);
        return table[index].occupied;
    }

    bool contains(const Key &key, size_t &_index) const {
        size_t index = findSlot(key);
        _index       = index;
        return table[index].occupied;
    }

    void erase(const Key &key) {
        size_t index = findSlot(key);
        if (table[index].occupied) {
            table[index].occupied = false;
            count--;
        } else {
            DEBUG_FUNCTION_LINE_VERBOSE("Key not found");
        }
    }

    size_t size() const { return count; }

private:
    struct Entry {
        Key key;
        Value value;
        bool occupied = false;
    };

    mstd::vector<Entry> table;
    float loadFactor;
    size_t count;

    size_t hash(const Key &key) const {
        return (key >> 8) * 2654435761 % table.capacity();
    }

    size_t findSlot(const Key &key) const {
        size_t index = hash(key);
        while (table[index].occupied && table[index].key != key)
            index = (index + 1) % table.capacity();

        return index;
    }

    void resize(size_t newSize) {
        mstd::vector<Entry> oldTable = table;
        table.clear();
        bool result = table._Buy(newSize);
        DEBUG_FUNCTION_LINE_VERBOSE("newSize: %d [%d Bytes] %s", newSize,
                                    newSize * sizeof(Entry),
                                    result ? "true" : "false");
        count = 0;

        for (int i = 0; i < (int) oldTable.capacity(); i++) {
            const auto &entry = oldTable[i];
            if (entry.occupied) insert(entry.key, entry.value);
        }
    }
};