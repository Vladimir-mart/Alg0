#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;
void Exponentiation(long double* special_ar) {
  long long q;
  cin >> q;
  long double e = exp(1.0);
  long long arr_index_l;
  long long arr_index_r;
  cout << fixed << showpoint;
  cout << setprecision(2 + 2 + 2 + 1);
  for (long long i = 0; i < q; i++) {
    cin >> arr_index_l >> arr_index_r;
    if (arr_index_l == 0) {
      cout << pow(exp(1.0),
                  special_ar[arr_index_r] / (arr_index_r - arr_index_l + 1))
           << '\n';
    } else {
      cout << pow(exp(1.0),
                  (special_ar[arr_index_r] - special_ar[arr_index_l - 1]) /
                      (arr_index_r - arr_index_l + 1))
           << '\n';
    }
  }
}
int main() {
  long long arr_length;
  cin >> arr_length;
  long double* arr = new long double[arr_length];
  long double* special_arr = new long double[arr_length];
  for (long long i = 0; i < arr_length; i++) {
    cin >> arr[i];
    if (i == 0) {
      special_arr[0] = log(arr[0]);
    } else {
      special_arr[i] = special_arr[i - 1] + log(arr[i]);
    }
  }
  Exponentiation(special_arr);
  delete[] arr;
  delete[] special_arr;
}
