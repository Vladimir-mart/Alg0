#include <cmath>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::string;

template <typename T>
class AVLTree {
 public:
  ~AVLTree();
  void Insert(T elem);
  void AvlQ(AVLTree<string>& avl1, AVLTree<string>& avl2);

 private:
  struct Node {
    int h;
    T elem;
    Node* couple;
    Node* l;
    Node* r;
  };
  void Binding(AVLTree<T>& tree1, AVLTree<T>& tree2, const T& val1,
               const T& val2);
  void Delete(Node* root);
  int Height(Node* root);
  Node* NewNode(T elem);
  Node* InsertT(Node* root, T elem);
  Node* RightRotate(Node* ty);
  Node* LeftRotate(Node* tx);
  int GetBalance(Node* root);
  Node* GetHead();
  Node* BalanceRotate(Node* root, int balance, T elem);
  Node* FindT(Node* root, const T& elem);
  Node* Find(const T& elem);
  Node* PairSearch(AVLTree& t1, AVLTree& t2, const T& val);
  Node* head_ = nullptr;
};

template <typename T>
AVLTree<T>::~AVLTree<T>() {
  Delete(head_);
}

template <typename T>
void AVLTree<T>::Delete(Node* root) {
  if (root) {
    Delete(root->l);
    Delete(root->r);
    delete root;
  }
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::Find(const T& elem) {
  return FindT(head_, elem);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::FindT(Node* root, const T& elem) {
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
int AVLTree<T>::Height(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  return root->h;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::GetHead() {
  return head_;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::NewNode(T elem) {
  Node* root = new Node();
  root->elem = elem;
  root->l = root->r = nullptr;
  root->h = 1;
  return root;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::RightRotate(Node* ty) {
  Node* tx = ty->l;
  Node* tree_temp = tx->r;
  tx->r = ty;
  ty->l = tree_temp;
  ty->h = max(Height(ty->l), Height(ty->r)) + 1;
  tx->h = max(Height(tx->l), Height(tx->r)) + 1;
  return tx;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::LeftRotate(Node* tx) {
  Node* ty = tx->r;
  Node* tree_temp = ty->l;
  ty->l = tx;
  tx->r = tree_temp;
  tx->h = max(Height(tx->l), Height(tx->r)) + 1;
  ty->h = max(Height(ty->l), Height(ty->r)) + 1;
  return ty;
}

template <typename T>
void AVLTree<T>::Binding(AVLTree<T>& tree1, AVLTree<T>& tree2, const T& val1,
                         const T& val2) {
  Node* node1 = tree1.Find(val1);
  Node* node2 = tree2.Find(val2);
  node1->couple = node2;
  node2->couple = node1;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::PairSearch(AVLTree<T>& t1,
                                                  AVLTree<T>& t2,
                                                  const T& val) {
  if (t1.Find(val) != nullptr) {
    return t1.Find(val)->couple;
  }
  return t2.Find(val)->couple;
}

template <typename T>
int AVLTree<T>::GetBalance(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  return Height(root->l) - Height(root->r);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::BalanceRotate(Node* root, int balance,
                                                     T elem) {
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
typename AVLTree<T>::Node* AVLTree<T>::InsertT(Node* root, T elem) {
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

template <typename T>
void AVLTree<T>::AvlQ(AVLTree<string>& avl1, AVLTree<string>& avl2) {
  unsigned int n;
  cin >> n;
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
}

int main() {
  AVLTree<string> avl1;
  AVLTree<string> avl2;
  AVLTree<string> res;
  res.AvlQ(avl1, avl2);
}
