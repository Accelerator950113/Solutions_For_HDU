#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int n;
unsigned long long a[128];

int main() {

	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	for (int i = 5; i < 55; ++ i) 
		a[i] = a[i-1] + a[i-3];

	while (cin >> n) {
		if (n == 0) break;
		cout << a[n] << endl;
	}

    return 0;
}
