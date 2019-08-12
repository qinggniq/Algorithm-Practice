#include <iostream>
#include "strongly_connected_component.hpp"

using namespace ds;

int main() {
  vector<pair<int, int>> in;  //{{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
  in.push_back({1, 0});
  in.push_back({0, 2});
  in.push_back({2, 1});
  in.push_back({0, 3});
  in.push_back({3, 4});
  Digraph g(5, in);
  KosarajuSCC kscc(g);
  auto coms = kscc.getComponents();
  for (auto n : coms) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}