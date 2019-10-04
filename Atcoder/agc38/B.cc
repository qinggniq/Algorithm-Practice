#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    vector<int> ord(n, 1);
    set<int> st;
    bool flag = 0;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = n-2; i >= 0; --i) {
        if (nums[i] < nums[i+1]) ord[i] = ord[i+1] + 1;
        else ord[i] = 1;
        if (ord[i] >= k) flag = true;
    }
    for (int i=0; i < k; ++i) {
        st.insert(nums[i]);
    }
    int ret = ord[0] >= k ? 0 : 1;// ord[0] < k;
    for (int i=k; i < n; ++i) {
        st.insert(nums[i]);
        int mx = *st.rbegin(), mi = *st.begin();
        if (nums[i] != mx || nums[i-k] != mi){
            if (ord[i-k+1] < k) {
                ret++;
            }
        }
        st.erase(nums[i-k]);
    }
    cout << (ret + flag) << endl;
}

int main() {
    int n; n = 1;
    while (n--) {
        solve();
    }
}