#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
int main() {
	int n;
   	setvbuf(stdout, NULL, _IONBF, 1024);
 	printf("input:");
	sleep(10);
	cout << "use \\n \n";
	cin >> n;
	cout << endl;
	return 0;
}
