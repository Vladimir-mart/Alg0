#include <iostream>
using namespace std;

class List {
 private:
  struct Node;

 public:
  List();
  ~List();
  // Добавление узла в список
  void Push(long long t);
  // Удаление последнего добавленного узла из списка
  int Pop();
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
  // Структура узла односвязного списка
  struct Node {
    long long vale;
    Node* next;
    long long min_s;
  };
  // Размер списка
  long long size_stack_;
  // Голова односвязного списка
  Node* head_;
};

List::List() {
  size_stack_ = 0;
  head_ = nullptr;
}

bool List::IsEmpty() const {
  bool empt = false;
  if (size_stack_ != 0) {
    empt = true;
  }
  return empt;
}

void List::Push(long long t) {
  Node* time = new Node;
  time->next = head_;
  time->vale = t;
  size_stack_++;
  if (size_stack_ > 1) {
    time->min_s = min(head_->min_s, t);
  }
  head_ = time;
  if (size_stack_ == 1) {
    time->min_s = time->vale;
  }
}

int List::Pop() {
  Node* new_head = head_->next;
  int a = head_->vale;
  delete head_;
  head_ = new_head;
  size_stack_--;
  return a;
}

void List::Clear() {
  while (size_stack_ != 0) {
    Pop();
  }
}

void List::Show() {
  Node* time = head_;
  while (time != 0) {
    cout << time->vale << " ";
    time = time->next;
  }
  cout << '\n';
}

int List::Back() { return head_->vale; }

int List::Min() const { return head_->min_s; }

uint64_t List::Size() const { return size_stack_; }

List::~List() { Clear(); }

void Querys(List* ls, string request) {
  if (request == "push") {
    long long pu;
    cin >> pu;
    ls->Push(pu);
    cout << "ok" << '\n';
    return;
  }
  if (request == "size") {
    cout << ls->Size() << '\n';
    return;
  }
  if (request == "Clear") {
    ls->Clear();
    return;
  }
  if (ls->IsEmpty()) {
    if (request == "back") {
      cout << ls->Back() << '\n';
    }
    if (request == "pop") {
      cout << ls->Pop() << '\n';
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
    Querys(&ls, request);
  }
  return 0;
}