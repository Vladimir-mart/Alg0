#include <math.h>
#include <iostream>

using namespace std;

// position служит для понимание что сдвинуто левая сторона(она же не включительно)

bool BinarySearch(int* begin, int* end, int target) {
  int position = 0;
  int distance;
  bool yes_or_no = false;
  while(1 == 1) {
    distance = abs(begin - end) / 2;
    if( * (begin + distance) < target) {
      begin += distance;
    } else {
      end -= distance;
      position = 1;
    }
    if(abs(begin - end) <= 1) {
      if( * (begin) == target) {
        yes_or_no = true;
      }
      // в данном случае position играет роль, был ли сдвиг, или нет
      if( * (end) == target && position == 1) {
        yes_or_no = true;
      }
      return yes_or_no;
    }
  }
}

int main() {
  int array_length;
  bool yes_or_no;
  cin >> array_length;
  int *arr = new int[array_length];
  for(int i = 0; i < array_length; i++) {
    cin >> arr[i];
  }
  int q;
  cin >> q;
  while(q != 0) {
    int arr_index_l;
    int arr_index_r;
    int targ;
    cin >> arr_index_l >> arr_index_r >> targ;
    yes_or_no = BinarySearch((arr + arr_index_l), (arr + arr_index_r), targ);
    if(yes_or_no) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
    q--;
  }
  delete [] arr;
}
