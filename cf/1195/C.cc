#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> h1(n), h2(n);
    for (int i = 0; i < n; ++i)
        cin >> h1[i];
    for (int i = 0; i < n; ++i)
        cin >> h2[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    dp[0][0] = h1[0];
    dp[0][1] = h2[0];
    dp[0][2] = 0;
    long long res = max(h1[0], h2[0]);
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + h1[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + h2[i];
        dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        res = max(max(dp[i][0], res), max(dp[i][1], dp[i][2]));
    }
    cout << res << "\n";
}