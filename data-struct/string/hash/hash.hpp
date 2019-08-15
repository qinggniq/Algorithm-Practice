#pragma once
#include <vector>

using std::vector;
namespace ds {
class HashMap {
  struct node {
    int nxt, key, val; /* data */
  };
  int get(int key) const {
    for (int p = head[hash(key)]; p; p = data[p].nxt) {
      if (data[p].key == key) return data[p].val;
    }
    return -1;  // nil value
  }
  void set(int key, int val) {
    for (int p = head[hash(key)]; p; p = data[p].nxt) {
      if (data[p].key == key) {
        data[p].val = val;
        return;
      }
    }
  }
  void add(int key, int val) {
    if (head[hash(key)] != -1) {
      return;
    }
    data.push_back({head[hash(key)], key, val});
    head[hash(key)] = data.size() - 1;
  }

 private:
  int mod;
  vector<node> data;
  vector<int> head;
  int hash(int key) { return key % mod; }
}
}  // namespace ds