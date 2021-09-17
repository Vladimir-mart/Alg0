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
  long long size_stack_t;
  // Голова односвязного списка
  Node* head_s;
};

List::List() {
  size_stack_t = 0;
  head_s = nullptr;
}

bool List::IsEmpty() const {
  if (size_stack_t != 0) {
    return true;
  }
}
void List::Push(long long t) {
  Node* time = new Node;
  time->next = head_s;
  time->vale = t;
  size_stack_t++;
  if (size_stack_t > 1) {
    time->min_s = min(head_s->min_s, t);
  }
  head_s = time;
  if (size_stack_t == 1) {
    time->min_s = time->vale;
  }
}

int List::Pop() {
  Node* new_head = head_s->next;
  int a = head_s->vale;
  delete head_s;
  head_s = new_head;
  size_stack_t--;
  return a;
}

void List::Clear() {
  while (size_stack_t != 0) {
    Pop();
  }
}

void List::Show() {
  Node* time = head_s;
  while (time != 0) {
    cout << time->vale << " ";
    time = time->next;
  }
  cout << '\n';
}

int List::Back() { return head_s->vale; }

int List::Min() const { return head_s->min_s; }

uint64_t List::Size() const { return size_stack_t; }

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
  if (request == "clear") {
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