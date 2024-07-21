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
  void Extractmin();            //+
  const T& GetMin();            //+
  void Insert(const T& value);  //+
  bool IsEmpty() const;         //+
  size_t Size() const;          //+
  void Clear();                 //+
  void Show();
  ~BinaryHeap();

 private:
  void SiftDown(unsigned int index);    //+
  void SiftUp(unsigned int index);      //+
  static int GetLeftChild(int index);   //+
  static int GetRightChild(int index);  //+
  static int GetParent(int index);      //+
  vector<T> heap_value_;
};

template <typename T>
void BinaryHeap<T>::Show() {
  cout << " Show ";
  for (unsigned int i = 0; i < heap_value_.size(); i++) {
    cout << heap_value_[i] << " ";
  }
  cout << '\n';
}

template <typename T>
void BinaryHeap<T>::Clear() {
  heap_value_.clear();
}

template <typename T>
const T& BinaryHeap<T>::GetMin() {
  return heap_value_[0];
}

template <typename T>
size_t BinaryHeap<T>::Size() const {
  return heap_value_.size();
}

template <typename T>
bool BinaryHeap<T>::IsEmpty() const {
  return !heap_value_.empty();
}

template <typename T>
void BinaryHeap<T>::Insert(const T& value) {
  if (heap_value_.size() == 1) {
    if (heap_value_[0] == 0) {
      heap_value_[0] = value;
      return;
    }
  }
  heap_value_.push_back(value);
  SiftUp(heap_value_.size() - 1);
}

template <typename T>
int BinaryHeap<T>::GetParent(int index) {
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
  swap(heap_value_[0], heap_value_[heap_value_.size() - 1]);
  heap_value_.pop_back();

  SiftDown(0);
}

template <typename T>
void BinaryHeap<T>::SiftUp(unsigned int index) {
  int perent = GetParent(index);
  while (perent >= 0 && heap_value_[perent] > heap_value_[index]) {
    swap(heap_value_[perent], heap_value_[index]);
    index = perent;
    perent = GetParent(index);
  }
}

template <typename T>
void BinaryHeap<T>::SiftDown(unsigned int i) {
  while ((2 * i + 1) <
         heap_value_.size()) {  // heapSize — количество элементов в куче
    unsigned int left = GetLeftChild(i);    // left — левый сын
    unsigned int right = GetRightChild(i);  // right — правый сын
    unsigned int j = left;
    if (right < heap_value_.size() && heap_value_[right] < heap_value_[left]) {
      j = right;
    }
    if (heap_value_[i] <= heap_value_[j]) {
      break;
    }
    swap(heap_value_[i], heap_value_[j]);
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
