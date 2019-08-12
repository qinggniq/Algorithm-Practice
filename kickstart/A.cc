/*
* author : qinggniq
* github : https://github.com/qinggniq
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define maxn 500005
using namespace std;

using ll = long long;
using PII = pair<int, int>;

int c[maxn], a[maxn];
int n;
int Lowbit(int x) // 2^k
{
    return x & (-x);
}
void update(int i, int x) //i点增量为x
{
    while (i <= n)
    {
        c[i] ^= x;
        i += Lowbit(i);
    }
}
int sum(int x) //区间求和 [1,x]
{
    int sum = 0;
    while (x > 0)
    {
        sum ^= c[x];
        x -= Lowbit(x);
    }
    return sum;
}

int Getsum(int x1, int x2) //求任意区间和
{
    return sum(x2) ^ sum(x1 - 1);
}

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
    int q;
    cin >> n >> q;
    memset(c, 0, maxn * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    for (int t = 0; t < q; ++t)
    {
        int pos, tar;
        cin >> pos >> tar;
        update(pos + 1, tar ^ a[pos + 1]);
        a[pos + 1] = tar;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {

                if (ok(Getsum(i, j)))
                {
                    ans = max(ans, j - i + 1);
                }
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