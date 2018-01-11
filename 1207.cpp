#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

unsigned long long f[128],g[128];
int n;

int main() {

	f[0] = 0, g[0] = 0;
	for (int i = 1;i <= 64;++ i)
		g[i] = g[i - 1] * 2 + 1;
	for (int i = 1;i <= 64;++ i) {
		f[i] = g[i];
		for (int x = 1;x < i;++ x)
			if ((2*f[x] + 2*g[i-1-x] + 1) < f[i]) f[i] = 2*f[x] + 2*g[i-1-x] + 1;
	}

	while (cin >> n)
		cout << f[n] << endl;

    return 0;
}
