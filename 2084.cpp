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

int n, T;
int a[128][128];

int main() {

	scanf("%d", &T);
	while (T --) {
		scanf("%d" ,&n);
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= i; ++ j)
				scanf("%d", &a[i][j]);
		for (int i = 2; i <= n; ++ i) {
			a[i][1] += a[i-1][1];
			a[i][i] += a[i-1][i-1];
			for (int j = 2; j < i; ++ j)
				a[i][j] += max(a[i-1][j], a[i-1][j-1]);
		}
		int ans = a[n][1];
		for (int i = 2; i <= n; ++ i)
			ans = max(ans, a[n][i]);
		printf("%d\n", ans);
	}

    return 0;
}
