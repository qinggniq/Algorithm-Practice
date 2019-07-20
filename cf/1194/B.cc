#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<string> g(m);
    vector<int> r(m), c(n);
    vector<vector<int>> b(m, vector<int>(n, 0));
    getline(cin, g[0]);
    for (int i = 0; i < m; ++i)
    {
        getline(cin, g[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j] == '.')
            {
                r[i]++;
                c[j]++;
                b[i][j] = 1;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ans = min(ans, r[i] + c[j] - b[i][j]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        solve();
    }
    return 0;
}