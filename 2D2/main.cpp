#include <deque>
#include <iostream>
#include <vector>
using namespace std;

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
  vector<int> a;

 private:
  void SiftDown(unsigned int index);    //+
  void SiftUp(unsigned int index);      //+
  static int GetLeftChild(int index);   //+
  static int GetRightChild(int index);  //+
  static int GetPerent(int index);      //+
};

void BinaryHeap::Show() {
  cout << " Show ";
  for (unsigned int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}

void BinaryHeap::Clear() { a.clear(); }

int BinaryHeap::GetMin() { return a[0]; }

size_t BinaryHeap::Size() const { return a.size(); }

bool BinaryHeap::IsEmpty() const { return !a.empty(); }

void BinaryHeap::Insert(int value) {
  if (a.size() == 1) {
    if (a[0] == 0) {
      a[0] = value;
      return;
    }
  }
  a.push_back(value);
  SiftUp(a.size() - 1);
}

int BinaryHeap::GetPerent(int index) { return (index - 1) / 2; }

int BinaryHeap::GetLeftChild(int index) { return 2 * index + 1; }

int BinaryHeap::GetRightChild(int index) { return 2 * index + 2; }

void BinaryHeap::Extractmin() {
  swap(a[0], a[a.size() - 1]);
  a.pop_back();

  SiftDown(0);
}

void BinaryHeap::SiftUp(unsigned int index) {
  int perent = GetPerent(index);
  while (perent >= 0 && a[perent] > a[index]) {
    swap(a[perent], a[index]);
    index = perent;
    perent = GetPerent(index);
  }
}
void BinaryHeap::SiftDown(unsigned int i) {
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

BinaryHeap::BinaryHeap(/* args */) {}

BinaryHeap::~BinaryHeap() {}

vector<int> Split(vector<int> arr1, vector<int> arr2) {
  vector<int> arr_res;
  int nres = arr1.size() + arr2.size();
  BinaryHeap ls;
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