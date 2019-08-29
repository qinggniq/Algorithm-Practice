#include <assert.h>
#include <iostream>
#include <unordered_map>
#include "reserver.hpp"

Reservoir reserver;

void test_null() { assert(reserver.choice(vector<int>()) == -1); }

void test_one() { assert(reserver.choice({1}) == 1); }

void test_mul() {
  vector<int> v;
  std::unordered_map<int, int> freq;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  for (int i = 0; i < 10000; ++i) {
    freq[reserver.choice(v)]++;
  }
  for (int i = -1; i < 10; ++i) {
    assert(freq[i] < 1200);
  }
}

void test_K_null() {
  vector<int> v;
  assert(reserver.choiceK(v, 0).empty());
  assert(reserver.choiceK(v, 10).empty());
  for (int i = 0; i < 10; ++i) v.push_back(i);
  assert(reserver.choiceK(v, -1).empty());
}

void test_K() {
  vector<int> v;
  std::unordered_map<int, int> freq;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  for (int i = 0; i < 10000; ++i) {
    vector<int> ans = reserver.choiceK(v, 5);
    for (int n : ans) freq[n]++;
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << freq[i] << std::endl;
    assert(freq[i] < 5200 && freq[i] > 4800);
  }
}

int main() {
  test_null();
  test_one();
  test_mul();
  test_K_null();
  test_K();
}