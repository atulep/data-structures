#include "gtest/gtest.h"
#include "segment_tree.h"
#include <vector>
#include <iostream>

using std::vector;

// O(n)
template <typename T>
int rmq(vector<T> data, int start, int end) {
  assert (data.size() > 0);
  int min = data[start];
  int min_idx = start;
  for (int i = start + 1; i <= end; ++i) {
    if (data[i] < min) {
      min = data[i];
      min_idx = i;
    }
  }
  return min_idx;
}

template <typename T>
T sum(vector<T> data, int start, int end) {
  assert (data.size() > 0);
  T ans = 0;
  for (int i = start; i <= end; ++i) {
    ans += data[i];
  }
  return ans;
}

namespace {
  TEST(RmqTest, EntireArray) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    SegmentTree<int> seg_tree(data);
    int start = 0, end = data.size() - 1; 
    EXPECT_EQ(seg_tree.rmq(start, end), rmq(data, start, end));
  }
  TEST(RmqTest, Middle2Elements) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    SegmentTree<int> seg_tree(data);
    int start = 3, end = 4; 
    EXPECT_EQ(seg_tree.rmq(start, end), rmq(data, start, end));
  }
   TEST(RmqTest, Middle3Elements) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    SegmentTree<int> seg_tree(data);
    int start = 2, end = 4; 
    EXPECT_EQ(seg_tree.rmq(start, end), rmq(data, start, end));
  }
  TEST(RmqTest, AllButFirstElement) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    SegmentTree<int> seg_tree(data);
    int start = 1, end = data.size() - 1; 
    EXPECT_EQ(seg_tree.rmq(start, end), rmq(data, start, end));
  }
  TEST(SumTest, EntireArray) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    SegmentTree<int> seg_tree(data, SUM);
    int start = 0, end = data.size() - 1; 
    EXPECT_EQ(seg_tree.range_sum(start, end), sum(data, start, end));
  }
  TEST(SumTest, Middle3Elements) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    SegmentTree<int> seg_tree(data, SUM);
    int start = 2, end = 4; 
    EXPECT_EQ(seg_tree.range_sum(start, end), sum(data, start, end));
  }
}
