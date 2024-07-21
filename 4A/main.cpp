#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::min;

const unsigned int kVariable1 = 23;
const unsigned int kVariable2 = 21563;
const unsigned int kVariable3 = 16714589;
const unsigned int kVariable4 = 17;
const unsigned int kVariable5 = 751;
const unsigned int kVariable6 = 13;
const unsigned int kVariable7 = 593;
const unsigned int kVariable8 = 5;

template <typename T>
class SparceTable {
 public:
  SparceTable();
  ~SparceTable();
  void CreatingTable(T n);
  void PushArr(T n);
  int GetArr(unsigned int ind) { return a_[ind]; }
  int Requests(unsigned int i, unsigned int j);

 private:
  int** mas_ = nullptr;
  T* a_ = nullptr;
  const int kMaxsizen = 100001;
  const int kSptab = 17;
  // (2 ^ 17) > 100001
  const float kHelpforlog = 2.0;
};

template <typename T>
SparceTable<T>::SparceTable() {
  mas_ = new int*[kMaxsizen];
  a_ = new T[kMaxsizen];
}

template <typename T>
SparceTable<T>::~SparceTable() {
  delete[] a_;
  for (int i = 0; i < kMaxsizen; i++) {
    delete[] mas_[i];
  }
  delete[] mas_;
}

template <typename T>
void SparceTable<T>::PushArr(T n) {
  cin >> a_[1];
  for (int i = 2; i <= n; i++) {
    a_[i] = (kVariable1 * a_[i - 1] + kVariable2) % kVariable3;
  }
}

template <typename T>
void SparceTable<T>::CreatingTable(T n) {
  for (int i = 0; i < kMaxsizen; i++) {
    mas_[i] = new int[kSptab];
  }
  int i;
  int j;
  for (i = 1; i <= n; i++) {
    mas_[i][0] = i;
  }
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 1; i + (1 << (j - 1)) <= n; i++) {
      if (a_[mas_[i][j - 1]] < a_[mas_[i + (1 << (j - 1))][j - 1]]) {
        mas_[i][j] = mas_[i][j - 1];
      } else {
        mas_[i][j] = mas_[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

template <typename T>
int SparceTable<T>::Requests(unsigned int i, unsigned int j) {
  int k = (int)(log(1. * j - i + 1) / log(kHelpforlog));
  int res = mas_[i][k];
  if (a_[mas_[j - (1 << k) + 1][k]] < a_[res]) {
    res = mas_[j - (1 << k) + 1][k];
  }
  return res;
}

int main() {
  int n;
  int m;
  unsigned int u;
  unsigned int v;
  unsigned int u1;
  unsigned int v1;
  int ans;
  SparceTable<int> tab;
  cin >> n >> m;
  tab.PushArr(n);
  cin >> u >> v;
  tab.CreatingTable(n);
  for (int i = 1; i <= m; i++) {
    u1 = min(u, v);
    v1 = max(u, v);
    ans = tab.GetArr(tab.Requests(u1, v1));
    if (i < m) {
      u = ((kVariable4 * u + kVariable5 + ans + 2 * i) % n) + 1;
      v = ((kVariable6 * v + kVariable7 + ans + kVariable8 * i) % n) + 1;
    }
  }
  cout << u << " " << v << " " << ans << '\n';
  return 0;
}
