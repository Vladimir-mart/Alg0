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
int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  QuickSort(a, n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  delete[] a;
  return 0;
}