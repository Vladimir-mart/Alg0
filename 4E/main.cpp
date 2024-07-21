#include <iostream>
#include <vector>
// Frankenstein
using std::cin;
using std::cout;
using std::max;
using std::min;
using std::vector;

struct Point2d {
  long long x;
  long long y;
};

struct Point {
  long long x;
  long long y;
  long long z;
};

long long FenwikF(const long long& m) { return (m & (m + 1)); }

long long SequenceF(const long long& i_m) { return (i_m | (i_m + 1)); }

class TreeB {
  vector<vector<vector<long long>>> tree_;

 public:
  TreeB(long long n);

  void Update(long long new_val, long long idx1, long long idx2,
              long long idx3);

  long long Query(long long idx1, long long idx2, long long idx3);

  long long Query(Point2d& p1, Point2d& p2, Point2d& p3);
};

void TreeB::Update(long long new_val, long long idx1, long long idx2,
                   long long idx3) {
  long long n = tree_.size();
  long long m = tree_[0].size();
  long long l = tree_[0][0].size();
  for (long long i = idx1; i < n; i = SequenceF(i)) {
    for (long long j = idx2; j < m; j = SequenceF(j)) {
      for (long long k = idx3; k < l; k = SequenceF(k)) {
        tree_[i][j][k] += new_val;
      }
    }
  }
}

TreeB::TreeB(long long n) {
  tree_.resize(n + 1);
  for (long long i = 0; i <= n; ++i) {
    tree_[i].resize(n + 1);
    for (long long j = 0; j <= n; ++j) {
      tree_[i][j].resize(n + 1);
      for (long long k = 0; k <= n; ++k) {
        tree_[i][j][k] = 0;
      }
    }
  }
}

long long TreeB::Query(long long idx1, long long idx2, long long idx3) {
  long long res = 0;
  for (long long i = idx1; i >= 0; i = FenwikF(i) - 1) {
    for (long long j = idx2; j >= 0; j = FenwikF(j) - 1) {
      for (long long k = idx3; k >= 0; k = FenwikF(k) - 1) {
        res += tree_[i][j][k];
      }
    }
  }
  return res;
}

long long TreeB::Query(Point2d& p1, Point2d& p2, Point2d& p3) {
  long long x_1 = p1.x;
  long long y_1 = p2.x;
  long long z_1 = p3.x;
  long long x_2 = p1.y;
  long long y_2 = p2.y;
  long long z_2 = p3.y;
  return Query(x_2, y_2, z_2) - Query(x_1 - 1, y_2, z_2) -
         Query(x_2, y_1 - 1, z_2) - Query(x_2, y_2, z_1 - 1) +
         Query(x_1 - 1, y_1 - 1, z_2) + Query(x_1 - 1, y_2 + 0, z_1 - 1) +
         Query(x_2 + 0, y_1 - 1, z_1 - 1) - Query(x_1 - 1, y_1 - 1, z_1 - 1);
}

Point2d DefiningPoint(long long x, long long y) {
  Point2d t = {0, 0};
  t.x = min(x + 1, y + 1);
  t.y = max(x + 1, y + 1);
  return t;
}

const unsigned int kStop = 3;

int main() {
  int n;
  cin >> n;
  Point2d p1 = {0, 0};
  Point2d p2 = {0, 0};
  Point2d p3 = {0, 0};
  TreeB tree(n);
  Point p3_d_1 = {0, 0, 0};
  Point p3_d_2 = {0, 0, 0};
  int operation;
  long long value;
  while (true) {
    cin >> operation;
    if (operation == kStop) {
      break;
    }
    if (operation == 1) {
      cin >> p3_d_1.x >> p3_d_1.y >> p3_d_1.z >> value;
      tree.Update(value, p3_d_1.x + 1, p3_d_1.y + 1, p3_d_1.z + 1);
    }
    if (operation == 2) {
      cin >> p3_d_1.x >> p3_d_1.y >> p3_d_1.z >> p3_d_2.x >> p3_d_2.y >>
          p3_d_2.z;
      p1 = DefiningPoint(p3_d_1.x, p3_d_2.x);
      p2 = DefiningPoint(p3_d_1.y, p3_d_2.y);
      p3 = DefiningPoint(p3_d_1.z, p3_d_2.z);
      cout << tree.Query(p1, p2, p3) << '\n';
    }
  }
  return 0;
}
