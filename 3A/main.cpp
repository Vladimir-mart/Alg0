#include <iostream>

using std::cin;
using std::cout;
using std::swap;

template <typename T>
class DecTree {
 public:
  DecTree();
  ~DecTree();
  void ResultsDisplay();

 private:
  struct Node {
   public:
    T x;
    T y;
    T label;
    Node* parent;
    Node* left;
    Node* right;
  };
  void Set(T xi, T yi, T labeli, Node& s);
  int treeSize_;
  Node* nodes_;
  Node** ordered_;
  Node* root_;
  int node_count_;
  void Delete(Node* root);
  void SortQuick(Node** pnodes, int left, int right);
  void MakeTree();
};

template <typename T>
void DecTree<T>::Set(T xi, T yi, T labeli, Node& s) {
  s.x = xi;
  s.y = -yi;
  s.label = labeli;
  s.parent = NULL;
  s.left = NULL;
  s.right = NULL;
}

template <typename T>
DecTree<T>::~DecTree() {
  // arr Nodes
  delete[] nodes_;
  delete[] ordered_;
}

template <typename T>
DecTree<T>::DecTree() {
  int a;
  int b;
  node_count_ = 0;
  cin >> treeSize_;
  nodes_ = new Node[treeSize_];
  ordered_ = new Node*[treeSize_];
  for (int i = 0; i < treeSize_; i++) {
    cin >> a >> b;
    Set(a, b, node_count_ + 1, nodes_[node_count_]);
    ordered_[node_count_] = nodes_ + node_count_;
    node_count_++;
  }
  SortQuick(ordered_, 0, treeSize_);
  MakeTree();
}

template <typename T>
void DecTree<T>::ResultsDisplay() {
  int parent;
  int left;
  int right;
  cout << "YES\n";
  for (int i = 0; i < treeSize_; i++) {
    if (nodes_[i].parent != nullptr) {
      parent = nodes_[i].parent->label;
    } else {
      parent = 0;
    }
    if (nodes_[i].left != nullptr) {
      left = nodes_[i].left->label;
    } else {
      left = 0;
    }
    if (nodes_[i].right != nullptr) {
      right = nodes_[i].right->label;
    } else {
      right = 0;
    }
    cout << parent << " " << left << " " << right << '\n';
  }
}

template <typename T>
void DecTree<T>::MakeTree() {
  Node* last = NULL;
  root_ = ordered_[0];
  last = root_;
  for (int i = 1; i < treeSize_; i++) {
    while (last->parent != NULL && ordered_[i]->y > last->y) {
      last = last->parent;
    }
    if (ordered_[i]->y <= last->y) {
      ordered_[i]->left = last->right;
      ordered_[i]->parent = last;
      if (last->right != nullptr) {
        last->right->parent = ordered_[i];
      }
      last->right = ordered_[i];

    } else {
      ordered_[i]->left = last;
      last->parent = ordered_[i];
      root_ = ordered_[i];
    }
    last = ordered_[i];
  }
}

template <typename T>
void DecTree<T>::SortQuick(Node** pnodes, int left, int right) {
  int l = left;
  int r = right - 1;
  Node* p;
  p = pnodes[l + rand() % (right - left)];
  do {
    while (pnodes[l]->x < p->x) {
      l++;
    }
    while (pnodes[r]->x > p->x) {
      r--;
    }
    if (l <= r) {
      swap(pnodes[l++], pnodes[r--]);
    }
  } while (l <= r);
  if (r - left > 0) {
    SortQuick(pnodes, left, r + 1);
  }
  if (right - l > 0) {
    SortQuick(pnodes, l, right);
  }
}

int main(void) {
  DecTree<int>* mytree = new DecTree<int>();
  mytree->ResultsDisplay();
  delete mytree;
}
