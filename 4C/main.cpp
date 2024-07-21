#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

template <typename T>
class TreeF {
 public:
  void Add(int i, int extra, vector<long long>& sum);
  long long GetSum(int i, const vector<long long>& sum);
  void PushArr(int n, vector<long long>& sum);
};

template <typename T>
void TreeF<T>::PushArr(int n, vector<long long>& sum) {
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    Add(i, x, sum);
  }
}

template <typename T>
void TreeF<T>::Add(int i, int extra, vector<long long>& sum) {
  for (; i < (int)sum.size(); i = i | (i + 1)) {
    sum[i] += extra;
  }
}
template <typename T>
long long TreeF<T>::GetSum(int i, const vector<long long>& sum) {
  long long s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    s += sum[i];
  }
  return s;
}

int main() {
  int n;
  cin >> n;
  TreeF<int> fenf;
  vector<long long> sum(n, 0);
  fenf.PushArr(n, sum);
  int n_queries;
  cin >> n_queries;
  for (int q = 0; q < n_queries; ++q) {
    char cmd;
    cin >> cmd;
    if (cmd == 'u') {
      int pos;
      int value;
      cin >> pos >> value;
      pos--;
      int old = fenf.GetSum(pos, sum) - fenf.GetSum(pos - 1, sum);
      fenf.Add(pos, value - old, sum);
    } else {
      int left;
      int right;
      cin >> left >> right;
      left--;
      right--;
      cout << fenf.GetSum(right, sum) - fenf.GetSum(left - 1, sum) << '\n';
    }
  }
  return 0;
}
