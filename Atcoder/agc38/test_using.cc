#include <iostream>
using namespace std;

struct S{
	typedef long long ll;
	void f() {int i = 0;}
};

int main() {
	using S::ll;
}
