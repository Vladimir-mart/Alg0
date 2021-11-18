#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::vector;

struct Point {
  long long x;
  long long y;
};

long long FenwikF(const long long& m) { return (m & (m + 1)); }

long long SequenceF(const long long& i_m) { return (i_m | (i_m + 1)); }

class TreeB {
  vector<vector<long long>> tree_;

 public:
  TreeB(long long n, long long m);

  void Update(long long new_val, long long idx1, long long idx2);

  long long Query(long long idx1, long long idx2);

  long long Query(long long x_1, long long y_1, long long x_2, long long y_2);
};

void TreeB::Update(long long new_val, long long idx1, long long idx2) {
  long long n = tree_.size();
  long long m = tree_[0].size();
  for (long long i = idx1; i < n; i = SequenceF(i)) {
    for (long long j = idx2; j < m; j = SequenceF(j)) {
      tree_[i][j] += new_val;
    }
  }
}

TreeB::TreeB(long long n, long long m) {
  tree_.resize(n, vector<long long>(m, 0));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      tree_[i][j] = 0;
    }
  }
}

long long TreeB::Query(long long idx1, long long idx2) {
  long long res = 0;
  for (long long i = idx1; i >= 0; i = FenwikF(i) - 1) {
    for (long long j = idx2; j >= 0; j = FenwikF(j) - 1) {
      res += tree_[i][j];
    }
  }
  return res;
}

long long TreeB::Query(long long x_1, long long y_1, long long x_2,
                       long long y_2) {
  return Query(x_2, y_2) - Query(x_2, y_1 - 1) - Query(x_1 - 1, y_2) +
         Query(x_1 - 1, y_1 - 1);
}

Point DefiningPoint(long long x, long long y) {
  Point t;
  t.x = min(x - 1, y - 1);
  t.y = max(x - 1, y - 1);
  return t;
}

int main() {
  int n;
  int m;
  cin >> n >> m;
  Point p1;
  Point p2;
  int requests;
  cin >> requests;
  TreeB tree(n, m);
  long long x_2;
  long long y_2;
  int operation;
  long long x_1;
  long long y_1;
  long long value;
  for (int i = 0; i < requests; ++i) {
    cin >> operation;
    if (operation == 1) {
      cin >> x_1 >> y_1 >> value;
      tree.Update(value, x_1 - 1, y_1 - 1);
    } else {
      cin >> x_1 >> y_1 >> x_2 >> y_2;
      p1 = DefiningPoint(x_1, x_2);
      p2 = DefiningPoint(y_1, y_2);
      cout << tree.Query(p1.x, p2.x, p1.y, p2.y) << '\n';
    }
  }
  return 0;
}
