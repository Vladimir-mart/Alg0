#include <cmath>
#include <iostream>

using std::abs;
using std::cin;
using std::cout;

bool BinarySearch(const int* begin, const int* end, const int target) {
  // position служит для понимание что сдвинуто левая сторона(она же не
  // включительно)
  int position = 0;
  int distance;
  bool result = false;
  while (abs(begin - end) > 1) {
    distance = abs(begin - end) / 2;
    if (*(begin + distance) < target) {
      begin += distance;
    } else {
      end -= distance;
      position = 1;
    }
  }
  if (*(begin) == target) {
    result = true;
  }
  // в данном случае position играет роль, был ли сдвиг, или нет
  if (*(end) == target && position == 1) {
    result = true;
  }
  return result;
}

int main() {
  int array_length;
  cin >> array_length;
  int* arr = new int[array_length + 1];
  for (int i = 0; i < array_length; i++) {
    cin >> arr[i];
  }
  arr[array_length] = arr[0];
  int number_of_queries;
  cin >> number_of_queries;
  while (number_of_queries != 0) {
    int arr_index_l;
    int arr_index_r;
    int targ;
    cin >> arr_index_l >> arr_index_r >> targ;
    (BinarySearch((arr + arr_index_l), (arr + arr_index_r), targ))
        ? cout << "YES" << '\n'
        : cout << "NO" << '\n';
    number_of_queries--;
  }
  delete[] arr;
}
