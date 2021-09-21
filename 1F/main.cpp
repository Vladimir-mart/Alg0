#include <iostream>

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
  // Не понимаю, почему он ругает его, проходи только с "_"
  long long size_stk_;
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
  cout << head_->value << '\n';
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

void Queries(List* ls, const string& request) {
  if (request == "push") {
    long long number;
    cin >> number;
    ls->Push(number);
    cout << "ok" << '\n';
    return;
  }
  if (request == "size") {
    cout << ls->Size() << '\n';
    return;
  }
  if (request == "clear") {
    ls->Clear();
    return;
  }
  if (ls->IsEmpty()) {
    if (request == "back") {
      cout << ls->Back() << '\n';
    }
    if (request == "pop") {
      ls->Pop();
    }
    if (request == "min") {
      cout << ls->Min() << '\n';
    }
  } else {
    cout << "error" << '\n';
  }
}

int main() {
  List ls;
  long long n;
  cin >> n;
  string request;
  for (long long i = 0; i < n; i++) {
    cin >> request;
    Queries(&ls, request);
  }
}