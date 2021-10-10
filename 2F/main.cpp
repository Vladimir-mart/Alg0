#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

#include <math.h>

#include <cmath>
#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::stack;
using std::swap;

void QuickSort(int mas[], int size) {
  int i = 0;
  int j = size - 1;
  int mid = mas[size / 2];
  do {
    while (mas[i] < mid) {
      i++;
    }
    while (mas[j] > mid) {
      j--;
    }
    if (i <= j) {
      int tmp = mas[i];
      mas[i] = mas[j];
      mas[j] = tmp;
      i++;
      j--;
    }
  } while (i <= j);
  if (j > 0) {
    QuickSort(mas, j + 1);
  }
  if (i < size) {
    QuickSort(&mas[i], size - i);
  }
}

int Counting(const int time[], const int a[], int n) {
  int step = 0;
  int res = 0;
  int res_m = 0;
  for (int i = 0; i < n; i++) {
    res++;
    if (time[step] <= a[i]) {
      if (step < n) {
        while (time[step] <= a[i]) {
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
  int* a = new int[n];
  int* time = new int[n];
  for (int i = 0, j = 0; i < n; i++, j++) {
    cin >> a[i];
    cin >> time[j];
    time[j] += a[i];
  }
  QuickSort(a, n);
  QuickSort(time, n);
  cout << Counting(time, a, n) << '\n';
  return 0;
}
