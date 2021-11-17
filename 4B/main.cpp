#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::min;

template <typename T>
class TreeSegment {
 public:
  void Decision();

 private:
  struct Node {
    Node* left;
    Node* right;
    long long lb;
    long long rb;
    long long sum;
    long long add;
  };
  Node* Build(int l, int r);
  void Change(Node* v, int ind, int d);
  void Push(Node* v);
  void Print(Node* v, int ind);
  void ChangeOtr(Node* v, int l, int r, int d);
  long long temp_ = 0;
  Node* Empty_ = new Node({nullptr, nullptr, 0, 0, 0, 0});
};

template <typename T>
void TreeSegment<T>::Decision() {
  int n;
  cin >> n;
  long long* arr = new long long[n + 1];
  Node* tree_otr = nullptr;
  tree_otr = Build(0, n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    Change(tree_otr, i, arr[i]);
  }
  int m;
  char c;
  int l;
  int r;
  int d;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> c;
    if (c == 'g') {
      cin >> d;
      Print(tree_otr, d - 1);
      arr[d - 1] = temp_;
      cout << arr[d - 1] << '\n';
    } else {
      cin >> l >> r >> d;
      ChangeOtr(tree_otr, l - 1, r, d);
    }
  }
  delete[] arr;
}

template <typename T>
typename TreeSegment<T>::Node* TreeSegment<T>::Build(int l, int r) {
  if (l + 1 == r) {
    return new Node({Empty_, Empty_, l, r, 0, 0});
  }
  int mid = (l + r) / 2;
  Node* nleft = Build(l, mid);
  Node* nright = Build(mid, r);
  return new Node({nleft, nright, l, r, 0, 0});
}

template <typename T>
void TreeSegment<T>::Change(Node* v, int ind, int d) {
  if (v->rb <= ind || v->lb > ind) {
    return;
  }
  if (v->lb + 1 == v->rb) {
    v->sum += d;
    return;
  }
  Change(v->left, ind, d);
  Change(v->right, ind, d);
  v->sum = v->left->sum + v->right->sum;
}

template <typename T>
void TreeSegment<T>::Push(Node* v) {
  if (v == Empty_) {
    return;
  }
  v->sum += v->add * (v->rb - v->lb);
  v->left->add += v->add;
  v->right->add += v->add;
  v->add = 0;
}

template <typename T>
void TreeSegment<T>::Print(Node* v, int ind) {
  Push(v);
  if (v->rb <= ind || v->lb > ind) {
    return;
  }
  if (v->lb + 1 == v->rb) {
    temp_ = v->sum + v->add;
    return;
  }
  Print(v->left, ind);
  Print(v->right, ind);
  v->sum = v->left->sum + v->right->sum;
}

template <typename T>
void TreeSegment<T>::ChangeOtr(Node* v, int l, int r, int d) {
  Push(v);
  if (v->lb >= r || v->rb <= l) {
    return;
  }
  if (l <= v->lb && r >= v->rb) {
    v->add += d;
    Push(v);
    return;
  }
  ChangeOtr(v->left, l, r, d);
  ChangeOtr(v->right, l, r, d);
  if (v == Empty_) {
    return;
  }
  v->sum = v->left->sum + v->right->sum;
}

int main() {
  TreeSegment<int> cho;
  cho.Decision();
}
