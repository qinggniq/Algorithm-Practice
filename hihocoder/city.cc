#include <iostream>

using namespace std;

const int n = 5;
static int ans = 7;

char g[5][5];
int vis[5][5];
int dire[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};

bool nok(int r, int c) { return r >= n || r < 0 || c >= n || c < 0; }
int rev(int r, int c) {
  int cnt = 0;
  for (int i = 0; i < 5; ++i) {
    int nr = r + dire[i][0], nc = c + dire[i][1];

    if (nok(nr, nc)) continue;

    if (g[nr][nc] == '1') {
      cnt--;
      g[nr][nc] = '0';
    } else {
      cnt++;
      g[nr][nc] = '1';
    }
  }

  return cnt;
}

void go(int step, int cnt) {
  // cout << r << " "<< c<<  " " <<  cnt << endl;
  if (cnt == 25) {
    ans = min(ans, step);
    return;
  }
  if (step >= ans) {
    return;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!vis[i][j]) {
        int add = rev(i, j);
        vis[i][j] = 1;
        go(step + 1, cnt + add);
        rev(i, j);
        vis[i][j] = 0;
      }
    }
  }
  return;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ans = 7;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
        vis[i][j] = 0;
        cnt += (g[i][j] - '0');
      }

    go(0, cnt);
    if (ans == 7) {
      cout << "-1\n";
    } else {
      cout << ans << endl;
    }
  }
}