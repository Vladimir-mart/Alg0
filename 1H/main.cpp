#include <iostream>
#include <string>
#include <vector>
// Не бейте -_-
using std::cin;
using std::cout;
using std::min;
using std::string;

class List {
 public:
  List();
  ~List();
  // Добавление узла в список
  void Push(long long t);
  // Удаление последнего добавленного узла из списка
  void Pop();
  // Получить размер списка
  uint64_t Size() const;
  // Очистка списка
  void Clear();
  // Показ списка
  void Show();
  // Получения последнего элимента
  int Back();
  // Получения минимума
  int Min() const;
  // Пустота
  bool IsEmpty() const;

 private:
  struct Node;
  // Структура узла односвязного списка
  struct Node {
    long long value;
    Node* next;
    long long min_s;
  };
  // Размер списка
  unsigned long long size_stk_;
  // Голова односвязного списка
  Node* head_;
};

List::List() {
  size_stk_ = 0;
  head_ = nullptr;
}

bool List::IsEmpty() const {
  bool empt = false;
  if (size_stk_ != 0) {
    empt = true;
  }
  return empt;
}

void List::Push(long long t) {
  Node* temporary = new Node;
  temporary->next = head_;
  temporary->value = t;
  size_stk_++;
  if (size_stk_ > 1) {
    temporary->min_s = min(head_->min_s, t);
  }
  head_ = temporary;
  if (size_stk_ == 1) {
    temporary->min_s = temporary->value;
  }
}

void List::Pop() {
  Node* new_head = head_->next;
  delete head_;
  head_ = new_head;
  size_stk_--;
}

void List::Clear() {
  while (size_stk_ != 0) {
    Pop();
  }
}

void List::Show() {
  Node* temporary = head_;
  while (temporary != 0) {
    cout << temporary->value << " ";
    temporary = temporary->next;
  }
  cout << '\n';
}

int List::Back() { return head_->value; }

int List::Min() const { return head_->min_s; }

uint64_t List::Size() const { return size_stk_; }

List::~List() { Clear(); }

// Не бейте, не помещается все в одно

unsigned int iter_split = 0;
unsigned int iter_temp = 0;
unsigned int iter_temp_check = 0;
int position = 0;
std::vector<string> st;
string temp;
string temp_check;

void CheckSplit(string arr, string split, unsigned int i) {
  if (arr[i] == split[iter_split]) {
    temp_check += arr[i];
    position = 1;
    iter_split++;
    iter_temp_check++;
    // Разрез найден
    if (iter_split == split.length()) {
      st.push_back(temp);
      temp.clear();
      temp_check.clear();
      iter_temp = 0;
      iter_temp_check = 0;
      iter_split = 0;
      position = 2;
    }
  } else {
    // Если разрез был не полностью
    if (position == 1) {
      position = 0;
      iter_temp += iter_temp_check;
      temp += temp_check;
    }
  }
}

std::vector<string> Spliter(string arr, string split) {
  for (unsigned int i = 0; i < arr.length(); i++) {
    // Проверка на начло разреза
    CheckSplit(arr, split, i);
    if (position == 0) {
      temp += arr[i];
      iter_temp++;
    }
    if (position == 2) {
      position = 0;
    }
  }
  st.push_back(temp);
  return st;
}

const int ten = 10;
int pol = 0;
List* PolishEntryCheck(List* stk, char c, int val) {
  if (pol == 1) {
    int a;
    int b;
    b = stk->Back();
    stk->Pop();
    a = stk->Back();
    stk->Pop();
    switch (c) {
      case '+':
        a += b;
        break;
      case '-':
        a -= b;
        break;
      case '*':
        a *= b;
        break;
      case '/':
        a /= b;
        break;
      default:
        break;
    }
    stk->Push(a);
    pol = 0;
  } else {
    stk->Push(val);
  }
  return stk;
}

int PolishEntry(List* stk, string arr) {
  int val = 0;
  string split;
  split = " ";
  std::vector<string> test = Spliter(arr, split);
  for (unsigned int i = 0; i < test.size(); i++) {
    val = 0;
    if (test[i][0] == '-' || test[i][0] == '+' || test[i][0] == '/' ||
        test[i][0] == '*') {
      pol = 1;
    } else {
      for (unsigned int j = 0; j < test[i].length(); j++) {
        val = val * ten + (test[i][j] - '0');
      }
    }
    stk = PolishEntryCheck(stk, test[i][0], val);
  }
  return stk->Back();
}

int main() {
  List stk;
  string arr;
  getline(cin, arr);
  cout << PolishEntry(&stk, arr) << '\n';
}