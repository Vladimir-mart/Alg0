#include <cmath>
#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;
double Kvadard(double x1, double y1, double x2, double y2) {
  if (x1 == x2 && y1 == y2) {
      return x1;
  }
  if (y2 == y1) {
    return (x2 * x2 * y1 * y1 - x1 * x1 * y2 * y2) / (2 * x2 * y1 * y1 - 2 * x1 * y2 * y2);
  }
  double answer1;
  double answer2;
  double d = sqrt(((2 * x1 * y2 * y2 - 2 * x2 * y1 * y1)) *
                      ((2 * x1 * y2 * y2 - 2 * x2 * y1 * y1)) -
                  2 * 2 * (y2 * y2 - y1 * y1) *
                      (x1 * x1 * y2 * y2 - x2 * x2 * y1 * y1));
  //Квадратное уравнение
  answer1 = ((2 * x1 * y2 * y2 - 2 * x2 * y1 * y1) + d) /
      (2 * ((y2 * y2 - y1 * y1)));
  answer2 = ((2 * x1 * y2 * y2 - 2 * x2 * y1 * y1) - d) /
      (2 * ((y2 * y2 - y1 * y1)));
  double ans;
  if (answer2 > x1 && answer2 < x2) {
    ans = answer2;
  }
  else {
    ans = answer1;
  }
  return ans;
}
int main() {
  const int s = 10;
  double x1;
  double x2;
  double y1;
  double y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) {
    double t1 = x1;
    double t2 = y1;
    x1 = x2;
    y1 = y2;
    x2 = t1;
    y2 = t2;
  }
  std::cout << std::fixed << std::showpoint;
  std::cout << std::setprecision(s);
  cout << Kvadard(x1, y1, x2, y2) << '\n';
  return 0;
}