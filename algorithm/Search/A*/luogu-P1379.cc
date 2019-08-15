/*
 * source: https://www.luogu.org/problemnew/show/P1379
 * author : qinggniq
 * github : https://github.com/qinggniq
 * tag : search
 * method : A*
 * tutor :
 *      https://blog.csdn.net/hitwhylz/article/details/23089415
 *      https://oi-wiki.org/search/astar/
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

const int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int fx, fy;
char ch;

struct Matrix {
  int a[5][5];
  bool operator<(const Matrix& rhs) const {
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (a[i][j] != rhs.a[i][j]) return true;
      }
    }
    return false;
  }
} s, t;

int h(Matrix a) {  // cacl the h(x) : guss cost to target
  int ret = 0;
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      if (a.a[i][j] != t.a[i][j]) ret++;
  return ret;
}

struct Node {
  Matrix m;
  int g;  // g(x) : cost from source
  bool operator<(const Node& rhs) const { return g + h(m) > rhs.g + h(rhs.m); }
} x;

priority_queue<Node> pq;
set<Matrix> vis;

void solve() {
  t.a[1][1] = 1;
  t.a[1][2] = 2;
  t.a[1][3] = 3;
  t.a[2][1] = 8;
  t.a[2][2] = 0;
  t.a[2][3] = 4;
  t.a[3][1] = 7;
  t.a[3][2] = 6;
  t.a[3][3] = 5;
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j) {
      cin >> ch;
      s.a[i][j] = ch - '0';
    }
  pq.push({s, 0});
  while (!pq.empty()) {
    x = pq.top();
    pq.pop();
    if (!h(x.m)) {  // to target
      cout << x.g << endl;
      return;
    }
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (!x.m.a[i][j]) fx = i, fy = j;
      }
    }
    for (int i = 0; i < 4; ++i) {
      int nx = fx + dire[i][0], ny = fy + dire[i][1];
      if (1 <= nx && nx <= 3 && 1 <= ny && ny <= 3) {
        swap(x.m.a[nx][ny], x.m.a[fx][fy]);
        if (!vis.count(x.m)) vis.insert(x.m), pq.push({x.m, x.g + 1});
        swap(x.m.a[nx][ny], x.m.a[fx][fy]);
      }
    }
  }
  return;
}

int main() {
  solve();
  return 0;
}