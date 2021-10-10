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
void Split(vector<int>& arr1, vector<int>& arr2, vector<int>& arr_res) {
  int n1 = arr1.size();
  int n2 = arr2.size();
  for (int i = 0, iter = 0, iter2 = 0; i < (n1 + n2); i++) {
    if ((iter2 < n2)) {
      if ((arr2[iter2] < arr1[iter])) {
        arr_res.push_back(arr2[iter2]);
        iter2++;
      } else {
        if (iter < n1) {
          arr_res.push_back(arr1[iter]);
          iter++;
        } else {
          arr_res.push_back(arr2[iter2]);
          iter2++;
        }
      }
    } else {
      if (iter < n1) {
        arr_res.push_back(arr1[iter]);
        ;
        iter++;
      } else {
        arr_res.push_back(arr2[iter2]);
        iter2++;
      }
    }
  }
}
int main() {
  int n1 = 0;
  vector<int> arr1;
  cin >> n1;
  int temp_arr = 0;
  for (int i = 0; i < n1; i++) {
    cin >> temp_arr;
    arr1.push_back(temp_arr);
  }
  int n2 = 0;
  cin >> n2;
  vector<int> arr2;
  vector<int> arr_res;
  for (int i = 0; i < n2; i++) {
    cin >> temp_arr;
    arr2.push_back(temp_arr);
  }
  Split(arr1, arr2, arr_res);
  for (unsigned int i = 0; i < arr_res.size(); ++i) {
    cout << arr_res[i] << " ";
  }
  arr1.clear();
  arr2.clear();
  cout << '\n';
}