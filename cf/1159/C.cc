#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n), g(m);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < m; ++i)
        cin >> g[i];
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if (g[0] < b.back())
    {
        cout << "-1\n";
    }
    else if (b.back() == g[0])
    {
        long long ans = 0;
        for (int i = 0; i < g.size(); ++i)
        {
            ans += g[i];
        }
        b.pop_back();
        for (int i = 0; i < b.size(); ++i)
        {
            ans += (long long)b[i] * g.size();
        }
        cout << ans << "\n";
    }
    else
    {
        long long ans = 0;
        ans += b.back();
        b.pop_back();
        for (int i = 0; i < g.size(); ++i)
        {
            ans += g[i];
        }
        //ans += std::accumulate(g.begin(), g.end(), 0);
        if (!b.empty())
        {
            ans += (long long)b.back() * ((int)g.size() - 1);
            b.pop_back();
            for (int i = 0; i < b.size(); ++i)
            {
                ans += (long long)b[i] * g.size();
            }
        }
        cout << ans << endl;
    }
}