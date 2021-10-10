#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
size_t Partition(std::vector<int>& vec, size_t left, size_t right) {
  int mid = vec[(left + right) / 2];
  size_t i = left;
  size_t j = right;
  while (i <= j) {
    while (vec[i] < mid) {
      i++;
    }
    while (vec[j] > mid) {
      j--;
    }
    if (i >= j) {
      break;
    }
    std::swap(vec[i++], vec[j--]);
  }

  return j;
}
int FindOrderStatistic(vector<int>& array, int k) {
  int left = 0;
  int right = array.size() - 1;
  int mid;
  int pol = 0;
  while (true) {
    mid = Partition(array, left, right);
    if (mid == k) {
      pol = 1;
    } else if (k < mid) {
      right = mid;
    } else {
      left = mid + 1;
    }
    if (pol == 1) {
      return array[mid];
    }
  }
}
const int an = 4321;
const int bn = 123;
const int cn = 45;
const int dn = 10;
const int en = 7;
int main() {
  int n;
  cin >> n;
  vector<int> arr;
  int c;
  int k;
  cin >> k;
  for (int i = 0; i < 2; i++) {
    cin >> c;
    arr.push_back(c);
  }
  for (int i = 2; i < n; i++) {
    c = (int)(arr[i - 1] * bn + arr[i - 2] * cn) % (int)(pow(dn, en) + an);
    arr.push_back(c);
  }
  if (k == 2) {
    cout << arr[1];
    return 0;
  }
  if (k == 1) {
    cout << arr[0];
    return 0;
  }
  cout << FindOrderStatistic(arr, k - 1);
  return 0;
}