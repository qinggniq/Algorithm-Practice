#include <iostream>
#include "manacher.hpp"
using namespace std;
using namespace ds;
int main() {
  string s("fsadfffffffffffffffffffffffffF");
  Manacher m(s);
  cout << m.getMaxLen() << endl;
}
