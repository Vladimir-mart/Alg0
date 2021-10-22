#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;
using std::swap;

template <typename T>
int InsertSearch(deque<T>& dq, int number, int iter1) {
  int ret;
  if (dq[0] >= number) {
    dq.push_front(number);
    return -1;
  }
  deque<int>::iterator it = dq.end();
  if (*(it - 1) > number) {
    if (iter1 <= (int)dq.size()) {
      if (*(it - iter1) < number) {
        it = dq.insert((it - iter1 + 1), number);
        ret = -1;
      } else {
        iter1++;
        return iter1;
      }
    } else {
      return -1;
    }
  } else {
    dq.push_back(number);
    return -1;
  }
  return ret;
}

template <typename T>
int Insert(deque<T>& dq, int n, const string kRequest) {
  if (kRequest == "insert") {
    int number;
    cin >> number;
    int iter1 = 1;
    while (true) {
      if (dq.empty() || dq.size() == 1) {
        dq.push_back(number);
        if (dq.size() == 1) {
          break;
        }
        if (dq[1] <= dq[0] && dq.size() == 2) {
          swap(dq[1], dq[0]);
        }
        break;
      }
      iter1 = InsertSearch(dq, number, iter1);
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
int Requests(deque<T>& dq, int n, const string kRequest) {
  if (kRequest == "clear") {
    cout << "ok" << '\n';
    dq.clear();
    n--;
    return n;
  }
  if (!dq.empty()) {
    if (kRequest == "extract_max") {
      cout << dq[dq.size() - 1] << '\n';
      dq.pop_back();
    }
    if (kRequest == "get_max") {
      cout << dq[dq.size() - 1] << '\n';
    }
    if (kRequest == "extract_min") {
      cout << dq[0] << '\n';
      dq.pop_front();
    }
    if (kRequest == "get_min") {
      cout << dq[0] << '\n';
    }
  } else {
    cout << "error" << '\n';
  }
  n--;
  return n;
}

int main() {
  deque<int> dq;
  int n;
  cin >> n;
  string request;
  while (n != 0) {
    cin >> request;
    if (request == "insert") {
      n = Insert(dq, n, request);
    } else {
      if (request == "size") {
        cout << dq.size() << '\n';
        n--;
      } else {
        n = Requests(dq, n, request);
      }
    }
  }
  dq.clear();
  return 0;
}
// тест