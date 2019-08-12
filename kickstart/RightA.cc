/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

bool odd(int x)
{
    int cnt = 0;
    while (x) {
        if (x & 1)
            cnt++;
        x /= 2;
    }
    return cnt & 1;
}

void solve()
{
    int N, Q, pos, val;
    cin >> N >> Q;
    vector<int> nums(N);
    set<int> st;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        if (odd(val))
            st.insert(i);
    }
    for (int i = 0; i < Q; ++i) {
        cin >> pos >> val;
        if (st.count(pos)) {
            if (!odd(val))
                st.erase(pos);
        } else {
            if (odd(val))
                st.insert(pos);
        }
        if (st.size() & 1) {
            int l = *(st.begin());
            auto it = st.end();
            it--;
            int r = *it;
            cout << max(N - l - 1, r) << " ";
        } else {
            cout << N << " ";
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}