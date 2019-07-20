#include <vector>
#include <iostream>

using namespace std;

void solve()
{
    string s, t, p;
    vector<int> tt(26, 0), pt(26, 0);
    getline(cin, s);
    getline(cin, t);
    getline(cin, p);

    for (int i = 0; i < s.length(); ++i)
    {
        ++tt[s[i] - 'a'];
    }
    for (int i = 0; i < p.length(); ++i)
    {
        ++tt[p[i] - 'a'];
    }
    for (int i = 0; i < t.length(); ++i)
    {
        if (--tt[t[i] - 'a'] < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    int sl = 0, tl = 0;
    //cout << "here out" << endl;
    while (sl < s.length() && tl < t.length())
    {
        while (tl < t.length() && t[tl] != s[sl])
            tl++;
        if (tl == t.length())
            break;
        sl++;
        tl++;
    }
    if (sl != s.length())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}
int main()
{
    int q;
    cin >> q;
    string tmp;
    getline(cin, tmp);
    while (q--)
    {
        solve();
    }
    return 0;
}