#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Digraph {
 public:
  struct Node {
    vector<int> next;
  };
  vector<Node> g;
  int V;
  Digraph(const vector<Node>& nodes) : g(nodes) { V = nodes.size(); }
  Digraph(int v, const vector<vector<int>>& in) : V(v), g(v) {
    for (int i = 0; i < in.size(); ++i) {
      g[in[i][0]].next.push_back(in[i][1]);
    }
  }
  vector<int> adj(int u) const { return g[u].next; }
  Digraph getRG() {
    vector<Node> res(V);
    for (int i = 0; i < g.size(); ++i) {
      for (int n : g[i].next) {
        res[n].next.push_back(i);
      }
    }
    return Digraph(res);
  }
};

class Kscc {
 public:
  Kscc(int v, const vector<vector<int>>& in)
      : g(v, in), vis(v, false), sccs(v), V(v) {
    Digraph rg = g.getRG();
    for (int i = 0; i < V; ++i) {
      if (!vis[i]) {
        dfs(i, g);
      }
    }
    int sz = revPost.size();
    fill(vis.begin(), vis.end(), false);
    reverse(revPost.begin(), revPost.end());
    cur = 0;
    for (int i = 0; i < sz; ++i) {
      if (!vis[revPost[i]]) {
        dfs(revPost[i], rg);
        cur++;
      }
    }
  }

  void dfs(int u, const Digraph& gr) {
    vis[u] = 1;
    sccs[u] = cur;
    for (int n : gr.adj(u)) {
      if (!vis[n]) {
        dfs(n, gr);
      }
    }
    revPost.push_back(u);
  }

  vector<int> getSccs() const { return sccs; };

 private:
  int V;
  int cur;
  vector<bool> vis;
  vector<int> sccs;
  vector<int> revPost;
  Digraph g;
};

int main() {
  vector<vector<int>> in;  //{{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
  in.push_back({1, 0});
  in.push_back({0, 2});
  in.push_back({2, 1});
  in.push_back({0, 3});
  in.push_back({3, 4});
  Kscc kscc(5, in);
  auto coms = kscc.getSccs();
  for (auto n : coms) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}