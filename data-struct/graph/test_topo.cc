#include "top_sort.hpp"

using namespace ds;
int main() {
  vector<pair<int, int>> v;
  v.push_back({5, 2});
  v.push_back({5, 0});
  v.push_back({4, 0});
  v.push_back({4, 1});
  v.push_back({2, 3});
  v.push_back({3, 1});
  TopSort ts(6, v);
  if (ts.isTopo()) {
    ts.print();
  }
  return 0;
}