#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

double MinWay(double x1, double y1, double x2, double y2) {
  // ax^2 + bx + c = 0
  double a = (y2 * y2 - y1 * y1);
  double b = (2 * x1 * y2 * y2 - 2 * x2 * y1 * y1);
  double c = (x1 * x1 * y2 * y2 - x2 * x2 * y1 * y1);
  // Дискриминант
  double d = sqrt(b * b - 2 * 2 * a * c);
  // Проверка на особый случай
  if (x1 == x2 && y1 == y2) {
    return x1;
  }
  if (y2 == y1) {
    return (x2 * x2 * y1 * y1 - x1 * x1 * y2 * y2) /
           (2 * x2 * y1 * y1 - 2 * x1 * y2 * y2);
  }
  // Вычисления
  double the_answer_to_the_quadratic_equation1 = ((b + d) / (2 * a));
  double the_answer_to_the_quadratic_equation2 = ((b - d) / (2 * a));
  double answer;
  if (the_answer_to_the_quadratic_equation2 > x1 &&
      the_answer_to_the_quadratic_equation2 < x2) {
    answer = the_answer_to_the_quadratic_equation2;
  } else {
    answer = the_answer_to_the_quadratic_equation1;
  }
  return answer;
}

int main() {
  const int rounding = 10;
  double x1;
  double x2;
  double y1;
  double y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }
  cout << std::fixed << std::showpoint;
  cout << std::setprecision(rounding);
  cout << MinWay(x1, y1, x2, y2) << '\n';
}