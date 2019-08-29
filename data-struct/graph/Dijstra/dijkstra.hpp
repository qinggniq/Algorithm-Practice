/*
 * The implemenation of Digistra Algorithm.
 * TimeComplex:
 *    O(E*log(N))
 * author : qinggniq
 * github : https://github.com/qinggniq
 * Related:
 *     wiki: https://oi-wiki.org/graph/shortest-path/
 *     intro:
 * https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
 *
 */
#pragma once
#include <climits>
#include <queue>
#include "../graph_link.hpp"
#define INF 0x3f3f3f3f3f

using std::priority_queue;
namespace ds {
class Dijkstra {
 public:
  using PII = pair<int, int>;
  Dijkstra(const vector<vector<int>>& in, int _v)
      : g(_v, in), V(_v), dis(_v, INF), fa(_v) {
    priority_queue<PII, vector<PII>, std::greater<PII>> heap;
    heap.push({0, 0});
    dis[0] = 0;
    while (!heap.empty()) {
      int u = heap.top().second;
      heap.pop();
      for (Edge e : g.adj(u)) {
        int v = e.v;
        if (e.w + dis[u] < dis[v]) {
          dis[v] = e.w + dis[u];
          fa[v] = u;
          heap.push({dis[v], v});
        }
      }
    }
  }
  vector<int> getMinPath() const { return fa; }
  int getDis(int v) const { return dis[v]; }

 private:
  int V;
  vector<int> dis;
  vector<int> fa;
  GraphLinkList g;
};
}  // namespace ds
