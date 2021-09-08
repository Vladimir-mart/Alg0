#include <iostream>
using std::cin;
using std::cout;
long long NOD(long long n1, long long n2) {
  long long diva;
  long long d = n1 - n2;
  if (n1 == n2) {
    return n1;
  }
  if (d < 0) {
    d = - d;
    diva = NOD(n1, d);
  } else {
    diva = NOD(n2, d);
  }
  return diva;
}
long long NOK(long long  n1, long long n2) {
  return ((n1 * n2) / NOD(n1, n2));
}
int main() {
  long long n1, n2;
  cin >> n1 >> n2;
  cout << NOK(n1, n2);
  return 0;
}
