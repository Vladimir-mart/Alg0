#include <math.h>
#include <iostream>
using std::cin;
using std::cout;
int main() {
  int iterator;
  cin >> iterator;
  while (iterator != 0) {
    int n;
    cin >> n;
    for (int divider = 2; divider <= sqrt(n); divider++) {
      while (n % divider == 0) {
        n /= divider;
        cout << divider << " ";
      }
    }
    if (n != 1) {
      cout << n << " ";
    }
    iterator--;
  }
  return 0;
}