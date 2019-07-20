#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int t, n; cin>>t;
    
    for (int i=0; i<t; ++i) {
        cin >> n;
        int up = min(n, static_cast<int>(sqrt(n))+1);
        int a, b, tx, ansx = INT_MAX, ansy=0;
        for (int i=1; i<=up; ++i) {
            if (n % i == 0) { 
                a = i; b = n/i;
                if (a == b) continue;
                tx = (b-a);
                if (tx%2 == 0) {
                    if (ansx > tx/2) {
                        ansx = tx/2;
                        ansy = (b+a)/2;
                    }        
                }   
            }
        }
        if (ansx != INT_MAX) cout << ansx << endl;
        else cout << "-1" << endl;
        //cout << ansx << " " << ansy << endl;
    }
}