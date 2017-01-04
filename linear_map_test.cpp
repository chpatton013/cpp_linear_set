#include "gtest/gtest.h"
#include "util/linear_map.h"
#include <string>

namespace util {
namespace {

TEST(LinearMapTest, find) {
  LinearMap<int, std::string> strings;

  ASSERT_TRUE(strings.insert({3, "three"}).second);
  ASSERT_TRUE(strings.insert({5, "five"}).second);
  ASSERT_TRUE(strings.insert({4, "four"}).second);

  ASSERT_EQ(strings.find(3)->second, "three");
  ASSERT_EQ(strings.find(4)->second, "four");
  ASSERT_EQ(strings.find(5)->second, "five");

  ASSERT_FALSE(strings.insert({4, "FOUR"}).second);
  ASSERT_EQ(strings.find(4)->second, "FOUR");
}

} // namespace
} // namespace util
