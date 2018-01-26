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
#define PI 3.14159265

using namespace std;

bool p[16384];
int n, ans;

int main() {

	memset(p, 0xff, sizeof(p));
	p[0] = p[1] = false;
	for (int i = 2; i <= 10000; ++ i)
		if (p[i]) {
			for (int j = i + i; j <= 10000; j += i)
				p[j] = false;
		}

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		ans = 0;
		for (int i = 2; i <= n/2; ++ i)
			if (p[i] && p[n-i] && (i+i != n)) ans ++;
		printf("%d\n", ans);
	}

    return 0;
}
