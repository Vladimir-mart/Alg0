#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

const int kByte = 8;
const int kMaxb = 255;


int GetByte(long long number, unsigned int n) {
  return number >> (kByte * n) & kMaxb;
}

template <typename T>
void Sort(vector<T>& data, unsigned int size, const unsigned int kN) {
  unsigned int counters[kMaxb + 1];
  for (unsigned int i = 0; i < kMaxb + 1; i++) {
    counters[i] = 0;
  }
  for (unsigned int i = 0; i < size; i++) {
    counters[GetByte(data[i], kN)]++;
  }
  for (unsigned int i = 1; i < kMaxb + 1; i++) {
    counters[i] += counters[i - 1];
  }
  long long* tmp = new long long[size];
  for (unsigned int i = size - 1;; i--) {
    tmp[--counters[GetByte(data[i], kN)]] = data[i];
    if (i == 0) {
      break;
    }
  }
  for (unsigned int i = 0; i < size; i++) {
    data[i] = tmp[i];
  }
  delete[] tmp;
}

template <typename T>
void LSDSort(vector<T>& data, unsigned int size) {
  unsigned int total_bytes = sizeof(long long);

  for (unsigned int byte = 0; byte < total_bytes; byte++) {
    Sort(data, size, byte);
  }
}

int main() {
  unsigned int n = 0;
  cin >> n;
  vector<long long> data;
  long long temp;
  for (unsigned int i = 0; i < n; i++) {
    cin >> temp;
    data.push_back(temp);
  }
  LSDSort(data, n);
  for (unsigned int i = 0; i < n; i++) {
    cout << data[i] << " ";
  }
  return 0;
}