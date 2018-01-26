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
#include <set>
#include <bitset>

using namespace std;

int f[1048576];

bool check(int x) {
	while (x) {
		if (x % 10 == 4) return 0;
		if (x % 100 == 62) return 0;
		x /= 10;
	}
	return 1;
}

int main() {

	f[0] = 1;
	for (int i = 1; i <= 1000000; ++ i)
		f[i] = f[i-1] + check(i);

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		if (n == 0 && m== 0) break;
		if (n > m) swap(n, m);
		printf("%d\n", f[m] - f[n-1]);
	}

    return 0;
}
