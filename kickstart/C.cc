/*
* author : qinggniq
* github : https://github.com/qinggniq
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using ll = long long;
using PII = pair<ll, ll>;
struct Node
{
    ll pos, cost, dis;
};

void solve()
{
    ll K, N;
    cin >> K >> N;
    vector<Node> stall(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> stall[i].dis;
        stall[i].pos = i;
    }
    for (ll i = 0; i < N; ++i)
    {
        cin >> stall[i].cost;
    }
    ll ans = (ll)100 * INT_MAX;
    //sort(stall.begin(), stall.end(), [](Node a, Node b) { return a.dis < b.dis; });
    for (ll i = 0; i < N; ++i)
    {
        priority_queue<ll, vector<ll>, std::greater<ll>> q;
        for (ll l = 0; l < i; ++l)
        {
            q.push(stall[l].cost + abs(stall[i].dis - stall[l].dis));
        }
        for (ll r = i + 1; r < N; ++r)
        {
            q.push(stall[r].cost + abs(stall[r].dis - stall[i].dis));
        }
        ll sm = stall[i].cost;
        for (ll _ = 0; _ < K; ++_)
        {
            sm += q.top();
            q.pop();
        }
        ans = min(ans, sm);
    }
    cout << ans;
}

int main()
{
    ll T;
    cin >> T;
    for (ll i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}