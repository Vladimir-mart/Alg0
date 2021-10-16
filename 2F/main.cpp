#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::stack;
using std::swap;
using std::vector;

template <typename T>
void QuickSort(vector<T>& mas, int left, int right) {
  int i = left;
  int j = right;
  int mid = mas[(i + j) / 2];
  do {
    while (mas[i] < mid) {
      i++;
    }
    while (mas[j] > mid) {
      j--;
    }
    if (i <= j) {
      swap(mas[i], mas[j]);
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j) {
    QuickSort(mas, left, j);
  }
  if (i < right) {
    QuickSort(mas, i, right);
  }
}

template <typename T>
int Counting(vector<T>& time_end, const vector<T>& time_begin, int n) {
  int step = 0;
  int res = 0;
  int res_m = 0;
  for (int i = 0; i < n; i++) {
    res++;
    if (time_end[step] <= time_begin[i]) {
      if (step < n) {
        while (time_end[step] <= time_begin[i]) {
          res--;
          step++;
        }
      }
    }
    if (res > res_m) {
      res_m = res;
    }
  }
  return res_m;
}

int main() {
  int n;
  cin >> n;
  vector<int> time_begin;
  vector<int> time_end;
  int temp_b;
  int temp_e;
  for (int i = 0, j = 0; i < n; i++, j++) {
    cin >> temp_b >> temp_e;
    time_begin.push_back(temp_b);
    time_end.push_back(time_begin[i] + temp_e);
  }
  QuickSort(time_begin, 0, n - 1);
  QuickSort(time_end, 0, n - 1);
  cout << Counting(time_end, time_begin, n) << '\n';
  return 0;
}
