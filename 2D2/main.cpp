#include <deque>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::swap;
using std::vector;

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
  static int GetPerent(int index);      //+
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
  swap(heap_value_[0], heap_value_[heap_value_.size() - 1]);
  heap_value_.pop_back();

  SiftDown(0);
}

template <typename T>
void BinaryHeap<T>::SiftUp(unsigned int index) {
  int perent = GetPerent(index);
  while (perent >= 0 && heap_value_[perent] > heap_value_[index]) {
    swap(heap_value_[perent], heap_value_[index]);
    index = perent;
    perent = GetPerent(index);
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

template <typename T>
vector<int> Merge(vector<T> arr1, vector<T> arr2) {
  vector<T> arr_res;
  int nres = arr1.size() + arr2.size();
  BinaryHeap<T> ls;
  for (unsigned int i = 0; i < arr1.size(); i++) {
    ls.Insert(arr1[i]);
  }
  for (unsigned int i = 0; i < arr2.size(); i++) {
    ls.Insert(arr2[i]);
  }
  for (int i = 0; i < nres; i++) {
    // cout << ls.GetMin() << "+++" << '\n';
    arr_res.push_back(ls.GetMin());
    ls.Extractmin();
  }
  ls.Clear();
  return arr_res;
}

int main() {
  int n_over;
  cin >> n_over;
  deque<vector<int>> merge_grid;
  for (int j = 0; j < n_over; j++) {
    int n1;
    cin >> n1;
    vector<int> arr1;
    int temp_arr1;
    for (int i = 0; i < n1; i++) {
      cin >> temp_arr1;
      arr1.push_back(temp_arr1);
    }
    merge_grid.push_front(arr1);
  }
  while (merge_grid.size() != 1) {
    merge_grid.push_back(Merge(merge_grid[0], merge_grid[1]));
    merge_grid.pop_front();
    merge_grid.pop_front();
  }
  for (unsigned int i = 0; i < merge_grid[0].size(); i++) {
    cout << merge_grid[0][i] << " ";
  }
  cout << '\n';
  merge_grid.clear();
  return 0;
}
