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
  long long sz_stk_;
  // Голова односвязного списка
  Node* head_;
};

List::List() {
  sz_stk_ = 0;
  head_ = nullptr;
}

bool List::IsEmpty() const {
  bool empt = false;
  if (sz_stk_ != 0) {
    empt = true;
  }
  return empt;
}

void List::Push(long long t) {
  Node* temporary = new Node;
  temporary->next = head_;
  temporary->value = t;
  sz_stk_++;
  if (sz_stk_ > 1) {
    temporary->min_s = min(head_->min_s, t);
  }
  head_ = temporary;
  if (sz_stk_ == 1) {
    temporary->min_s = temporary->value;
  }
}

void List::Pop() {
  Node* new_head = head_->next;
  delete head_;
  head_ = new_head;
  sz_stk_--;
}

void List::Clear() {
  while (sz_stk_ != 0) {
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

uint64_t List::Size() const { return sz_stk_; }

List::~List() { Clear(); }

class Queue {
 public:
  Queue();
  void Enqueue(long long t);
  void Dequeue();
  int Min();
  int SizeQ();
  int Front();
  void Clear();
  bool IsEmpty();
  ~Queue();

 private:
  List in_, out_;
};

bool Queue::IsEmpty() {
  return ((in_.Size() + out_.Size()) != 0) ? true : false;
}

void Queue::Clear() {
  in_.Clear();
  out_.Clear();
}

int Queue::Front() {
  if (out_.Size() == 0) {
    while (in_.Size() != 0) {
      out_.Push(in_.Back());
      in_.Pop();
    }
  }
  return out_.Back();
}

int Queue::SizeQ() { return in_.Size() + out_.Size(); }

int Queue::Min() {
  if (in_.Size() == 0) {
    return out_.Min();
  }
  if (out_.Size() == 0) {
    return in_.Min();
  }
  return min(in_.Min(), out_.Min());
}

void Queue::Dequeue() {
  if (out_.Size() == 0) {
    while (in_.Size() != 0) {
      out_.Push(in_.Back());
      in_.Pop();
    }
  }
  cout << out_.Back() << '\n';
  out_.Pop();
}

void Queue::Enqueue(long long t) { in_.Push(t); }

Queue::Queue() {}

Queue::~Queue() { Clear(); }

void Querys(Queue* que, const string& request) {
  if (request == "enqueue") {
    long long pu;
    cin >> pu;
    que->Enqueue(pu);
    cout << "ok" << '\n';
    return;
  }
  if (request == "size") {
    cout << que->SizeQ() << '\n';
    return;
  }
  if (request == "clear") {
    que->Clear();
    cout << "ok" << '\n';
    return;
  }
  if (que->IsEmpty()) {
    if (request == "front") {
      cout << que->Front() << '\n';
    }
    if (request == "dequeue") {
      que->Dequeue();
    }
    if (request == "min") {
      cout << que->Min() << '\n';
    }
  } else {
    cout << "error" << '\n';
  }
}

int main() {
  Queue que;
  long long number;
  cin >> number;
  string request;
  for (long long i = 0; i < number; i++) {
    cin >> request;
    Querys(&que, request);
  }
}
