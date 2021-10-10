#include <math.h>

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
int HFValg(vector<int> arr, unsigned int iter) {
  int ret;
  if (iter == arr.size()) {
    ret = arr[iter - 1];
  } else {
    ret = arr[iter];
  }
  return ret;
}
vector<int> Split(vector<int> arr1, vector<int> arr2) {
  vector<int> arr_res;
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
  deque<vector<int>> dque_vec;
  for (int j = 0; j < n_over; j++) {
    int n1;
    cin >> n1;
    vector<int> arr1;
    int temp_arr1;
    for (int i = 0; i < n1; i++) {
      cin >> temp_arr1;
      arr1.push_back(temp_arr1);
    }
    dque_vec.push_front(arr1);
  }
  while (dque_vec.size() != 1) {
    dque_vec.push_back(Split(dque_vec[0], dque_vec[1]));
    dque_vec.pop_front();
    dque_vec.pop_front();
  }
  for (unsigned int i = 0; i < dque_vec[0].size(); i++) {
    cout << dque_vec[0][i] << " ";
  }
  cout << '\n';
}