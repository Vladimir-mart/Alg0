#include <iostream>

using std::cin;
using std::cout;

long long GCD(long long n1, long long n2) {
  long long diva;
  long long d = n1 - n2;
  if (n1 == n2) {
    return n1;
  }
  if (d < 0) {
    d = -d;
    diva = GCD(n1, d);
  } else {
    diva = GCD(n2, d);
  }
  return diva;
}

long long LCM(long long n1, long long n2) { return ((n1 * n2) / GCD(n1, n2)); }

int main() {
  long long n1;
  long long n2;
  cin >> n1 >> n2;
  cout << LCM(n1, n2);
  return 0;
}
