/*
 * The implemenation of Prim algorithm optimized using priority_queue
 */
#include <climits>
#include <iostream>
#include <queue>

#include "graph_link.hpp"

using std::cout;
using std::endl;
using std::priority_queue;
namespace ds {
class PrimHeap {
 public:
  typedef std::pair<int, int> PII;

 public:
  PrimHeap(int v, const vector<vector<int>>& in)
      : V(v), g(v), dis(v), parent(v), mstSet(v) {
    for (auto edgs : in) {
      g.addEdge(edgs[0], edgs[1], edgs[2]);
    }
    fill(dis.begin(), dis.end(), INT_MAX);
    fill(mstSet.begin(), mstSet.end(), false);
    parent[0] = -1;

    priority_queue<PII, vector<PII>, std::greater<PII>> pq;
    int src = 0;
    pq.push({0, src});
    dis[0] = 0;
    for (int i = 1; i < V; ++i) {
      int u = pq.top().second;
      pq.pop();
      mstSet[u] = true;
      auto adj = g.adj(u);
      for (const Edge& e : adj) {
        int v = e.v;
        int w = e.w;
        if (mstSet[v] == false && dis[v] > w) {
          dis[v] = w;
          pq.push({w, v});
          parent[v] = u;
        }
      }
    }
  }
  void print() {
    for (int i = 1; i < V; ++i) {
      cout << parent[i] << " - " << i << " \t" << dis[i] << endl;
    }
  }

 private:
  int V;
  vector<int> dis;
  vector<int> parent;
  vector<bool> mstSet;
  GraphLinkList g;
};
}  // namespace ds