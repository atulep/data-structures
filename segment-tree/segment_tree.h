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
  int rmq(int start, int end); // range minimum query
private:
  int left(int root);
  int right(int root);
  int query(int p, int seg_start, int seg_end, int i, int j);
  void build(int p, int start, int end);
  bool inside(int seg_start, int seg_end, int i, int j);
  bool outside(int seg_start, int seg_end, int i, int j);
};

template <typename T>
inline int SegmentTree<T>::left(int root) {
  return 2 * root;
}

template <typename T>
inline int SegmentTree<T>::right(int root) {
  return 2 * root + 1;
}

template <typename T>
inline bool SegmentTree<T>::inside(int seg_start, int seg_end, int i, int j) {
  return seg_start >= i && seg_end <= j;
}

template <typename T>
inline bool SegmentTree<T>::outside(int seg_start, int seg_end, int i, int j) {
  return seg_start > j || seg_end < i;
}
#endif