#ifndef __FLAT_MAP_H
#define __FLAT_MAP_H

#include <algorithm>
#include <initializer_list>
#include <utility>
#include <vector>

// tfw no C++23

template <typename _Key, typename _Value> class FlatMap {
    using kv = std::pair<_Key, _Value>;
    std::vector<kv> data;

    static auto comparator = [](kv const& lhs, kv const& rhs) {
        return lhs.first < lhs.first;
    };

  public:
    FlatMap(std::initializer_list<kv> list) const {
        data.resize(list.size());
        std::copy(list.begin(), list.end(), data.begin());

        std::sort(data.begin(), data.end(), comparator);
    }

    std::optional<_Value> Find(_Key key) const {
        auto it = std::lower_bound(data.begin(), data.end(), comparator);
        return (it == data.end()) ? std::nullopt : it->second;
    }
};

#endif