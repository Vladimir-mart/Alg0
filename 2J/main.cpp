#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

template <typename T>
class BinaryHeap {
 public:
  BinaryHeap(/* args */);
  void Extractmin();            //+
  const T GetMin();             //+
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
  static int GetPerent(int index);      //+
  vector<T> a;
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
const T BinaryHeap<T>::GetMin() {
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
void BinaryHeap<T>::Insert(const T& value) {
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

const double k_pr = 20.;

int main() {
  BinaryHeap<int> heap;
  long long n;
  cin >> n;
  long long l;
  for (int i = 0; i < n; i++) {
    cin >> l;
    heap.Insert(l);
  }
  long long n1;
  long long n2;
  double res = 0;
  while (heap.Size() != 1) {
    n1 = heap.GetMin();
    heap.Extractmin();
    n2 = heap.GetMin();
    heap.Extractmin();
    heap.Insert(n1 + n2);
    res += ((n1 / k_pr) + (n2 / k_pr));
  }
  cout << std::fixed << std::showpoint;
  cout << std::setprecision(2);
  cout << res;
}