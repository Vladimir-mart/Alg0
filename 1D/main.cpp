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
  cin >> array_length;
  int *arr = new int[array_length];
  for(int i = 0; i < array_length; i++) {
    cin >> arr[i];
  }
  int q;
  cin >> q;
  while(q != 0) {
    int array_indexes_l;
    int array_indexes_r;
    int targ;
    cin >> array_indexes_l >> array_indexes_r >> targ;
    if(BinarySearch((arr + array_indexes_l), 
      (arr + array_indexes_r), targ) == false) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << '\n';
    q--;
  }
  delete [] arr;
}
