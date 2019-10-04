#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, d;
int solve() {
    vector<pair<double, double> > island(n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        //cin>>island[i].first>>island[i].second;
        if (y > d) {
            return -1;
        }
        island[i].first =  x - sqrt(double(d*d - y*y));
        island[i].second = x + sqrt(double(d*d - y*y));
    }
    sort(island.begin(), island.end());
    double over = island[0].second;
    int  ans = 1;
    for (int i = 1; i < n; ++i) {
        if (island[i].first <= over) {
            over = min(over, island[i].second);
        }else{
            ans++;
            over = island[i].second;
        }
    }
    return ans;
}
int main() {
    int Case = 1;
    while (cin >> n >> d) {
        cout << "Case " << Case << ": "<< solve() << endl;
        Case++;
    }
}