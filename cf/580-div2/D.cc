#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(180);
    vector<vector<long long>> g(180, vector<long long>(180));
    vector<vector<long long>> dis(180, vector<long long>(180));
    int cnt = 0;
    int i; 
    for (i=0; i < n; ++i) {
        long long num; cin >> num;
        if (num) {
            a[cnt++] = num;
            if (cnt > 120) {
                break;
            }   
        }
      
    }
    //cout << i << endl;
    if (i < n) {cout << "3\n"; return;}
    for (int i=0; i < cnt; ++i) for (int j = 0; j < cnt; ++j) {
        if (i != j && a[i] & a[j]) g[i][j] = dis[i][j] = 1;
        else g[i][j] = dis[i][j] = 1e9;
    }
    long long ans = 1e9;
    for (int k = 0; k < cnt; ++k) {
        for (int i=0; i < k; ++i) for (int j = 0; j < i; ++j) ans = min(ans, dis[i][j] + g[i][k] + g[j][k]);
        for (int i=0; i < cnt; ++i) for (int j = 0; j < cnt; ++j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    cout << (ans >= 1e9 ? -1 : ans ) <<  endl;
}

int main() {
int n; n = 1;
while (n--) {
solve();
}
}