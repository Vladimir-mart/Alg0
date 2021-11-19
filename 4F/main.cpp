#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::min;
using std::string;
using std::vector;

class SegmentTree {
 public:
  SegmentTree(const string& speech);
  int RMQPub(long long left, long long right);

 private:
  struct Node {
    int num_open;
    long long max_len;
    int num_close;

    Node() : num_open(0), max_len(0), num_close(0) {}

    Node(int open, int close, long long length)
        : num_open(open), max_len(length), num_close(close) {}
  };
  Node RMQ(long long left, long long right);
  static Node Merge(const Node& left, const Node& right);

  static long long Parent(long long index) { return (index - 1) / 2; }
  static long long LChild(long long index) { return (index + 1) * 2 - 1; }
  static long long RChild(long long index) { return (index + 1) * 2; }

  vector<Node> tree_;
  long long size_;
};

int SegmentTree::RMQPub(long long left, long long right) {
  return RMQ(left, right).max_len;
}

typename SegmentTree::Node SegmentTree::Merge(const Node& left,
                                              const Node& right) {
  int size = min(left.num_open, right.num_close);
  int open = left.num_open + right.num_open - size;
  int close = left.num_close + right.num_close - size;
  long long length = left.max_len + right.max_len + size * 2;
  return Node{open, close, length};
}

typename SegmentTree::Node SegmentTree::RMQ(long long left, long long right) {
  Node lb;
  Node rb;
  left += size_ - 1;
  right += size_ - 1;
  while (left < right) {
    long long r_brother = RChild(Parent(left));
    long long l_brother = LChild(Parent(right));
    if (left == r_brother) {
      lb = Merge(lb, tree_[left]);
    }
    if (right == l_brother) {
      rb = Merge(tree_[right], rb);
    }
    left = Parent(left + 1);
    right = Parent(right - 1);
  }
  if (left == right) {
    rb = Merge(tree_[left], rb);
  }
  return Merge(lb, rb);
}

SegmentTree::SegmentTree(const string& speech) {
  long long k = log2(speech.size()) + 1;
  int kdegree_2 = (1 << (k));
  size_ = kdegree_2;
  long long size = 2 * size_ - 1;
  tree_.resize(size, Node());
  for (size_t i = 0; i < speech.size(); ++i) {
    if (speech[i] == ')') {
      tree_[size_ + i - 1] = Node(0, 1, 0);
    }
    if (speech[i] == '(') {
      tree_[size_ + i - 1] = Node(1, 0, 0);
    }
  }
  for (long long i = size_ - 2; i >= 0; --i) {
    tree_[i] = Merge(tree_[LChild(i)], tree_[RChild(i)]);
  }
}

int main() {
  string speech;
  cin >> speech;
  SegmentTree segment_tree(speech);
  int requests;
  cin >> requests;
  for (int i = 0; i < requests; ++i) {
    long long left;
    long long right;
    cin >> left >> right;
    cout << segment_tree.RMQPub(left - 1, right - 1) << '\n';
  }
}
