#include <math.h>

#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using std::cin;
using std::cout;
using std::stack;
using std::swap;
using std::vector;
void Split(vector<int>& arr1, vector<int>& arr2, int nres,
           vector<int>& arr_res) {
  unsigned int iter = 0;
  unsigned int iter2 = 0;
  for (int i = 0; i < nres; i++) {
    if ((arr2[iter2] < arr1[iter]) && (iter2 < arr2.size())) {
      arr_res.push_back(arr2[iter2]);
      cout << arr2[iter2] << " ";
      iter2++;
    } else {
      if (iter < arr1.size()) {
        arr_res.push_back(arr1[iter]);
        cout << arr1[iter] << " ";
        iter++;
      } else {
        arr_res.push_back(arr2[iter2]);
        cout << arr2[iter2] << " ";
        iter2++;
      }
    }
  }
}
int main() {
  int n1;
  vector<int> arr1;
  cin >> n1;
  int temp_arr;
  for (int i = 0; i < n1; i++) {
    cin >> temp_arr;
    arr1.push_back(temp_arr);
  }
  int n2;
  cin >> n2;
  int nres = n1 + n2;
  vector<int> arr_res;
  vector<int> arr2;
  for (int i = 0; i < n2; i++) {
    cin >> temp_arr;
    arr2.push_back(temp_arr);
  }
  Split(arr1, arr2, nres, arr_res);
  cout << '\n';
}