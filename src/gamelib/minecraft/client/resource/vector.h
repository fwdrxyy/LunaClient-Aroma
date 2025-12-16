#pragma once

#include "../../utils/Common.h"

// #define SHOULD_DEBUG
#ifdef SHOULD_DEBUG
#define _log(str, ...) mc::logConsolef(str, __VA_ARGS__)
#else
#define _log(str, ...) ;
#endif

namespace mstd {
    template<typename T>
    class vector {
    public:
        typedef T *iter;
        typedef const T *citer;

        iter begin() { return &start[0]; }
        citer begin() const { return &start[0]; }
        iter end() { return &start[size()]; }
        citer end() const { return &start[size()]; }

        vector() {
            _log("%08X | Creating Vector with Default Constructor\n", this);
            _Buy(0);
        }

        vector(size_t length) {
            _log("%08X | Creating Vector with length: %d\n", this, length);
            _Buy(length);
        }

        ~vector() {
            _log("%08X | Deleting Vector\n", this);
            _delete();
        }

        vector(vector<T> &&move) = delete;
        vector(const vector<T> &copy) {
            _Buy(copy.capacity());
            for (size_t i = 0; i < copy.size(); i++) this->at(i) = copy[i];
        }

        vector<T> &operator=(const vector<T> &copy) = delete;

        void _delete() {
            if (start) delete start;

            start          = nullptr;
            finish         = nullptr;
            end_of_storage = nullptr;
        }

        bool _Buy(size_t length) {
            _log("%08X | _Buy: Vector Buying Vector with length: %d\n", this,
                length);
            start          = nullptr;
            finish         = nullptr;
            end_of_storage = nullptr;

            if (length != 0) {
                // maxSize = 4 MiB
                size_t maxSize = (4 * 1024 * 1024);
                if ((length * sizeof(T)) < maxSize) {
                    T *data        = new T[length];
                    start          = data;
                    finish         = data;
                    end_of_storage = &data[length];

                    clear();

                    return true;
                } else {
                    _log("%08X | _Buy: Length too large, %d exceeds %d MiB\n",
                        this, length, maxSize);
                    return false;
                }
            }

            return false;
        }

        void push_back(const T &data) {
            size_t currentSize = (start != nullptr) ? (finish - start) : 0;
            size_t capacity = (start != nullptr) ? (end_of_storage - start) : 0;

            if (currentSize >= capacity) {
                size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
                _log("%08X | push_back: Growing vector from %d to %d\n", this,
                    capacity, newCapacity);

                T *oldData = new T[currentSize];
                for (int i = 0; i < (int) currentSize; i++) oldData[i] = at(i);

                delete[] start;

                _Buy(newCapacity);
                for (int i = 0; i < (int) currentSize; i++)
                    push_back(oldData[i]);

                delete oldData;
            }

            *finish = data;
            finish++;
        }

        iter erase(size_t index) {
            if (index < 0 || index >= size()) {
                _log("%08X | erase: Index out of bounds\n", this);
                return end();
            }

            for (size_t i = index; i < size() - 1; ++i) start[i] = start[i + 1];

            finish--;
            return start + index;
        }

        iter erase(iter position) {
            if (position < start || position >= finish) {
                _log("%08X | erase: Iterator out of bounds\n", this);
                return end();
            }

            for (iter it = position; it != finish - 1; ++it) *it = *(it + 1);

            finish--;
            return position;
        }

        T at(size_t i) const { return start[i]; }

        T &at(size_t i) { return start[i]; }

        T operator[](size_t i) const { return this->start[i]; }

        T &operator[](size_t i) { return this->start[i]; }

        T &back() { return this->start[size() - 1]; }

        void pop_back() { finish--; }

        size_t size() const {
            return ((size_t) finish - (size_t) start) / sizeof(T);
        }

        size_t capacity() const {
            return ((size_t) end_of_storage - (size_t) start) / sizeof(T);
        }

        size_t remainingSize() const {
            return ((size_t) end_of_storage - (size_t) finish) / sizeof(T);
        }

        void clear() {
            for (size_t i = 0; i < capacity(); i++) at(i) = T{};
        }

        T *data() { return start; }

        T *sort(bool (*f)(const T &, const T &)) {
            T *list = new T[size()];
            for (size_t i = 0; i < size(); i++) list[i] = at(i);

            T *temp = new T[1];
            for (size_t i = 0; i < size(); i++) {
                for (size_t j = 0; j < size(); j++) {
                    if (f(list[i], list[j])) {
                        *temp   = list[i];
                        list[i] = list[j];
                        list[j] = *temp;
                    }
                }
            }

            delete temp;
            return list;
        }

        uint32_t field_0x0 = 0;
        T *start           = nullptr;
        T *finish          = nullptr;
        T *end_of_storage  = nullptr;
    };
} // namespace mstd
