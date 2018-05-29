#include "segment_tree.h"
#include <algorithm>
#include <iostream>

using std::min;
using std::cin;
using std::cout;
using std::endl;

template <typename T> 
SegmentTree<T>::SegmentTree(vector<T>data, enum query type) {
  this->data = data;
  this->type = type;
  seg.resize(4 * this->data.size()); // 1-indexed, heap-like
  build(1, 0, data.size() - 1);
}

template <typename T>
void SegmentTree<T>::build(int p, int i, int j) {
  if (i == j) {
    switch (type) {
      case RMQ: seg[p] = i; break;
      case SUM: seg[p] = data[i]; break;
    }
    return;
  }
  if (i > j) {
    return;
  }
  int mid = (i + j) / 2;
  build(left(p), i, mid);
  build(right(p), mid + 1, j);
  switch (type) {
    case RMQ:
      if (data[seg[left(p)]] < data[seg[right(p)]]) {
        seg[p] = seg[left(p)];
      } else {
        seg[p] = seg[right(p)];
      }
      break;
    case SUM:
      seg[p] = seg[left(p)] + seg[right(p)];
      break;
  }
}

template <typename T> 
int SegmentTree<T>::query(int p, int seg_start, int seg_end, int i, int j) {
  if (outside(seg_start, seg_end, i, j)) {
    return -1;
  }
  if (inside(seg_start, seg_end, i, j)) {
    return seg[p];
  }
  int mid = (seg_start + seg_end) / 2;
  int p1 = query(left(p), seg_start, mid, i, j);
  int p2 = query(right(p), mid + 1, seg_end, i, j);
  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  return data[p1] < data[p2] ? p1 : p2;
}

template <typename T>
T SegmentTree<T>::sum(int p, int seg_start, int seg_end, int i, int j) {
  if (outside(seg_start, seg_end, i, j)) {
    return 0;
  }
  if (inside(seg_start, seg_end, i, j)) {
    return seg[p];
  }
  int mid = (seg_start + seg_end) / 2;
  T lsum = sum(left(p), seg_start, mid, i, j);
  T rsum = sum(right(p), mid + 1, seg_end, i, j);
  return lsum + rsum;
}

template <typename T>
void SegmentTree<T>::update_util(int p, int seg_start, int seg_end, int i) {
  if (outside(seg_start, seg_end, i, i) || seg_start >= seg_end) {
    return;
  }
  int mid = (seg_start + seg_end) / 2;
  update_util(left(p), seg_start, mid, i);
  update_util(right(p), mid + 1, seg_end, i);
  switch (type) {
    case RMQ:
      if (data[seg[left(p)]] < data[seg[right(p)]]) {
        seg[p] = seg[left(p)];
      } else {
        seg[p] = seg[right(p)];
      }
      break;
    case SUM:
      seg[p] = seg[left(p)] + seg[right(p)];
      break;
  }
}

template <typename T>
int SegmentTree<T>::rmq(int i, int j) {
  return query(1, 0, data.size()-1, i, j);
}

template <typename T>
T SegmentTree<T>::range_sum(int i, int j) {
  return sum(1, 0, data.size()-1, i, j);
}

template <typename T>
void SegmentTree<T>::update(int idx, T val) {
  data[idx] = val;
  update_util(1, 0, data.size()-1, idx);
}
template class SegmentTree<int>;
template class SegmentTree<double>;