#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int sz = s.size(), i = 0;
    vector<int> ls(sz), rs(sz);
    int cnt = 0;
    while (i < sz)
    {
        //int cnt = 0;
        while (i > 0 && i < sz && s[i] == 'v' && s[i - 1] == 'v')
            cnt++, i++;
        while (i < sz && s[i] == 'o')
        {
            ls[i] = cnt;
            i++;
        }
        i++;
    }
    i = sz - 1;
    cnt = 0;
    while (i >= 0)
    {
        // cnt = 0;
        while (i < sz - 1 && i >= 0 && s[i] == 'v' && s[i + 1] == 'v')
            cnt++, i--;
        while (i >= 0 && s[i] == 'o')
        {
            rs[i] = cnt;
            i--;
        }
        i--;
    }
    long long ans = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (s[i] == 'o')
        {
            ans += ((long long)ls[i] * rs[i]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    solve();
}