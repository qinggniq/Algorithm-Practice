#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n)), dis(n, vector<int>(n));
    for (int i=0; i < n; ++i) for (int j = 0; j < n; ++j) {
        char a; cin >> a;
        
        if (a == '0') g[i][j] = 1e9;
        else g[i][j] = 1;
        dis[i][j] = g[i][j];
        dis[i][i] = 0;
    }
    for (int k=0; k < n; ++k) {
        for (int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
    int m; cin >> m;
    vector<int> seq(m);
    for (int i = 0; i < m; ++i) cin >> seq[i], seq[i] = seq[i] - 1;
    for (int i=1, l = 0; i < m - 1; ++i) {
        if (dis[seq[l]][seq[i+1]] == i + 1 - l) seq[i] = -1;
        else l = i;
    }
    int cnt = 0;
    for (int i=0; i < m; ++i) {
        cnt += (seq[i] == -1 ? 0 : 1);
    }
    cout << cnt << endl;
    for (int i=0; i < m; ++i) {
        if (seq[i] != -1) cout << seq[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
int n; n=1;
while (n--) {
    solve();
    }
}