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

int n, m;
int a[1024];

int main() {

	a[1] = 2;
	for (int i = 2; i <= 1000; ++ i)
		a[i] = a[i-1] + 2;

	while (scanf("%d%d", &n, &m) == 2) {
		bool fst = true;
		int ts, gs;
		for (int i = 1; i <= n;) {
			ts = 0, gs = 0;
			for (int j = 0; (j < m) && (i <= n); ++ j, ++ i)
				ts += a[i], ++ gs;
			if (fst) fst = false;
			else putchar(' ');
			printf("%d", ts / gs);
		}
		puts("");
	}

    return 0;
}
