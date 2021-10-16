#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::swap;
using std::vector;

template <typename T>
void QuickSort(vector<T>& mas, unsigned int left, unsigned int right) {
  unsigned int i = left;
  unsigned int j = right;
  unsigned int mid = mas[(i + j) / 2].y;
  do {
    while (mas[i].y < mid) {
      i++;
    }
    while (mas[j].y > mid) {
      j--;
    }
    if (i <= j) {
      swap(mas[i], mas[j]);
      i++;
      if (j > 0) {
        j--;
      }
    }
  } while (i <= j);
  if (left < j) {
    QuickSort(mas, left, j);
  }
  if (i < right) {
    QuickSort(mas, i, right);
  }
}

template <typename T>
class BinaryHeap {
 public:
  BinaryHeap(/* args */);
  void Extractmin();       //+
  int GetMin();            //+
  void Insert(int value);  //+
  bool IsEmpty() const;    //+
  size_t Size() const;     //+
  void Clear();            //+
  void Show();
  ~BinaryHeap();
  vector<T> a;

 private:
  void SiftDown(unsigned int index);    //+
  void SiftUp(unsigned int index);      //+
  static int GetLeftChild(int index);   //+
  static int GetRightChild(int index);  //+
  static int GetPerent(int index);      //+
};

template <typename T>
void BinaryHeap<T>::Show() {
  cout << " Show ";
  for (unsigned int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}

template <typename T>
void BinaryHeap<T>::Clear() {
  a.clear();
}

template <typename T>
int BinaryHeap<T>::GetMin() {
  return a[0];
}

template <typename T>
size_t BinaryHeap<T>::Size() const {
  return a.size();
}

template <typename T>
bool BinaryHeap<T>::IsEmpty() const {
  return !a.empty();
}

template <typename T>
void BinaryHeap<T>::Insert(int value) {
  if (a.size() == 1) {
    if (a[0] == 0) {
      a[0] = value;
      return;
    }
  }
  a.push_back(value);
  SiftUp(a.size() - 1);
}

template <typename T>
int BinaryHeap<T>::GetPerent(int index) {
  return (index - 1) / 2;
}

template <typename T>
int BinaryHeap<T>::GetLeftChild(int index) {
  return 2 * index + 1;
}

template <typename T>
int BinaryHeap<T>::GetRightChild(int index) {
  return 2 * index + 2;
}

template <typename T>
void BinaryHeap<T>::Extractmin() {
  swap(a[0], a[a.size() - 1]);
  a.pop_back();

  SiftDown(0);
}

template <typename T>
void BinaryHeap<T>::SiftUp(unsigned int index) {
  int perent = GetPerent(index);
  while (perent >= 0 && a[perent] > a[index]) {
    swap(a[perent], a[index]);
    index = perent;
    perent = GetPerent(index);
  }
}

template <typename T>
void BinaryHeap<T>::SiftDown(unsigned int i) {
  while ((2 * i + 1) < a.size()) {  // heapSize — количество элементов в куче
    int left = GetLeftChild(i);    // left — левый сын
    int right = GetRightChild(i);  // right — правый сын
    int j = left;
    if (right < (int)a.size() && a[right] < a[left]) {
      j = right;
    }
    if (a[i] <= a[j]) {
      break;
    }
    swap(a[i], a[j]);
    i = j;
  }
}

template <typename T>
BinaryHeap<T>::BinaryHeap(/* args */) {}

template <typename T>
BinaryHeap<T>::~BinaryHeap() {}

struct Point {
  unsigned int x;
  unsigned int y;
};

template <typename T>
long long Maximum(vector<T>& coord, unsigned int size, unsigned int k) {
  BinaryHeap<int> heap;
  long long ans = 0;
  QuickSort(coord, 0, size - 1);
  while (size != 0) {
    heap.Insert(coord[size - 1].x);
    if (heap.Size() > k) {
      heap.Extractmin();
    }
    if (heap.Size() == k) {
      ans = max(ans, (long long)(coord[size - 1].y * heap.GetMin()));
    }
    size--;
  }
  return ans;
}

int main() {
  unsigned int n;
  unsigned int k;
  cin >> n >> k;
  vector<Point> coord;
  Point temp;
  int x;
  int y;
  for (unsigned int i = 0; i < n; ++i) {
    cin >> x >> y;
    temp.x = x;
    temp.y = y;
    coord.push_back(temp);
  }
  cout << Maximum(coord, n, k) << '\n';
}