#include<iostream>
#include<vector>

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> hei(n);
    for (int i = 0; i < n; ++i) cin >> hei[i];
    for (int i = 0; i +1 < n; ++i) {
        if (m + hei[i] < hei[i+1] - k) {
            cout << "NO" <<endl;
            return;
        }else{
            m += (hei[i] - max(hei[i+1] - k, 0));
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}