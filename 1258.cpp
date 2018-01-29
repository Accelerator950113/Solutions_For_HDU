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
#include <sstream>

using namespace std;

map < int, int > M;
int t, n, x;
int ans;
int a[128], b[128], c[128];
bool fst;

void dfs(int dep, int tot) {
	if (tot > t) return;
	if (tot == t) {
		ans ++;
		fst = true;
		for (int i = 1; i < dep; ++ i)
			for (int j = 0; j < c[i]; ++ j) {
				if (fst) fst = false;
				else printf("+");
				printf("%d", a[i]);
			}
		printf("\n");
		return;
	}
	if (dep > n) return;
	for (c[dep] = b[dep]; c[dep] >= 0; -- c[dep])
		dfs(dep+1, tot + c[dep]*a[dep]);
}

int main() {

	while (scanf("%d%d", &t, &n) == 2) {
		if (t == 0 && n == 0) break;
		M.clear();
		while (n --) {
			scanf("%d", &x);
			M[x] ++;
		}
		n = 0;
		for (map < int, int > :: iterator it = M.begin(); it != M.end(); ++ it) 
			a[++ n] = it -> first, b[n] = it -> second;
		reverse(a+1, a+n+1);
		reverse(b+1, b+n+1);
		printf("Sums of %d:\n", t);
		ans = 0;
		dfs(1, 0);
		if (ans == 0) printf("NONE\n");
	}

    return 0;
}