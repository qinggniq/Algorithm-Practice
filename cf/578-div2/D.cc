#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        ll f = 0;
        for (ll j = 0; j < n; j++)
        {
            if (s[i][j] == 'B')
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
            count++;
    }
    for (ll i = 0; i < n; i++)
    {
        ll f = 0;
        for (ll j = 0; j < n; j++)
        {
            if (s[j][i] == 'B')
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
            count++;
    }
    vector<pair<ll, ll>> row(n);
    vector<pair<ll, ll>> column(n);
    for (ll i = 0; i < n; i++)
    {
        ll first = -1, last = -1, f = 0;
        for (ll j = 0; j < n; j++)
        {
            if (f == 0 && s[i][j] == 'B')
            {
                first = j;
                last = j;
                f = 1;
            }
            else if (s[i][j] == 'B')
                last = j;
        }
 
        row[i].first = first;
        row[i].second = last;
    }
    for (ll i = 0; i < n; i++)
    {
        ll first = -1, last = -1, f = 0;
        for (ll j = 0; j < n; j++)
        {
            if (f == 0 && s[j][i] == 'B')
            {
                first = j;
                last = j;
                f = 1;
            }
            else if (s[j][i] == 'B')
                last = j;
        }
 
        column[i].first = first;
        column[i].second = last;
        // cout << column[i].first << " " << column[i].second << "\n";
    }
    vector<vector<pair<ll, ll>>> dp(n);
    for (ll i = 0; i < n; i++)
        dp[i] = vector<pair<ll, ll>>(n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            dp[i][j].first = 0;
            dp[i][j].second = 0;
        }
    }
 
    for (ll j = 0; j < n - k + 1; j++)
    {
        for (ll i = 0; i < k; i++)
        {
            if (row[i].first >= j && row[i].second <= j + k - 1)
                dp[0][j].first++;
        }
        for (ll i = k; i < n; i++)
        {
            ll t1 = dp[i - k][j].first;
            if (row[i - k].first >= j && row[i - k].second <= j + k - 1)
                t1--;
            if (row[i].first >= j && row[i].second <= j + k - 1)
                t1++;
            dp[i - k + 1][j].first = t1;
        }
    }
    for (ll i = 0; i < n - k + 1; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            if (column[j].first >= i && column[j].second <= i + k - 1)
                dp[i][0].second++;
        }
        for (ll j = k; j < n; j++)
        {
            ll t2 = dp[i][j - k].second;
            if (column[j - k].first >= i && column[j - k].second <= i + k - 1)
            {
                t2--;
            }
            if (column[j].first >= i && column[j].second <= i + k - 1)
            {
                t2++;
            }
            dp[i][j - k + 1].second = t2;
        }
    }
    ll maximum = -1;
    for (ll i = 0; i < n - k + 1; i++)
    {
        for (ll j = 0; j < n - k + 1; j++)
        {
            // cout << dp[i][j].second << " ";
            maximum = max(maximum, dp[i][j].first + dp[i][j].second);
        }
        // cout << "\n";
    }
    cout << count + maximum << "\n";
}