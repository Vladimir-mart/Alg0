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
  void SiftDown(int index);             //+
  void SiftUp(int index);               //+
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

void BinaryHeap::SiftUp(int index) {
  int perent = GetPerent(index);
  while (perent >= 0 && a[perent] > a[index]) {
    swap(a[perent], a[index]);
    index = perent;
    perent = GetPerent(index);
  }
}
void BinaryHeap::SiftDown(int i) {
  while ((2 * i + 1) <
         (int)a.size()) {  // heapSize — количество элементов в куче
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

void HeapQueries(BinaryHeap& ls, const string& request) {
  if (request == "insert") {
    int number;
    cin >> number;
    ls.Insert(number);
    cout << "ok" << '\n';
    return;
  }
  if (request == "size") {
    cout << ls.Size() << '\n';
    return;
  }
  if (request == "clear") {
    ls.Clear();
    cout << "ok" << '\n';
    return;
  }
  if (ls.IsEmpty()) {
    if (request == "extract_min") {
      cout << ls.GetMin() << '\n';
      ls.Extractmin();
    }
    if (request == "get_min") {
      cout << ls.GetMin() << '\n';
    }
  } else {
    cout << "error" << '\n';
  }
}

int main() {
  BinaryHeap heap;
  long long n;
  cin >> n;
  string request;
  for (long long i = 0; i < n; i++) {
    cin >> request;
    HeapQueries(heap, request);
  }
}