#include <cmath>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::string;

template <typename T>
class Node {
 public:
  int h;
  T elem;
  Node* couple;
  Node* l;
  Node* r;
};

template <typename T>
class AVLTree {
 public:
  ~AVLTree();
  void Delete(Node<T>* root);
  int Height(Node<T>* root);
  Node<T>* NewNode(T elem);
  Node<T>* InsertT(Node<T>* root, T elem);
  void Insert(T elem);

  Node<T>* RightRotate(Node<T>* ty);
  Node<T>* LeftRotate(Node<T>* tx);

  int GetBalance(Node<T>* root);
  Node<T>* GetHead();
  Node<T>* BalanceRotate(Node<T>* root, int balance, T elem);
  Node<T>* FindT(Node<T>* root, const T& elem);
  Node<T>* Find(const T& elem);

 private:
  Node<T>* head_ = nullptr;
};

template <typename T>
AVLTree<T>::~AVLTree<T>() {
  Delete(head_);
}

template <typename T>
void AVLTree<T>::Delete(Node<T>* root) {
  if (root) {
    Delete(root->l);
    Delete(root->r);
    delete root;
  }
}

template <typename T>
Node<T>* AVLTree<T>::Find(const T& elem) {
  return FindT(head_, elem);
}

template <typename T>
Node<T>* AVLTree<T>::FindT(Node<T>* root, const T& elem) {
  if (root == nullptr || elem == root->elem) {
    return root;
  }
  if (elem >= root->elem) {
    return FindT(root->r, elem);
  }
  return FindT(root->l, elem);
}

template <typename T>
void AVLTree<T>::Insert(T elem) {
  head_ = InsertT(head_, elem);
}

template <typename T>
int AVLTree<T>::Height(Node<T>* root) {
  if (root == nullptr) {
    return 0;
  }
  return root->h;
}

template <typename T>
Node<T>* AVLTree<T>::GetHead() {
  return head_;
}

template <typename T>
Node<T>* AVLTree<T>::NewNode(T elem) {
  Node<T>* root = new Node<T>();
  root->elem = elem;
  root->l = root->r = nullptr;
  root->h = 1;
  return root;
}

template <typename T>
Node<T>* AVLTree<T>::RightRotate(Node<T>* ty) {
  Node<T>* tx = ty->l;
  Node<T>* tree_temp = tx->r;
  tx->r = ty;
  ty->l = tree_temp;
  ty->h = max(Height(ty->l), Height(ty->r)) + 1;
  tx->h = max(Height(tx->l), Height(tx->r)) + 1;
  return tx;
}

template <typename T>
Node<T>* AVLTree<T>::LeftRotate(Node<T>* tx) {
  Node<T>* ty = tx->r;
  Node<T>* tree_temp = ty->l;
  ty->l = tx;
  tx->r = tree_temp;
  tx->h = max(Height(tx->l), Height(tx->r)) + 1;
  ty->h = max(Height(ty->l), Height(ty->r)) + 1;
  return ty;
}

template <typename T>
void Binding(AVLTree<T>& tree1, AVLTree<T>& tree2, const T& val1,
             const T& val2) {
  Node<T>* node1 = tree1.Find(val1);
  Node<T>* node2 = tree2.Find(val2);
  node1->couple = node2;
  node2->couple = node1;
}

template <typename T>
Node<T>* PairSearch(AVLTree<T>& t1, AVLTree<T>& t2, const T& val) {
  if (t1.Find(val) != nullptr) {
    return t1.Find(val)->couple;
  }
  return t2.Find(val)->couple;
}

template <typename T>
int AVLTree<T>::GetBalance(Node<T>* root) {
  if (root == nullptr) {
    return 0;
  }
  return Height(root->l) - Height(root->r);
}

template <typename T>
Node<T>* AVLTree<T>::BalanceRotate(Node<T>* root, int balance, T elem) {
  if (balance > 1 && elem < root->l->elem) {
    return RightRotate(root);
  }
  if (balance < -1 && elem > root->r->elem) {
    return LeftRotate(root);
  }
  if (balance > 1 && elem > root->l->elem) {
    root->l = LeftRotate(root->l);
    return RightRotate(root);
  }
  if (balance < -1 && elem < root->r->elem) {
    root->r = RightRotate(root->r);
    return LeftRotate(root);
  }
  return root;
}

template <typename T>
Node<T>* AVLTree<T>::InsertT(Node<T>* root, T elem) {
  if (root == nullptr) {
    return (NewNode(elem));
  }
  if (elem < root->elem) {
    root->l = InsertT(root->l, elem);
  } else if (elem > root->elem) {
    root->r = InsertT(root->r, elem);
  } else {
    return root;
  }
  root->h = 1 + max(Height(root->l), Height(root->r));
  int balance = GetBalance(root);
  return BalanceRotate(root, balance, elem);
}

int main() {
  unsigned int n;
  cin >> n;
  AVLTree<string> avl1;
  AVLTree<string> avl2;
  string s1;
  string s2;
  for (unsigned int i = 0; i < n; ++i) {
    cin >> s1 >> s2;
    avl1.Insert(s1);
    avl2.Insert(s2);
    Binding(avl1, avl2, s1, s2);
  }
  unsigned int q;
  cin >> q;
  string pair_key;
  for (unsigned int i = 0; i < q; ++i) {
    cin >> pair_key;
    cout << PairSearch(avl1, avl2, pair_key)->elem << '\n';
  }
  return 0;
}
