#include <deque>
#include <iostream>
#include <vector>
using namespace std;

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

template <typename T>
vector<int> Split(vector<T> arr1, vector<T> arr2) {
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
  deque<vector<int>> dque_vec;
  for (int j = 0; j < n_over; j++) {
    int n1;
    cin >> n1;
    vector<int> arr1;
    int temp_arr1;
    for (int i = 0; i < n1; i++) {
      cin >> temp_arr1;
      arr1.push_back(temp_arr1);
    }
    dque_vec.push_front(arr1);
  }
  while (dque_vec.size() != 1) {
    dque_vec.push_back(Split(dque_vec[0], dque_vec[1]));
    dque_vec.pop_front();
    dque_vec.pop_front();
  }
  for (unsigned int i = 0; i < dque_vec[0].size(); i++) {
    cout << dque_vec[0][i] << " ";
  }
  cout << '\n';
  dque_vec.clear();
  return 0;
}