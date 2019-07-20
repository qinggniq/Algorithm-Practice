#include <iostream>
#include <vector>

using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    bool win = true;

    if (k % 3 == 0)
    {
        int np = n % (k + 1);
        if (np % 3 == 0 && np != k)
        {
            win = false;
        }
    }
    else
    {
        int np = n % 3;
        if (np == 0)
            win = false;
    }
    cout << (win ? "Alice" : "Bob") << endl;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}