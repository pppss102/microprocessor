#ifndef __FLAT_MAP_H
#define __FLAT_MAP_H

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <optional>
#include <utility>
#include <vector>

// tfw no C++23

template <typename _Key, typename _Value> class FlatMap {
    using kv = std::pair<_Key, _Value>;
    std::vector<kv> data;
    std::function<bool(kv, kv)> comparator;

  public:
    FlatMap(std::initializer_list<kv> list) {
        comparator = [](kv lhs, kv rhs) { return lhs.first < rhs.first; };
        data.resize(list.size());
        std::copy(list.begin(), list.end(), data.begin());

        std::sort(data.begin(), data.end(), comparator);
    }

    std::optional<_Value> Find(_Key key) const {
        kv entry = {key, _Value()};
        auto it = std::lower_bound(data.begin(), data.end(), entry, comparator);
        return (it == data.end() || it->first != key)
                   ? std::nullopt
                   : std::optional<_Value>{it->second};
    }
};

#endif