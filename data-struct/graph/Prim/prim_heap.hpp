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
using PII = pair<int, int>;
// namespace ds {
// class PrimHeap {
//  public:
//   typedef std::pair<int, int> PII;

//  public:
//   PrimHeap(int v, const vector<vector<int>>& in)
//       : V(v), g(v), dis(v), parent(v), mstSet(v) {
//     for (auto edgs : in) {
//       g.addEdge(edgs[0], edgs[1], edgs[2]);
//     }
//     fill(dis.begin(), dis.end(), INT_MAX);
//     fill(mstSet.begin(), mstSet.end(), false);
//     parent[0] = -1;

//     priority_queue<PII, vector<PII>, std::greater<PII>> pq;
//     int src = 0;
//     pq.push({0, src});
//     dis[0] = 0;
//     for (int i = 1; i < V; ++i) {
//       int u = pq.top().second;
//       pq.pop();
//       mstSet[u] = true;
//       auto adj = g.adj(u);
//       for (const Edge& e : adj) {
//         int v = e.v;
//         int w = e.w;
//         if (mstSet[v] == false && dis[v] > w) {
//           dis[v] = w;
//           pq.push({w, v});
//           parent[v] = u;
//         }
//       }
//     }
//   }
//   void print() {
//     for (int i = 1; i < V; ++i) {
//       cout << parent[i] << " - " << i << " \t" << dis[i] << endl;
//     }
//   }

//  private:
//   int V;
//   vector<int> dis;
//   vector<int> parent;
//   vector<bool> mstSet;
//   GraphLinkList g;
// };
// }  // namespace ds

namespace ds {
class PrimHeap {
 public:
  PrimHeap(int v, const vector<vector<int>>& in) : V(v), g(v), parent(v) {
    for (const auto& n : in) {
      g.addEdge(n[0], n[1], n[2]);
    }
    dis.assign(V, INT_MAX);
    vis.assign(V, false);
    parent[0] = -1;
    dis[0] = 0;
    priority_queue<PII> q;
    q.push({0, 0});  //{dis, src}
    int cnt = 0;
    for (int i = 1; i < V; ++i) {
      auto now = q.top();
      q.pop();
      vis[now.second] = true;
      for (const Edge& edg : g.adj(now.second)) {
        int nxt = edg.v;
        int w = edg.w;
        if (!vis[w] && dis[nxt] > w) {
          dis[nxt] = w;
          parent[nxt] = now.second;
          q.push({w, nxt});
        }
      }
    }
  }

 private:
  int V;
  vector<int> parent;
  vector<int> dis;
  vector<bool> vis;
  GraphLinkList g;
};

}  // namespace ds