#include <iostream>

using namespace std;

int main() {
    int i, j, k;cin >> i >> j >> k;
    cout << (min(j , k) >= i ? "Yes": "No") <<endl;
    //for_each(nums.begin(), nums.end(), [](auto it){cout << it << " ";});
    std::swap(i, j);
}