#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 2== 0) {
        cout << "NO\n";
        return;
    }
    vector<int> nums(2*n);
    int cnt = 1;
    bool flag = true;
    for (int i=0; i <n; i++) {
        if (flag)
            nums[i] = cnt;
        else
            nums[i] = cnt + 3, cnt += 4;
        flag = !flag;
    }
    int cur = accumulate(nums.begin(), nums.begin() + n, 0);
    
     flag = true;
    for (int i=n; i<2*n; ++i) {
        if (flag) {
            nums[i] = nums[i-n] + 1;
            cur++;
        }else{
            nums[i] = nums[i-n]-1;
            cur--;
        }
        flag = !flag;
    }
    cout << "YES\n";
    for (int n:nums) {
        cout << n << " ";
    }
}

int main() {
int n;n = 1;
while (n--) {
solve();
}
}