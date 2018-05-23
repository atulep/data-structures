#include "segment_tree.h"

template <typename T> 
SegmentTree<T>::SegmentTree(vector<T>data) {
  this->data = data;
  this->seg.resize(this->data.size() + 1); // 1-indexed, heap-like
}

template <typename T>
T SegmentTree<T>::rmq(int i, int j) {
  return 0;
}

template class SegmentTree<int>;
