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
char a[2048];

int main() {

	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		scanf("%s", a);
		int l = strlen(a);
		int wei;
		for (int i = 0;i*n < l;i ++) {
			wei = min(l, i*n + n);
			if (i&1) reverse(a + i*n, a + wei);
		}
		for (int i = 0;i < n;++ i)
			for (int j = i;j < l;j += n)
				putchar(a[j]);
		putchar('\n');
	}

    return 0;
}
