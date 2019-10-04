#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int l, r;
    bool operator<(const node& rhs) {
        return l < rhs.l;
    }
};

void solve() {
    int N, T; cin >> N >> T;
    vector<node> segs(N);
    for (int i=0; i<N; ++i) cin >> segs[i].l >> segs[i].r;
    sort(segs.begin(), segs.end());
    int over = 0, ans = 0;
    int i = 0, pos = 0;
    while (over < T) {
        int start = over+1;
        for (i = pos; i < N; ++i) {
            if (segs[i].l <= start) over = max(over, segs[i].r);
            else {
                pos = i; break;
            }
        }
        if (start > over) {
            cout << "-1\n";
            return;
        }
        ans++;
    }
    if (over >= T) cout << ans << endl;
}

int main() {
    int n; n = 1;
    while (n--) {
        solve();
    }
}