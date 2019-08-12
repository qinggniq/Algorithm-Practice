/*
* author : qinggniq
* github : https://github.com/qinggniq
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;
bool ok(int x)
{
    int cnt = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((1 << i) & x)
            cnt++;
    }
    return cnt % 2 == 0;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int t = 0; t < q; ++t)
    {
        int pos, tar;
        cin >> pos >> tar;
        A[pos] = tar;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int tmp = 0;
                for (int l = i; l <= j; ++l)
                {
                    tmp ^= A[l];
                }
                if (ok(tmp))
                    ans = max(ans, j - i + 1);
            }
        }
        cout << ans << " ";
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}