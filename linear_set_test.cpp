#include "gtest/gtest.h"
#include "util/linear_set.h"

namespace util {
namespace {

TEST(LinearSetTest, insert) {
  LinearSet<int> ints;

  ASSERT_EQ(ints.size(), 0);
  ASSERT_TRUE(ints.insert(5).second);
  ASSERT_EQ(ints.size(), 1);
  ASSERT_FALSE(ints.insert(5).second);
  ASSERT_EQ(ints.size(), 1);
  ASSERT_TRUE(ints.insert(3).second);
  ASSERT_EQ(ints.size(), 2);

  auto itr = ints.begin();
  ASSERT_EQ(*itr, 5);
  ++itr;
  ASSERT_EQ(*itr, 3);
  ++itr;
  ASSERT_EQ(itr, ints.end());
}

TEST(LinearSetTest, clear) {
  LinearSet<int> ints;

  ints.insert(5);
  ints.insert(3);
  ints.clear();
  ASSERT_EQ(ints.size(), 0);

  auto itr = ints.begin();
  ASSERT_EQ(itr, ints.end());
}

TEST(LinearSetTest, erase) {
  LinearSet<int> ints;

  ints.insert(5);
  ints.insert(3);
  ASSERT_TRUE(ints.erase(5));
  ASSERT_EQ(ints.size(), 1);

  auto itr = ints.begin();
  ASSERT_EQ(*itr, 3);
  ++itr;
  ASSERT_EQ(itr, ints.end());

  ASSERT_FALSE(ints.erase(5));
  ASSERT_EQ(ints.size(), 1);

  ASSERT_TRUE(ints.erase(3));
  ASSERT_EQ(ints.size(), 0);
}

TEST(LinearSetTest, find) {
  LinearSet<int> ints;

  ASSERT_EQ(ints.find(5), ints.end());
  ints.insert(5);
  ASSERT_NE(ints.find(5), ints.end());
  ASSERT_EQ(*ints.find(5), 5);

  ints.insert(3);
  ASSERT_NE(ints.find(5), ints.end());
  ASSERT_EQ(*ints.find(5), 5);
  ASSERT_NE(ints.find(3), ints.end());
  ASSERT_EQ(*ints.find(3), 3);
}

} // namespace
} // namespace util
