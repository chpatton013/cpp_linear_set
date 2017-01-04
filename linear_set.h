#pragma once

#include <algorithm>
#include <vector>

namespace util {

namespace {
template <typename Value>
struct Compare {
  bool operator()(const Value& lhs, const Value& rhs) {
    return lhs == rhs;
  }
};
} // namespace

template <typename Key,
          typename Value = Key,
          typename CompareType = Compare<Value>>
class LinearSet {
public:
  using ValueList = std::vector<Value>;
  using Iterator = decltype(ValueList().begin());
  using ConstIterator = decltype(ValueList().cbegin());

  LinearSet() = default;
  LinearSet(const LinearSet&) = default;
  LinearSet(LinearSet&&) = default;
  ~LinearSet() = default;
  LinearSet& operator=(const LinearSet&) = default;
  LinearSet& operator=(LinearSet&&) = default;

  std::size_t size() const {
    return values_.size();
  }
  void clear() {
    values_.clear();
  }

  std::pair<Iterator, bool> insert(const Value& value) {
    auto itr = find(value);
    if (itr != values_.end()) {
      *itr = value;
      return {itr, false};
    }

    values_.push_back(value);
    return {find(value), true};
  }

  bool erase(const Key& key) {
    auto itr = find(key);
    if (itr == values_.end()) {
      return false;
    }

    values_.erase(itr);
    return true;
  }

  Iterator find(const Key& key) {
    return std::find_if(
        values_.begin(), values_.end(), [key](const Value& value) {
          return CompareType()(key, value);
        });
  }

  ConstIterator find(const Key& key) const {
    return std::find_if(
        values_.begin(), values_.end(), [key](const Value& value) {
          return CompareType()(key, value);
        });
  }

  Iterator begin() {
    return values_.begin();
  }

  Iterator end() {
    return values_.end();
  }

  ConstIterator cbegin() {
    return values_.cbegin();
  }

  ConstIterator cend() {
    return values_.cend();
  }

private:
  ValueList values_;
};
} // namespace util
