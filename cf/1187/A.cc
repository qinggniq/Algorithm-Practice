#include <iostream>

using namespace std;
//g99999 6666 6666 
int main() {
    int t; cin >> t;
    int a, b, c;
    while(t--) {
        cin >> a >> b >> c;
        if (a >= (b+c)) {
            cout << max(b, c) + 1 << endl;
            continue;
        } 
        if (a < (b+c)) {
            cout << max(a-b, a-c) + 1 << endl;
        }
    }
}