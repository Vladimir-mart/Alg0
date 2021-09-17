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
  bool isEmpty() const;

 private:
  // Структура узла односвязного списка
  struct Node {
    long long vale;
    Node* next;
    long long min_s;
  };
  // Размер списка
  long long size_stack;
  // Голова односвязного списка
  Node* head;
};

List::List() {
  size_stack = 0;
  head = nullptr;
}

bool List::isEmpty() const {
  if (size_stack != 0) {
    return true;
  }
  return false;
}
void List::Push(long long t) {
  Node* time = new Node;
  time->next = head;
  time->vale = t;
  size_stack++;
  if (size_stack > 1) {
    time->min_s = min(head->min_s, t);
  }
  head = time;
  if (size_stack == 1) {
    time->min_s = time->vale;
  }
}

int List::Pop() {
  Node* newHead = head->next;
  int a = head->vale;
  delete head;
  head = newHead;
  size_stack--;
  return a;
}

void List::Clear() {
  while (size_stack != 0) {
    Pop();
  }
}

void List::Show() {
  Node* time = head;
  while (time != 0) {
    cout << time->vale << " ";
    time = time->next;
  }
  cout << '\n';
}

int List::Back() { return head->vale; }

int List::Min() const { return head->min_s; }

uint64_t List::Size() const { return size_stack; }

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
  if (ls->isEmpty()) {
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