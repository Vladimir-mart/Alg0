#include <iostream>

using std::cin;
using std::cout;

template <typename T>
struct Node {
  T key;
  Node* l;
  Node* r;
};

template <typename T>
class SplayT {
 public:
  SplayT() { head_ = nullptr; }
  ~SplayT() { Delete(head_); }
  void Delete(Node<T>* rt);

  Node<T>* GetHead();
  Node<T>* NewNode(int key);
  void Insert(int key);
  Node<T>* InsertT(Node<T>* rt, int d);

  Node<T>* RightRotate(Node<T>* x);
  Node<T>* LeftRotate(Node<T>* x);

  int FindNext(Node<T>* rt, int next, int dif_nice = -1, int answer = -1);

  void Search(int key);
  Node<T>* Splay(Node<T>* rt, int key);

 private:
  Node<T>* head_;
};

template <typename T>
Node<T>* SplayT<T>::Splay(Node<T>* rt, int key) {
  if (rt == nullptr || rt->key == key) {
    return rt;
  }
  if (rt->key > key) {
    if (rt->l != nullptr && rt->l->key > key) {
      rt->l->l = Splay(rt->l->l, key);
      rt = RightRotate(rt);
    } else if (rt->l != nullptr && rt->l->key < key) {
      rt->l->r = Splay(rt->l->r, key);
      (rt->l->r != nullptr) ? rt->l = LeftRotate(rt->l) : rt->l->r = nullptr;
    }
    return rt;
  }
  if (rt->key <= key) {
    if (rt->r == nullptr) {
      return rt;
    }
    if (rt->r->key > key) {
      rt->r->l = Splay(rt->r->l, key);
      if (rt->r->l != nullptr) {
        rt->r = RightRotate(rt->r);
      }
    } else if (rt->r->key < key) {
      rt->r->r = Splay(rt->r->r, key);
      rt = LeftRotate(rt);
    }
    return (rt->r == nullptr) ? rt : LeftRotate(rt);
  }
  return (rt->l == nullptr) ? rt : RightRotate(rt);
}

template <typename T>
void SplayT<T>::Search(int key) {
  head_ = Splay(head_, key);
}

template <typename T>
int SplayT<T>::FindNext(Node<T>* rt, int next, int dif_nice, int answer) {
  if (rt == nullptr) {
    return answer;
  }
  int difference = rt->key - next;
  if (difference >= 0) {
    if (dif_nice == -1) {
      dif_nice = difference;
      answer = rt->key;
    } else {
      if (difference < dif_nice) {
        dif_nice = difference;
        answer = rt->key;
      }
    }
    answer = FindNext(rt->l, next, dif_nice, answer);
  } else {
    answer = FindNext(rt->r, next, dif_nice, answer);
  }
  return answer;
}

template <typename T>
Node<T>* SplayT<T>::LeftRotate(Node<T>* x) {
  Node<T>* y = x->r;
  x->r = y->l;
  y->l = x;
  return y;
}

template <typename T>
Node<T>* SplayT<T>::RightRotate(Node<T>* x) {
  Node<T>* y = x->l;
  x->l = y->r;
  y->r = x;
  return y;
}

template <typename T>
Node<T>* SplayT<T>::NewNode(int key) {
  Node<T>* node = new Node<T>();
  node->key = key;
  node->l = node->r = nullptr;
  return (node);
}

template <typename T>
void SplayT<T>::Delete(Node<T>* rt) {
  if (rt != nullptr) {
    Delete(rt->l);
    Delete(rt->r);
    delete rt;
  }
}

template <typename T>
Node<T>* SplayT<T>::GetHead() {
  return head_;
}

template <typename T>
void SplayT<T>::Insert(int key) {
  head_ = InsertT(head_, key);
}

template <typename T>
Node<T>* SplayT<T>::InsertT(Node<T>* rt, int d) {
  Node<T>* temp = rt;
  if (temp == nullptr) {
    temp = NewNode(d);
    return temp;
  }
  if (d < temp->key) {
    if (temp->l == nullptr) {
      temp->l = NewNode(d);
      return temp;
    }
    InsertT(temp->l, d);
  } else {
    if (temp->r == nullptr) {
      temp->r = NewNode(d);
      return temp;
    }
    InsertT(temp->r, d);
  }
  return head_;
}

const long long kDiv = 1000000000;

int main() {
  int n;
  cin >> n;
  SplayT<int> rt;
  int key;
  char sign;
  int key_answer;
  char sign_last = '+';
  for (int i = 0; i < n; ++i) {
    cin >> sign >> key;
    if (sign == '+') {
      if (sign_last == '?') {
        rt.Insert((key_answer + key) % kDiv);
        rt.Search((key_answer + key) % kDiv);
        sign_last = '+';
      } else {
        rt.Insert(key);
        rt.Search(key);
      }
    } else {
      sign_last = sign;
      key_answer = rt.FindNext(rt.GetHead(), key);
      cout << key_answer << "\n";
    }
  }
  return 0;
}
