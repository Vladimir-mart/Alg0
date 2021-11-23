#include <iostream>

using std::cin;
using std::cout;

const long long max = 2000000000;

class Dtree {
 public:
  Dtree(/* args */);
  ~Dtree();
  static void Solution();

 private:
  struct Item {
    int priority;
    int x;
    int min;
    Item* l;
    Item* r;
    int cnt;
    Item(int x)
        : priority(rand()), x(x), min(x), l(nullptr), r(nullptr), cnt(0) {}
  };
  static int Min(int x, int y);
  static int Cnt(Item* t);
  static long long GetMin(Item* t);
  static void Update(Item* t);
  static void Merge(Item* l, Item* r, Item*& t);
  static void Split(Item* t, Item*& l, Item*& r, int pos);
  static void Delete(Item* tree);
};

void Dtree::Delete(Item* tree) {
  if (tree == nullptr) {
    return;
  }
  if (tree->l != nullptr) {
    Delete(tree->l);
  }
  if (tree->r != nullptr) {
    Delete(tree->r);
  }
  delete tree;
}

Dtree::Dtree(/* args */) {}

Dtree::~Dtree() {}

int Dtree::Min(int x, int y) { return (x < y) ? x : y; }

int Dtree::Cnt(Item* t) { return t != nullptr ? t->cnt : 0; }

long long Dtree::GetMin(Item* t) { return t != nullptr ? t->min : max; }

void Dtree::Update(Item* t) {
  if (t != nullptr) {
    t->cnt = 1 + Cnt(t->l) + Cnt(t->r);

    t->min = Min(t->x, Min(GetMin(t->l), GetMin(t->r)));
  }
}

void Dtree::Merge(Item* l, Item* r, Item*& t) {
  if (l == nullptr || r == nullptr) {
    t = l != nullptr ? l : r;
  } else if (l->priority > r->priority) {
    Merge(l->r, r, l->r), t = l;
  } else {
    Merge(l, r->l, r->l), t = r;
  }

  Update(t);
}

void Dtree::Split(Item* t, Item*& l, Item*& r, int pos) {
  if (t == nullptr) {
    return void(l = r = 0);
  }
  if (pos <= Cnt(t->l)) {
    Split(t->l, l, t->l, pos), r = t;
  }

  else {
    Split(t->r, t->r, r, pos - 1 - Cnt(t->l)), l = t;
  }

  Update(t);
}

void Dtree::Solution() {
  int n;
  char c;
  int i;
  int j;
  Dtree dt;
  Item* t1 = nullptr;
  Item* t = nullptr;
  Item* t2 = nullptr;
  cin >> n;
  for (int k = 0; k < n; k++) {
    cin >> c >> i >> j;
    if (c == '+') {
      dt.Split(t, t1, t2, i);
      dt.Merge(t1, new Item(j), t1);
      dt.Merge(t1, t2, t);
    } else {
      dt.Split(t, t, t1, i - 1);
      dt.Split(t1, t1, t2, j - i + 1);
      cout << t1->min << '\n';
      dt.Merge(t, t1, t);
      dt.Merge(t, t2, t);
    }
  }
  Delete(t);
}

int main() {
  Dtree dt;
  dt.Solution();
  return 0;
}
