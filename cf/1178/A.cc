#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct Node
{
    int val, pos;
};

void solve()
{
    int n, sm = 0, fsm = 0;
    cin >> n;
    vector<Node> nums(n), fill;
    vector<int> ans(1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i].val;
        nums[i].pos = i + 1;
        if (nums[i].val <= nums[0].val / 2)
        {
            fill.push_back(nums[i]);
            fsm += nums[i].val;
        }

        sm += nums[i].val;
    }
    sm /= 2;
    //sort(fill.begin(), fill.end(), [](Node &a, Node &b) { return a.val > b.val; });
    //int sm = accumulate(nums.begin(), nums.end())
    int cnt = nums[0].val + fsm;
    if (cnt > sm)
    {
        cout << fill.size() + 1 << "\n";
        cout << "1 ";
        for (int i = 0; i < fill.size(); ++i)
            cout << fill[i].pos << " ";
        cout << "\n";
    }
    else
    {
        cout << "0\n";
    }
}

int main()
{
    solve();
}