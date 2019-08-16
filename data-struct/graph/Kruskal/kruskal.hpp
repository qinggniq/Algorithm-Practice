#include "union_find.hpp"
using namespace std;

class Kruskal {
  // vector in should be sorted
  Kruskal(const vector<vector<int>> in, int N) : uf(N) {
    int sz = in.size();
    int cnt = 0, tmp = -1;
    for (int i = 0; i < sz; ++i) {
      int x = in[i][0], y = in[i][1], v = in[i][2];
      if (!uf.connected(x, y)) {
        cnt++;
        tmp += v;
        if (cnt == N - 1) {
          ans = tmp;
          return;
        }
      }
    }
    ans = -1;
  }
  int MST() { return ans; }

 private:
  int ans;
  UF uf;
};