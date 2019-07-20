#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>

using namespace std;

class SegementTree{
public:
    SegementTree(int sz):st(sz) {
        for (int i=0; i<sz; ++i) {
            st[i] = INT_MAX;
        }
    }
    void upd(int o, int l, int r, int k, int v) {
    if (l == r) {
        st[o] = v;
        return;
    }
    int m = (l + r) / 2, ls = o * 2, rs = o * 2 + 1;
    if (k <= m)
        upd(ls, l, m, k, v);
    else
        upd(rs, m + 1, r, k, v);
    st[o] = min(st[ls], st[rs]);
}
int getMin(int o, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr)
        return st[o];
    int m = (l + r) / 2, ls = o * 2, rs = o * 2 + 1, res = 1e9;
    if (ql <= m)
        res = min(res, getMin(ls, l, m, ql, qr));
    if (qr > m)
        res = min(res, getMin(rs, m + 1, r, ql, qr));
    return res;
}

private:
    vector<int> st;
};

int main() {
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<int> a(n+1), b(n+1);
        vector<vector<int>> p(n+1, vector<int>());
        SegementTree st(n*4);
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            //a[i]--;
            p[a[i]].push_back(i);
            st.upd(1, 1, n, i, a[i]);
        }
        for (int i=0; i<n; ++i) {
            cin >> b[i];
            //b[i]--;
        }
        for (int i=1; i<=n; ++i) {
            reverse(p[i].begin(), p[i].end());
        }
        bool ok = true;
        for (int i=0; i<n; ++i) {
            if (p[b[i]].empty()) {
                ok = false;
                break;
            }
            int k = b[i], pos = p[b[i]].back();
            p[b[i]].pop_back();
            if (st.getMin(1, 1, n, 1, pos) < k) {
                ok = false;
                break;
            }
            st.upd(1, 1, n, pos, INT_MAX);
        }
         
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
//不管多大范围的排序都可以化简为两个数的排序