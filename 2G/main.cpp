#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;
using std::swap;

template <typename T>
int InsertSearch(deque<T>& lol, int number, int iter1) {
  int ret;
  if (lol[0] >= number) {
    lol.push_front(number);
    return -1;
  }
  deque<int>::iterator it = lol.end();
  if (*(it - 1) > number) {
    if (iter1 <= (int)lol.size()) {
      if (*(it - iter1) < number) {
        it = lol.insert((it - iter1 + 1), number);
        ret = -1;
      } else {
        iter1++;
        return iter1;
      }
    } else {
      return -1;
    }
  } else {
    lol.push_back(number);
    return -1;
  }
  return ret;
}

template <typename T>
int Insert(deque<T>& lol, int n, const string kRequest) {
  if (kRequest == "insert") {
    int number;
    cin >> number;
    int iter1 = 1;
    while (true) {
      if (lol.empty() || lol.size() == 1) {
        lol.push_back(number);
        if (lol.size() == 1) {
          break;
        }
        if (lol[1] <= lol[0] && lol.size() == 2) {
          swap(lol[1], lol[0]);
        }
        break;
      }
      iter1 = InsertSearch(lol, number, iter1);
      if (iter1 == -1) {
        break;
      }
    }
    cout << "ok" << '\n';
    n--;
    return n;
  }
  return n;
}

template <typename T>
int Requests(deque<T>& lol, int n, const string kRequest) {
  if (kRequest == "clear") {
    cout << "ok" << '\n';
    lol.clear();
    n--;
    return n;
  }
  if (!lol.empty()) {
    if (kRequest == "extract_max") {
      cout << lol[lol.size() - 1] << '\n';
      lol.pop_back();
    }
    if (kRequest == "get_max") {
      cout << lol[lol.size() - 1] << '\n';
    }
    if (kRequest == "extract_min") {
      cout << lol[0] << '\n';
      lol.pop_front();
    }
    if (kRequest == "get_min") {
      cout << lol[0] << '\n';
    }
  } else {
    cout << "error" << '\n';
  }
  n--;
  return n;
}

int main() {
  deque<int> lol;
  int n;
  cin >> n;
  string request;
  while (n != 0) {
    cin >> request;
    if (request == "insert") {
      n = Insert(lol, n, request);
    } else {
      if (request == "size") {
        cout << lol.size() << '\n';
        n--;
      } else {
        n = Requests(lol, n, request);
      }
    }
  }
  lol.clear();
  return 0;
}
// тест