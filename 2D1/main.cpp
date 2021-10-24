#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::stack;
using std::swap;
using std::vector;

template <typename T>
int HFValg(vector<T> arr, unsigned int iter) {
  int jump_control;
  if (iter == arr.size()) {
    jump_control = arr[iter - 1];
  } else {
    jump_control = arr[iter];
  }
  return jump_control;
}

template <typename T>
vector<T> Merge(vector<T> arr1, vector<int> arr2) {
  vector<T> arr_res;
  unsigned int nres = arr1.size() + arr2.size();
  unsigned int iter = 0;
  unsigned int iter2 = 0;
  int help_from_valgrind1;
  int help_from_valgrind2;
  for (unsigned int i = 0; i < nres; i++) {
    help_from_valgrind1 = HFValg(arr1, iter);
    help_from_valgrind2 = HFValg(arr2, iter2);
    if ((help_from_valgrind2 < help_from_valgrind1) && iter2 < arr2.size()) {
      arr_res.push_back(arr2[iter2]);
      iter2++;
    } else {
      if (iter < arr1.size()) {
        arr_res.push_back(arr1[iter]);
        iter++;
      } else {
        arr_res.push_back(arr2[iter2]);
        iter2++;
      }
    }
  }
  return arr_res;
}

int main() {
  int n_over;
  cin >> n_over;
  deque<vector<int>> merge_grid;
  for (int j = 0; j < n_over; j++) {
    int n1;
    cin >> n1;
    vector<int> arr1;
    int temp_arr1;
    for (int i = 0; i < n1; i++) {
      cin >> temp_arr1;
      arr1.push_back(temp_arr1);
    }
    merge_grid.push_front(arr1);
  }
  while (merge_grid.size() != 1) {
    merge_grid.push_back(Merge(merge_grid[0], merge_grid[1]));
    merge_grid.pop_front();
    merge_grid.pop_front();
  }
  for (unsigned int i = 0; i < merge_grid[0].size(); i++) {
    cout << merge_grid[0][i] << " ";
  }
  cout << '\n';
}