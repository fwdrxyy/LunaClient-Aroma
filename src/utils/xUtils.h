#ifndef XUTILS_H
#define XUTILS_H

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <whb/log.h>

// #define XU_DEBUG
#ifdef XU_DEBUG
#define XU_LOG(fmt, ...)                WHBLogWritef("%30s@L%04d: " fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define XU_DEBUG_VAR(type, name, value) type name = value
#else
#define XU_LOG(fmt, ...)                                                                                                                                                 \
    do {                                                                                                                                                                 \
    } while (false)
#define XU_DEBUG_VAR(type, name, value) (void) sizeof(value)
#endif // XU_DEBUG

template<typename T>
class xVector {
    std::vector<T> _data;

    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;

public:
    using value_type      = T;
    using iterator        = typename std::vector<T>::iterator;
    using const_iterator  = typename std::vector<T>::const_iterator;
    using reference       = T &;
    using const_reference = const T &;

    xVector() { XU_LOG("ctor default size=%zu cap=%zu\n", _data.size(), _data.capacity()); }
    xVector(std::initializer_list<T> init) : _data(init) { XU_LOG("ctor init size=%zu cap=%zu\n", _data.size(), _data.capacity()); }

    iterator begin() noexcept { return _data.begin(); }
    const_iterator begin() const noexcept { return _data.begin(); }
    iterator end() noexcept { return _data.end(); }
    const_iterator end() const noexcept { return _data.end(); }

    bool empty() const noexcept { return _data.empty(); }
    size_type size() const noexcept { return _data.size(); }
    size_type capacity() const noexcept { return _data.capacity(); }

    reference front() { return _data.front(); }
    const_reference front() const { return _data.front(); }

    reference back() { return _data.back(); }
    const_reference back() const { return _data.back(); }

    reference operator[](size_type idx) { return _data[idx]; }
    const_reference operator[](size_type idx) const { return _data[idx]; }

    reference at(size_type idx) { return _data.at(idx); }
    const_reference at(size_type idx) const { return _data.at(idx); }

    T *data() noexcept { return _data.data(); }
    const T *data() const noexcept { return _data.data(); }

    void clear() { _data.clear(); }

    void push_back(const T &value) { _data.push_back(value); }

    void push_back(T &&value) { _data.push_back(std::move(value)); }

    template<class... Args>
    void emplace_back(Args &&...args) {
        _data.emplace_back(std::forward<Args>(args)...);
    }

    void pop_back() {
        if (_data.empty()) return;
        XU_DEBUG_VAR(size_type, old_sz, _data.size());
        _data.pop_back();
        XU_LOG("pop_back size=%zu->%zu\n", old_sz, _data.size());
    }

    iterator erase(iterator pos) {
        XU_DEBUG_VAR(size_type, idx, static_cast<size_type>(std::distance(_data.begin(), pos)));
        XU_DEBUG_VAR(size_type, old_sz, _data.size());
        auto it = _data.erase(pos);
        XU_LOG("erase idx=%zu size=%zu->%zu\n", idx, old_sz, _data.size());
        return it;
    }

    iterator erase(iterator first, iterator last) {
        XU_DEBUG_VAR(size_type, start, static_cast<size_type>(std::distance(_data.begin(), first)));
        XU_DEBUG_VAR(size_type, count, static_cast<size_type>(std::distance(first, last)));
        XU_DEBUG_VAR(size_type, old_sz, _data.size());
        auto it = _data.erase(first, last);
        XU_LOG("erase range start=%zu count=%zu size=%zu->%zu\n", start, count, old_sz, _data.size());
        return it;
    }

    void reserve(size_type n) {
        XU_DEBUG_VAR(size_type, old_cap, _data.capacity());
        _data.reserve(n);
        XU_LOG("reserve %zu->%zu\n", old_cap, _data.capacity());
    }

    void resize(size_type n) {
        XU_DEBUG_VAR(size_type, old_sz, _data.size());
        _data.resize(n);
    }

    void shrink_to_fit() {
        XU_DEBUG_VAR(size_type, old_cap, _data.capacity());
        _data.shrink_to_fit();
        XU_LOG("shrink_to_fit %zu->%zu\n", old_cap, _data.capacity());
    }

    void swap(xVector &other) noexcept {
        XU_LOG("swap sizes %zu<->%zu\n", _data.size(), other._data.size());
        _data.swap(other._data);
    }

    xVector &filter(bool (*pred)(const T &)) {
        XU_DEBUG_VAR(size_type, old_sz, _data.size());
        _data.erase(std::remove_if(_data.begin(), _data.end(), [pred](const T &v) { return !pred(v); }), _data.end());
        XU_LOG("filter removed=%zu size=%zu\n", old_sz - _data.size(), _data.size());
        return *this;
    }

    xVector &remove_value(const T &value) {
        XU_DEBUG_VAR(size_type, old_sz, _data.size());
        _data.erase(std::remove(_data.begin(), _data.end(), value), _data.end());
        XU_LOG("remove_value removed=%zu size=%zu\n", old_sz - _data.size(), _data.size());
        return *this;
    }

    xVector &sort() {
        XU_LOG("sort size=%zu\n", _data.size());
        std::sort(_data.begin(), _data.end());
        return *this;
    }

    xVector &reverse() {
        XU_LOG("reverse size=%zu\n", _data.size());
        std::reverse(_data.begin(), _data.end());
        return *this;
    }

    xVector slice(size_type start, size_type end) const {
        if (start > end || end > _data.size()) throw std::out_of_range("slice indices out of range");
        XU_LOG("slice [%zu,%zu) size=%zu\n", start, end, _data.size());
        return xVector(_data.begin() + start, _data.begin() + end);
    }

    bool contains(const T &value) const {
        bool found = std::find(_data.begin(), _data.end(), value) != _data.end();
        XU_LOG("contains %s\n", found ? "true" : "false");
        return found;
    }

    difference_type index_of(const T &value) const {
        auto it             = std::find(_data.begin(), _data.end(), value);
        difference_type idx = it == _data.end() ? -1 : std::distance(_data.begin(), it);
        XU_LOG("index_of %zd\n", idx);
        return idx;
    }

    std::string join(const std::string &delim = ",") const {
        XU_LOG("join size=%zu\n", _data.size());
        std::ostringstream oss;
        for (size_type i = 0; i < _data.size(); ++i) {
            oss << _data[i];
            if (i + 1 < _data.size()) oss << delim;
        }

        return oss.str();
    }

    template<class UnaryFn>
    auto map(UnaryFn fn) const -> xVector<decltype(fn(std::declval<T>()))> {
        XU_LOG("map size=%zu\n", _data.size());
        using U = decltype(fn(std::declval<T>()));
        xVector<U> out;
        out.reserve(_data.size());
        std::transform(_data.begin(), _data.end(), std::back_inserter(out.std_vector()), fn);
        return out;
    }

    const std::vector<T> &std_vector() const noexcept { return _data; }
    std::vector<T> &std_vector() noexcept { return _data; }

private:
    template<typename It>
    xVector(It first, It last) : _data(first, last) {
        XU_LOG("ctor slice size=%zu cap=%zu\n", _data.size(), _data.capacity());
    }
};

#endif // XUTILS_H
