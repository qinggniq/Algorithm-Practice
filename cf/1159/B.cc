#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    int mi = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        if (i == 1 || i == n)
            mi = min(mi, tmp / (n - 1));
        else
            mi = min(mi, min(tmp / (i - 1), tmp / (n - i)));
    }
    cout << mi << endl;
}