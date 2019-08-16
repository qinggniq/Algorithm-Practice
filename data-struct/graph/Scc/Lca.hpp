/*
 * The implemenation of Lca
 * Author : qinggniq
 * Related:
 *      https://oi-wiki.org/graph/lca/
 */

#pragma once
#include <vector>

using std::vector;
namespace ds {
struct Node {
  int val;
  Node *left, *right;
};

static Node* normalLca(Node* root, Node* p, Node* q) {
  if (root == nullptr) return root;
  if (p == root) return root;
  if (q == root) return root;
  Node* l = normalLca(root->left, p, q);
  Node* r = normalLca(root->right, p, q);
  if (l != nullptr && r != nullptr) return root;
  if (l != nullptr)
    return r;
  else
    return l;
}

class LcaInc {
 public:
  LcaInc(const vector<vector<int>>& _v, const vector<vector<int>>& _w)
      : v(_v), w(_w) {
    father.assign(v.size(), vector<int>(31));
    cost.assign(v.size(), vector<int>(31));
    dep.resize(v.size());
    dfs(1, 0);  // index from 1
  }
  int lca(int x, int y) {
    if (dep[x] > dep[y]) std::swap(x, y);
    int diff = dep[y] - dep[y], ans = 0;
    for (int i = 0; diff; ++i, diff >>= 1) {
      if (diff & 1) ans += cost[y][i], y = father[y][i];
    }
    if (x == y) return ans;
    for (int i = 30; i >= 0 && y != x; --i) {
      if (father[x][i] != father[y][i]) {  // find the first father
        ans += cost[x][i] + cost[y][i];
        x = father[x][i];
        y = father[y][i];
      }
    }
    ans += cost[y][0] + cost[x][0];
    return ans;
  }

 private:
  void dfs(int root, int fno) {
    father[root][0] = fno;     // root's 2^0 father = father
    dep[root] = dep[fno] + 1;  // dep of root = dep of faher+1

    for (int i = 1; i < 31; ++i) {
      // t = father[root][i-1] : father of len 2^(i-1);
      // father[t][i-1] fahter of len 2^(i-1), add them get
      // father of root len 2^i
      father[root][i] = father[father[root][i - 1]][i - 1];
      cost[root][i] = cost[father[root][i - 1]][i - 1] + cost[root][i - 1];
    }
    int sz = v[root].size();
    for (int i = 0; i < sz; ++i) {
      if (v[root][i] == fno) continue;
      cost[v[root][i]][0] = w[root][i];
      dfs(v[root][i], root);
    }
  }
  vector<vector<int>> v;  // v[root] : vector<int> denote the adj of node root;
  vector<vector<int>> w;  // w:weight of edges
  vector<vector<int>> father, cost;
  vector<int> dep;
};
}  // namespace ds
