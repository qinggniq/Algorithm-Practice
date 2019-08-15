/*
 * The implemenation of Prim algorithm of Minimize Generated Tree.
 */
#pragma once
#include <algorithm>
#include <climits>
#include <iostream>
#include "graph_link.hpp"

using std::cout;
using std::endl;
using std::fill;
using std::vector;
namespace ds {
class Prim {
 public:
  Prim(int v, const vector<vector<int>>& in)
      : V(v), g(in), mstSet(v), parent(v), dis(v) {
    fill(mstSet.begin(), mstSet.end(), false);
    fill(dis.begin(), dis.end(), INT_MAX);
    dis[0] = 0;
    parent[0] = -1;

    for (int cnt = 0; cnt < V - 1; ++cnt) {
      int min_idx = minKey();
      mstSet[min_idx] = true;
      for (int v = 0; v < V; ++v) {
        if (g.getW(v, min_idx) && mstSet[v] == false &&
            g.getW(v, min_idx) < dis[v])
          dis[v] = g.getW(v, min_idx), parent[v] = min_idx;
      }
    }
  }

  void print() {
    cout << "The MST: " << endl;
    for (int i = 1; i < V; ++i) {
      cout << parent[i] << " - " << i << " \t" << g.getW(i, parent[i]) << endl;
    }
  }

 private:
  int minKey() {
    // auto mi = q.top();
    // q.pop();
    int mi = INT_MAX, min_idx;
    for (int i = 0; i < V; ++i)
      if (mstSet[i] == false && dis[i] < mi) mi = dis[i], min_idx = i;
    return min_idx;
  }

 private:
  int V;
  // priority_queue<pair<int, int>> q;
  vector<int> parent;   // store MST
  vector<int> dis;      // store minimum weight edge
  vector<bool> mstSet;  // intern set store inputed vetex
  GraphMatrix g;
};
}  // namespace ds