#include <iostream>
#include <vector>
// #include <algorithm>

float abs(float a) {
    return a > 0 ? a : -a;
}
using namespace std;

int main() {
    int n; cin >> n;
    vector<float> nums(n, 0.0);
    for (int i=0; i<n; ++i) cin >> nums[i];

    float n_sum = 0.0, p_sum = 0.0;
    for (int i=0; i<n; ++i) {
        if (nums[i] >= 0) {
            p_sum += (static_cast<int>(nums[i]));
        } else {
            n_sum += ::abs(static_cast<int>(nums[i]));
        }
    }
    int diff = static_cast<int>(p_sum - n_sum);
    if (diff <= 0) {
        diff = -diff;

        for (int i=0; i<n; ++i) {
            if (diff && (nums[i] > 0) && (nums[i] != static_cast<int>(nums[i]))) {
                cout << (static_cast<int>(nums[i]) + 1) << endl; diff--;
            }else{
                cout << static_cast<int>(nums[i]) << endl;
            }
        }
    }else{
        for (int i=0; i<n; ++i) {
            if (diff && (nums[i] < 0) && (nums[i] != static_cast<int>(nums[i]))) {
                cout << (static_cast<int>(nums[i]) - 1) << endl; diff--;
            }else{
                cout << static_cast<int>(nums[i]) << endl;
            }
        }
    }

    //cout <<  static_cast<int>(-0.9) << endl;
    return 0;
}