#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int kN = 4;
const int kSz = 6;
void check(int n) {
    if (n == 0) exit(0);
}
int main() {
    int a, b, an;
    vector<int> nums(kSz+1, 1);
    vector<int> tmp={0, 4, 8, 15, 16, 23, 42};
    unordered_set<int> st, all{4, 8, 15, 16, 23, 42};

    cout << "? 1 2" << endl;
    cin >> an;
    check(an);
    for (int i=kSz; i >= 1; --i) 
        if (an % tmp[i] == 0 && all.count(tmp[i]) && all.count(an/tmp[i])) {
            nums[1] = tmp[i];st.insert(nums[1]);
            nums[2] = an / tmp[i];st.insert(nums[2]);
            break;
        }
    cout << "? 3 4" << endl;
    cin >> an;
     check(an);
    for (int i=kSz; i >= 1; --i) 
        if (an % tmp[i] == 0 && all.count(tmp[i]) && all.count(an/tmp[i])) {
            nums[3] = tmp[i];st.insert(nums[3]);
            nums[4] = an / tmp[i];st.insert(nums[4]);
            break;
        }
    for (int i=1, j=0; i<=kSz; ++i) {
        if (!st.count(tmp[i])) {
            int tm = tmp[i];
            nums[5+j] = tm;
            st.insert(tmp[i]);
            j++;
            if (j == 2) break;
        }
    }
    cout << "? 1 3" << endl;
    cin >> an;
     check(an);
    if (an % nums[2] == 0 && an/nums[2] != nums[2] && st.count(an/nums[2])) {
        swap(nums[1], nums[2]);
    }
    if (an % nums[4] == 0 && an/nums[4] != nums[4]&& st.count(an/nums[4])) {
        swap(nums[3], nums[4]);
    }
    cout << "? 1 5" << endl;
    cin >> an;
    check(an);
    if (an % nums[6] == 0 && an/nums[6] != nums[6]&& st.count(an/nums[6])) {
        swap(nums[5], nums[6]);
    }
    cout << "! ";
    for (int i=1; i<=kSz; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
    
}