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

int n,m;

bool check(int l, int r) {
	return ((l >= 1) && (r <= n));
}

void Solve(int d) {
	if ((d * d) > (2*m)) return;
	Solve(d + 1);
	if (d & 1) {
		if (m % d == 0) {
			if (check(m/d - d/2, m/d + d/2)) printf("[%d,%d]\n", m/d - d/2, m/d + d/2);
		}
	}
	else {
		if ((m % d != 0) && ((2*m) % d == 0)) {
			if (check(m/d - d/2 + 1, m/d + d/2)) printf("[%d,%d]\n", m/d - d/2 + 1, m/d + d/2);
		}
	}
}

int main() {

	while (scanf("%d%d", &n, &m) == 2) {
		if ((n == 0) && (m == 0)) break;
		Solve(1);
		puts("");
	}

    return 0;
}
