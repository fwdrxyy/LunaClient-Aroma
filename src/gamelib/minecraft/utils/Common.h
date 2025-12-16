#pragma once

#include <utils/Types.h>

#include <Link/Link.h>

#define MC_VFUNC(return_type, class_type, function_name, ...)                                                                                                            \
    int flag_##function_name;                                                                                                                                            \
    return_type (*function_name)(class_type * _this, ##__VA_ARGS__)

#define DEFINE_STATIC_DEF_VAR(type, name, addr) static inline type default_##name = (type) addr;

#define DEFINE_STATIC_VAR(type, name, addr)     static inline type name = (type) addr;

#define ARR_LEN(arr)                            (sizeof(arr) / sizeof(arr[0]))

#define mc_swprintf                             ((int32_t (*)(wchar_t *, int32_t, const wchar_t *, ...)) 0x0382C8C0)

namespace mc {
    uint32_t getR1Register();

    template<typename T, typename U>
    T min(T t, U u) {
        return t > u ? u : t;
    }

    template<typename tChar>
    int mc_strlen(const tChar *str) {
        int length = 0;
        while (str[length] != 0) length++;

        return length;
    }

    template<typename... Args>
    int mc_snprintf(const char *out, uint32_t size, const char *__format, Args... args) {
        return Link::Func<int, 0x0382DF78, const char *, uint32_t, const char *, Args...>()(out, size, __format, args...);
    }

    template<typename... Args>
    int mc_swscanf(const wchar_t *buffer, const wchar_t *__format, Args... args) {
        return Link::Func<int, 0x0382b610, const wchar_t *, const wchar_t *, Args...>()(buffer, __format, args...);
    }

    template<typename... Args>
    int mc_sscanf(const char *buffer, const char *__format, Args... args) {
        return Link::Func<int, 0x0382f634, const char *, const char *, Args...>()(buffer, __format, args...);
    }

    template<typename tChar>
    int mc_strcmp(const tChar *str1, const tChar *str2) {
        switch (sizeof(tChar)) {
            case 0x1: // char
                return Link::Func<int, 0x0382cb74, const tChar *, const tChar *>()(str1, str2);
            case 0x2: // wchar_t
                return Link::Func<int, 0x0382c75c, const tChar *, const tChar *>()(str1, str2);
            default:
                return -1;
        }
    }

    // https://stackoverflow.com/questions/2249110/how-do-i-make-a-portable-isnan-isinf-function
    int isinf(double x);

    // https://stackoverflow.com/questions/2249110/how-do-i-make-a-portable-isnan-isinf-function
    int isnan(double x);

    void toCStr(float input, char *result, int decimalPlaces = 5);
} // namespace mc