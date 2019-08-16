#pragma once
/*
 * The implemenation of Kosaraju
 *
 * Related Links:
 *      wiki: https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm
 *      code: https://blog.csdn.net/mmy1996/article/details/76685031
 *      problem: http://poj.org/problem?id=2186
 */
#include <iostream>
#include <vector>
#include "../graph_link.hpp"

using std::pair;
using std::vector;

namespace ds {

class KosarajuSCC {
 public:
  KosarajuSCC() = delete;
  KosarajuSCC(const Digraph& dg) {
    digrah = dg;
    V = digrah.getV();
    vis = vector<bool>(V, false);
    components = vector<int>(V, 0);
    Digraph reversed_graph = digrah.getRG();
    for (int i = 0; i < V; ++i) {  //先正遍历
      if (!vis[i]) {
        dfs(i, digrah);
      }
    }
    cur = 0;
    std::fill(vis.begin(), vis.end(), false);
    int sz = reversePost.size();
    for (int i = sz - 1; i >= 0; --i) {  //注意是从stack的顶部向下遍历
      if (!vis[reversePost[i]]) {
        dfs(reversePost[i], reversed_graph);
        cur++;
        // std::cout << "--- cur : " << cur << std::endl;
      }
    }
  }

  vector<int> getComponents() const { return components; }
  vector<vector<int>> getSccs() {
    for (int i = 0; i < cur; ++i) {
      sccs.push_back(vector<int>());
    }
    for (int i = 0; i < V; ++i) {
      sccs[components[i]].push_back(i);
    }
    return sccs;
  }

 private:
  void dfs(int v, Digraph g) {
    vis[v] = true;
    components[v] = cur;
    for (int w : g.adj(v)) {
      if (!vis[w]) {
        dfs(w, g);
      }
    }
    reversePost.push_back(v);
  }

 private:
  int V;
  int cur;  //当前分量id

  Digraph digrah;
  vector<int> reversePost;
  vector<bool> vis;
  vector<int> components;
  vector<vector<int>> sccs;
};

}  // namespace ds
