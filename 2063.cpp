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

int link[1024];
bool v[1024];
vector < int > g[1024];
int n, m, k;
int x, y;
int ans;

bool find(int cnt) {
	if (v[cnt]) return false;
	v[cnt] = true;
	for (int i = 0; i < g[cnt].size(); ++ i)
		if ((link[g[cnt][i]] == -1) || (find(link[g[cnt][i]]))) {
			link[g[cnt][i]] = cnt;
			return true;
		}
	return false;
}

int main() {

	while ((scanf("%d", &k) != EOF) && (k != 0)) {
		scanf("%d%d", &n, &m);
		memset(link, 0xff, sizeof(link));
		for (int i = 1; i <= n; ++ i)
			g[i].clear();
		while (k --) {
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
		}
		ans = 0;
		for (int i = 1; i <= n; ++ i) {
			memset(v, 0, sizeof(v));
			if (find(i)) ans ++;
		}
		printf("%d\n", ans);
	}

    return 0;
}
