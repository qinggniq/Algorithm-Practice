/*
 * The implemenation of top sort;
 * Author : qinggniq
 *
 * Related:
 *      wiki: https://en.wikipedia.org/wiki/Topological_sorting
 *      code: https://www.geeksforgeeks.org/topological-sorting/
 */

#include <queue>
#include "graph_link.hpp"

using std::queue;
namespace ds {
class TopSort {
 public:
  TopSort(int v, const vector<pair<int, int>>& in) : V(v), g(v, in) {
    Digraph dg(v, in);
    vector<int> in_deg = dg.getInDeg();
    queue<int> q;
    for (int i = 0; i < V; ++i) {
      if (in_deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int sz = q.size();
      longest_path.push_back(q.front());
      while (sz--) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int n : dg.adj(cur)) {
          in_deg[n]--;
          if (in_deg[n] == 0) q.push(n);
        }
      }
    }
  }

  bool isTopo() const { return ans.size() == V; }
  vector<int> getTopo() const { return ans; }
  vector<int> getLongestPath() const { return longest_path; }
  void print() {
    std::cout << "Top sort : ";
    for (int n : ans) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "Longest paht length : " << longest_path.size() << std::endl;
    for (int n : longest_path) std::cout << n << " ";
    std::cout << std::endl;
  }

 private:
  int V;
  Digraph g;
  vector<int> ans;
  vector<int> longest_path;
};
}  // namespace ds