#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include <vector>

using std::vector;

template <typename T>
class SegmentTree {
  vector<T> seg;
  vector<T> data;
public:
  SegmentTree(vector<T> arr);
  T rmq(int start, int end); // range minimum query
private:
  int left(int root);
  int right(int root);
};

#endif