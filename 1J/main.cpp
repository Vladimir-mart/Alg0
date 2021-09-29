#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::min;
using std::string;

class List {
 public:
  List();
  ~List();
  // Добавление узла в список
  void Push(char t);
  // Удаление последнего добавленного узла из списка
  void Pop();
  // Получить размер списка
  uint64_t Size() const;
  // Очистка списка
  void Clear();
  // Показ списка
  void Show();
  // Получения последнего элимента
  char Back();
  // Пустота
  bool IsEmpty() const;

 private:
  struct Node;
  // Структура узла односвязного списка
  struct Node {
    char value;
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

void List::Push(char t) {
  Node* temporary = new Node;
  temporary->next = head_;
  temporary->value = t;
  size_stk_++;
  head_ = temporary;
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

char List::Back() { return head_->value; }

uint64_t List::Size() const { return size_stk_; }

List::~List() { Clear(); }

void Check(List& s) {
  if (s.Size() == 0) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
int main() {
  List s;
  char c;
  while (1 == 1) {
    c = cin.get();
    if (c == '\n') {
      break;
    }
    switch (c) {
      case '(':
      case '{':
      case '[':
        s.Push(c);
        break;
      case ')':
      case '}':
      case ']':
        if (!s.IsEmpty() || (c == ')' && s.Back() != '(') ||
            (c == '}' && s.Back() != '{') || (c == ']' && s.Back() != '[')) {
          cout << "NO " << '\n';
          return 0;
        }
        s.Pop();
        break;
    }
  }
  Check(s);
  return 0;
}