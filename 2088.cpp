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

int n;
int a[1024];
bool fst = true;

int main() {

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		if (fst) fst = false;
		else putchar('\n');
		a[0] = 0;
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
			a[0] += a[i];
		}
		a[0] /= n;
		int ans = 0;
		for (int i = 1; i <= n; ++ i)
			if (a[i] > a[0]) ans += (a[i] - a[0]);
			else ans += (a[0] - a[i]);
		printf("%d\n", ans/2);
	}

    return 0;
}
