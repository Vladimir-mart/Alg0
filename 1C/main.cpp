#include <cmath>
#include <iostream>

using std::cin;
using std::cout;

int checking_divisors(int n) {
  for (int divider = 2; divider <= sqrt(n); divider++) {
    while (n % divider == 0) {
      n /= divider;
      cout << divider << " ";
    }
  }
  return n;
}

int main() {
  int number_of_requests;
  cin >> number_of_requests;
  while (number_of_requests != 0) {
    int n;
    cin >> n;
    n = checking_divisors(n);
    if (n != 1) {
      cout << n << " ";
    }
    number_of_requests--;
  }
}