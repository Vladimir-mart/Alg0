#include <iostream>
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
  // Для строк
  void PushStr(char* t);
  // Для строк
  void PopStr();
  // Для строк
  char* BackStr();
 private:
  // Структура узла односвязного списка
  struct Node {
    int vale;
    char* str_foo;
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

char* List::BackStr() {
  return head_->str_foo;
}

void List::PopStr() {
  Node* new_head = head_->next;
  delete head_;
  head_ = new_head;
  size_stack_--;
}

void List::PushStr(char* t) {
  Node* time = new Node;
  time->next = head_;
  time->str_foo = t;
  size_stack_++;
  head_ = time;
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

List Spliter(char* arr, char* split) { 
  int len = 0;
  int i = 0;
  int spl_i = 0;
  List temp;
  while(split[spl_i]+'0' != 48) {
    cout << split[spl_i]+'0' << '\n';
    spl_i++;
  }
  int spl_i_temp = spl_i;
  while(arr[len]+'0' != 48) {
    len++;
  }
  char* str1 = new char[len];
  char* str2 = new char[len];
  int q = 0;
  int pol = 1;
  int pol1 = 0;
  int q1 = 0;
  for(int i = 0; i < len; i++) {
    if(pol == 0) {
      str2 = str1;
      q = q + q1;
    }
    str1[i] = arr[i];
    if(arr[i] == split[i]) {
      pol = 0;
      q1++;
      spl_i_temp--;
      if(spl_i_temp == 0)
      {
        spl_i_temp = spl_i;
        temp.PushStr(str2);
        delete[] str2;
        q = 0;
        spl_i_temp = spl_i;
      }
    } else {
      q1 = 0;
      str2[q] = arr[i];
      q++;
    }
    len++;
  }
  temp.PushStr(str2);
}

int main() {
  List stk;
  char c;
  int V = 0;
  int i = 1;
  int pol = 0;
  while (c != '\n') {
    V = 0;
    while (c != ' ' || c != '\n') {
      c = cin.get();
      if (c == '0') {
        pol = 2;
      }
      if (c == '-' || c == '+' || c == '/' || c == '*') {
        pol = 1;
        break;
      }
      if (c == '\n' || c == ' ') {
        break;
      }
      V = V * 10 + (c - '0');
    }
    
    if (c == '\n') {
      break;
    }
    if (V == 0 && pol != 2 && pol != 1) {
      pol = 0;
    } else {
      if (pol == 1) {
        int a, b;
        b = stk.Back();
        stk.Pop();
        a = stk.Back();
        stk.Pop();
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
        stk.Push(a);
        pol = 0;
      } else {
        stk.Push(V);
      }
    }
    
  }
  cout << stk.Back() << '\n';
  return 0;
}