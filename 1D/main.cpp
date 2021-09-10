#include <math.h>
#include <iostream>

using namespace std;

bool BinarySearch(int* begin, int* end, int target)
{
  // служит для понимание что сдвинуто левая сторона(она же не включительно)
  int position = 0;
  int distance;
  while(1 == 1)
  {
    distance = abs(begin - end) / 2;
    if( * (begin + distance) < target)
    {
      begin += distance;
    }
    else
    {
      end -= distance;
      position = 1;
    }
    if(abs(begin - end) <= 1)
    {
      if( * (begin) == target)
      {
        return 1;
      }
      // в данном случае position играет роль, был ли сдвиг, или нет
      if( * (end) == target && position == 1)
      {
        return 1;
      }
      return 0;
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
  int Q;
  cin >> Q;
  while(Q != 0) {
    int array_indexes_l;
    int array_indexes_r;
    int targ;
    cin >> array_indexes_l >> array_indexes_r >> targ;
    if(BinarySearch((arr + array_indexes_l), 
      (arr + array_indexes_r), targ) == 0) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << '\n';
    Q--;
  }
  delete [] arr;
}
