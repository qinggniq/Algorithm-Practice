#include "prim.hpp"
#include "prim_heap.hpp"

using namespace ds;

int main() {
  //   vector<vector<int>> in{{0, 2, 0, 6, 0},
  //                          {2, 0, 3, 8, 5},
  //                          {0, 3, 0, 0, 7},
  //                          {6, 8, 0, 0, 9},
  //                          {0, 5, 7, 9, 0}};
  //   Prim p(5, in);
  //   p.print();
  vector<vector<int>> iin{{0, 1, 4},  {0, 7, 8},  {1, 2, 8}, {1, 7, 11},
                          {2, 3, 7},  {2, 8, 2},  {2, 5, 4}, {3, 4, 9},
                          {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
                          {6, 8, 6},  {7, 8, 7}};
  PrimHeap ph(9, iin);
  cout << " ? " << endl;
  ph.print();
}