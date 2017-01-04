#pragma once

#include "linear_set.h"
#include <algorithm>
#include <tuple>
#include <vector>

namespace util {

namespace {
template <typename Key, typename Value>
struct MapTypes {
  using Entry = std::pair<Key, Value>;
  struct Compare {
    bool operator()(const Key& lhs, const Value& rhs) {
      return lhs == rhs.first;
    }
  };
};
} // namespace

template <typename Key,
          typename Value,
          typename CompareType = typename MapTypes<Key, Value>::Compare>
using LinearMap =
    LinearSet<Key, typename MapTypes<Key, Value>::Entry, CompareType>;
} // namespace util
