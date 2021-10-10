#include <iostream>
#include <vector>
using std::vector;
const int kByte = 8;
const int kMaxb = 255;
int GetByte(long long number, size_t n) {
  return number >> (kByte * n) & kMaxb;
}

void Sort(vector<long long>& data, size_t size, const size_t kN) {
  size_t counters[kMaxb + 1];
  for (size_t i = 0; i < kMaxb + 1; i++) {
    counters[i] = 0;
  }
  for (size_t i = 0; i < size; i++) {
    counters[GetByte(data[i], kN)]++;
  }
  for (size_t i = 1; i < kMaxb + 1; i++) {
    counters[i] += counters[i - 1];
  }
  long long* tmp = new long long[size];
  for (size_t i = size - 1;; i--) {
    tmp[--counters[GetByte(data[i], kN)]] = data[i];
    if (i == 0) {
      break;
    }
  }
  for (size_t i = 0; i < size; i++) {
    data[i] = tmp[i];
  }
  delete[] tmp;
}

void LSDSort(vector<long long>& data, size_t size) {
  size_t total_bytes = sizeof(long long);

  for (size_t byte = 0; byte < total_bytes; byte++) {
    Sort(data, size, byte);
  }
}

int main() {
  size_t n = 0;
  std::cin >> n;
  vector<long long> data;
  long long temp;
  for (size_t i = 0; i < n; i++) {
    std::cin >> temp;
    data.push_back(temp);
  }
  LSDSort(data, n);
  for (size_t i = 0; i < n; i++) {
    std::cout << data[i] << " ";
  }
  return 0;
}