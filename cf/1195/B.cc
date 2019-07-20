#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i <= n; ++i)
    {
        if (i * (i + 1) / 2 == k + n - i)
        {
            cout << n - i << endl;
            break;
        }
    }
    return 0;
}