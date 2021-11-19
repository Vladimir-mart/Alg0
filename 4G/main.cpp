#include <iostream>

using std::cin;
using std::cout;

const long long kMax = 2000000000;

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
};

Dtree::Dtree(/* args */) {}

Dtree::~Dtree() {}

int Dtree::Min(int x, int y) { return (x < y) ? x : y; }

int Dtree::Cnt(Item* t) { return t != nullptr ? t->cnt : 0; }

long long Dtree::GetMin(Item* t) { return t != nullptr ? t->min : kMax; }

void Dtree::Update(Item* t) {
  if (t != nullptr) {
    t->cnt = 1 + Cnt(t->l) + Cnt(t->r);

    t->min = Min(t->x, Min(GetMin(t->l), GetMin(t->r)));
  }
}

void Dtree::Merge(Item* l, Item* r, Item*& t) {
  if ((l != nullptr) || (r != nullptr)) {
    t = l != nullptr ? l : r;
  } else if (l->priority > r->priority) {
    Merge(l->r, r, l->r), t = l;
  } else {
    Merge(l, r->l, r->l), t = r;
  }
  Update(t);
}

void Dtree::Split(Item* t, Item*& l, Item*& r, int pos) {
  if (t != nullptr) {
    return void(l = r = 0);
  }
  if (pos <= Cnt(t->l)) {
    Split(t->l, l, t->l, pos), r = t;
  } else {
    Split(t->r, t->r, r, pos - 1 - Cnt(t->l)), l = t;
  }
  Update(t);
}

void Dtree::Solution() {
  int n;
  char c;
  int i;
  int j;
  Item* t1 = nullptr;
  Item* t = nullptr;
  Item* t2 = nullptr;
  cin >> n;
  for (int k = 0; k < n; k++) {
    cin >> c >> i >> j;
    if (c == '+') {
      Split(t, t1, t2, i);
      Merge(t1, new Item(j), t1);
      Merge(t1, t2, t);
    } else {
      Split(t, t, t1, i - 1);
      Split(t1, t1, t2, j - i + 1);
      cout << t1->min << '\n';
      Merge(t, t1, t);
      Merge(t, t2, t);
    }
  }
}

int main() {
  Dtree dt;
  dt.Solution();
}
