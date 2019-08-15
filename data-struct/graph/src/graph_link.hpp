#ifndef __graph_link__
#define __graph_link__

#include <iostream>
#include <vector>

using std::fill;
using std::pair;
using std::vector;
namespace ds {
struct Edge {
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};
struct GraphNode {
  int id;  // node id
  std::vector<Edge> next;
};

class GraphLinkList {
 public:
  GraphLinkList(int n_) : n(n_), graph_(n_ + 1) {}
  void addEdge(int u, int v, int w) {
    graph_[u].id = u;
    graph_[u].next.push_back(Edge(u, v, w));
    graph_[v].id = v;
    graph_[v].next.push_back(Edge(v, u, w));
  }
  vector<Edge> adj(int v) const { return graph_[v].next; }
  // int getW(int u, int v) const {}

 private:
  int n;  // node number
  std::vector<GraphNode> graph_;
};

class GraphMatrix {
 public:
  GraphMatrix(int v) {
    g.resize(v);
    fill(g.begin(), g.end(), vector<int>(v, 0));
  }
  GraphMatrix(const vector<vector<int>>& in) : g(in) {}
  void addEdge(int u, int v, int w) {
    g[u][v] = w;
    g[v][u] = w;
  }
  int getW(int u, int v) const { return g[u][v]; }

 private:
  vector<vector<int>> g;
};

class Digraph {
 public:
  Digraph() = default;
  Digraph(int v, const vector<pair<int, int>>& in)
      : V(v), in_deg(v, 0), out_deg(v, 0) {
    g.resize(V);
    for (auto& p : in) {
      in_deg[p.second]++;
      out_deg[p.first]++;
      g[p.first].push_back(p.second);
    }
  }
  Digraph(int v, const vector<vector<int>>& _g) : V(v), g(_g) {}
  int getV() const { return V; }
  vector<vector<int>> getG() const { return g; }
  Digraph getRG() {
    vector<vector<int>> res(V, vector<int>());
    for (int i = 0; i < V; ++i) {
      for (int w : g[i]) {
        res[w].push_back(i);
      }
    }
    return Digraph(V, res);
  }
  vector<int> adj(int w) const { return g[w]; }
  vector<int> getInDeg() const { return in_deg; }
  vector<int> getOutDeg() const { return out_deg; }

 private:
  int V;
  vector<vector<int>> g;
  vector<int> in_deg;
  vector<int> out_deg;
};

}  // namespace ds

#endif