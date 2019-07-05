#include <iostream>

using namespace std;

int main() {
    string s; cin >> s; cin >> s;
    int ones =  0, zeros = 0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '0') {
            zeros++;
        }else{
            ones++;
        }
    }
    if (zeros != ones) {
        cout << 1 << endl;
        cout << s << endl;
    }else{
        cout << 2 << endl;
        cout << s[0] << " " << s.substr(1) << endl;
    }
    return 0;
}