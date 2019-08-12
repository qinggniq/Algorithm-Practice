#include <iostream>

using namespace std;

const int kMod = 998244353;
void solve()
{
    int w, h;
    cin >> w >> h;
    int ans = 1;
    for (int i = 0; i < w + h; ++i)
    {
        ans = (ans * 2) % kMod;
    }
    cout << ans << "\n";
}

int main()
{
    solve();
}