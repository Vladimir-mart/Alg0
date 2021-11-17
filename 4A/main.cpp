#include <algorithm>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::min;

const int kMax_size_n = 100001;
const int kSp_tab = 17;
// (2 ^ 17) > 100001
int** mas = new int*[kMax_size_n];
int* a = new int[kMax_size_n];

void CreatingTable(int n) {
  for (int i = 0; i < kMax_size_n; i++) {
    mas[i] = new int[kSp_tab];
  }
  int i;
  int j;
  for (i = 1; i <= n; i++) {
    mas[i][0] = i;
  }
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 1; i + (1 << (j - 1)) <= n; i++) {
      if (a[mas[i][j - 1]] < a[mas[i + (1 << (j - 1))][j - 1]]) {
        mas[i][j] = mas[i][j - 1];
      } else {
        mas[i][j] = mas[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

const float help_for_log = 2.0;

int Requests(int i, int j) {
  int k = (int)(log(1. * j - i + 1) / log(help_for_log));
  int res = mas[i][k];
  if (a[mas[j - (1 << k) + 1][k]] < a[res]) {
    res = mas[j - (1 << k) + 1][k];
  }
  return res;
}

const unsigned int kVariable1 = 23;
const unsigned int kVariable2 = 21563;
const unsigned int kVariable3 = 16714589;
const unsigned int kVariable4 = 17;
const unsigned int kVariable5 = 751;
const unsigned int kVariable6 = 13;
const unsigned int kVariable7 = 593;
const unsigned int kVariable8 = 5;

int main() {
  int n;
  int m;
  int u;
  int v;
  int u1;
  int v1;
  int ans;
  cin >> n >> m;
  cin >> a[1] >> u >> v;
  for (int i = 2; i <= n; i++) {
    a[i] = (kVariable1 * a[i - 1] + kVariable2) % kVariable3;
  }
  CreatingTable(n);
  for (int i = 1; i <= m; i++) {
    u1 = min(u, v);
    v1 = max(u, v);
    ans = a[Requests(u1, v1)];
    if (i < m) {
      u = ((kVariable4 * u + kVariable5 + ans + 2 * i) % n) + 1;
      v = ((kVariable6 * v + kVariable7 + ans + kVariable8 * i) % n) + 1;
    }
  }
  cout << u << " " << v << " " << ans << '\n';
  delete[] a;
  for (int i = 0; i < kMax_size_n; i++) {
    delete[] mas[i];
  }
  delete[] mas;
  return 0;
}
