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
      int tmp = mas[i];
      mas[i] = mas[j];
      mas[j] = tmp;
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

int main() {
  int n;
  cin >> n;
  vector<int> a;
  int elem;
  for (int i = 0; i < n; i++) {
    cin >> elem;
    a.push_back(elem);
  }
  QuickSort(a, 0, a.size() - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
