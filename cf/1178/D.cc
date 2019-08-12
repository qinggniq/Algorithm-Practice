#include <iostream>

using namespace std;

int prime[20000];
int book[20000];
int main()
{
    int cnt = 1;
    int n = 20000; //10000以内的素数表
    for (int i = 2; i <= n; i++)
    {
        if (book[i] == 0) //是素数
        {
            prime[cnt++] = i;                      //存储素数
            for (int j = i * i; j <= n; j = j + i) //遍历i*i-n
            {
                book[j] = 1; //不是素数的数赋值为1
            }
        }
    }
    cin >> n;
    int i;
    for (i = 0; i < 10000; ++i)
    {
        if (prime[i] >= n)
        {
            break;
        }
    }
    if (prime[i] == n)
    {
        cout << n << "\n";
        for (i = 1; i < n; ++i)
        {
            cout << i << " " << i + 1 << "\n";
        }
        cout << n << " 1\n";
    }
    else
    {
        int cnt = prime[i] - n;
        cout << prime[i] << "\n";
        for (i = 1; i < n; ++i)
        {
            cout << i << " " << i + 1 << "\n";
        }
        cout << n << " 1\n";

        for (int j = 1; j + 2 <= n && cnt-- > 0; j += 4)
        {
            cout << j << " " << j + 2 << "\n";
        }

        for (int j = 2; j + 2 <= n && cnt-- > 0; j += 4)
        {
            cout << j << " " << j + 2 << "\n";
        }
        if (cnt > 0)
            cout << n - 1 << " 2\n";
    }
}