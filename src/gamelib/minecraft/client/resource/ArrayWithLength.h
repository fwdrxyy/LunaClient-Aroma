#pragma once

namespace mc {
    template<typename T>
    class ArrayWithLength {    
    public:
        ArrayWithLength(T* arr, int size) {
            buffer = arr;
            length = size;
        }   

        ArrayWithLength() = default;

        T& operator[](int index) {
            return buffer[index];
        }

        T operator[](int index) const {
            return buffer[index];
        }

        T* buffer = nullptr;
        int length = 0;
    };
}