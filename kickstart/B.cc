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

struct Node
{
    int pos;
    char dire;
};
void solve()
{
    int N, G, M;
    cin >> N >> G >> M;
    vector<Node> gus(G);
    vector<vector<pair<int, int>>> rem(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < G; ++i)
    {
        cin >> gus[i].pos >> gus[i].dire;
        rem[gus[i].pos].push_back({i, -1});
    }
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < G; ++j)
        {
            if (gus[j].dire == 'A')
            {
                if (gus[j].pos == 1)
                    gus[j].pos = N;
                else
                    gus[j].pos--;
            }
            else
            {
                if (gus[j].pos == N)
                    gus[j].pos = 1;
                else
                    gus[j].pos++;
            }
            if (rem[gus[j].pos].empty())
            {
                rem[gus[j].pos].push_back({j, i});
            }
            else
            {
                if (rem[gus[j].pos][0].second != i)
                {
                    rem[gus[j].pos] = vector<pair<int, int>>(1, {j, i});
                }
                else
                {
                    rem[gus[j].pos].push_back({j, i});
                }
            }
        }
    }
    vector<int> res(G, 0);
    for (int i = 1; i <= N; ++i)
    {
        for (auto n : rem[i])
        {
            res[n.first]++;
        }
    }
    for (int i = 0; i < G; ++i)
    {
        cout << res[i] << " ";
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