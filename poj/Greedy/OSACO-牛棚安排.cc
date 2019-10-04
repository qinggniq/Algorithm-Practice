#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct cow{
    int l, r;
    int no; 
    cow(int l, int r, int no):l(l), r(r), no(no) {}
    // bool operator<(const cow& rhs) const { 
    //     if (rhs.l == l) return r > rhs.r;
    //     return l < rhs.l;
    // }
};

bool operator<(const cow& lhs, const cow& rhs){ 
     return lhs.r < rhs.l;
}
void solve() {
    multiset<cow> st;
    int n, l, r; cin >> n;
    for (int i=0; i < n; i++) {
        cin >> l >> r;
        st.insert(cow(l, r, i));
    }
    int ans = 0;
    vector<int> res(n);
    while (!st.empty()) {
        ans++;
        multiset<cow>::iterator it = st.begin();
        res[it->no] = ans;
        cow nxt = *(it);
        st.erase(it);
        while ((it = upper_bound(st.begin(), st.end(), nxt)) != st.end()) {
            res[it->no] = ans;
            nxt = *(it);
            st.erase(it);
        }
    }
    cout << ans<<endl;
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
}

int main() {
    int n; n = 1;
    while (n--) {
        solve();
    }
}