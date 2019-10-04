#include <bits/stdc++.h>

using namespace std;

long long dp[200010][2];
void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; getline(cin, s);
    getline(cin, s);
    dp[0][0] = b; dp[0][1] = 1e15;
    for (int i=0; i < n; ++i) {
        if (s[i] == '0') {
            dp[i+1][0] = min(dp[i][0] + a, dp[i][1] + a + a) + b;
            dp[i+1][1] = min(dp[i][1] + a, dp[i][0] + a + a) + b + b;
        }else{
            dp[i+1][0] = 1e15;
            dp[i+1][1] = dp[i][1] + b + b + a;
        }
    }
    cout << dp[n][0] << endl;
}

int main() {
    int n; cin >> n;
    while (n--) {
        solve();
    }
}