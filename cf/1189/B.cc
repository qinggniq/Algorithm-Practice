#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    if (nums[n-3] + nums[n-2] <= nums[n-1]) {
        cout << "NO";
    }else{
        cout << "YES" << endl;
        cout << nums[n-3] << " ";
        for (int i=0; i<n-3; ++i) cout << nums[i] << " ";
        cout << nums[n-2] << " " << nums[n-1];
    }
}