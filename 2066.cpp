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

struct node {
	int yy, dd;
	node() {}
	node(int _y, int _d) {
		yy = _y;
		dd = _d;
	}
};

vector < int > D;
vector < node > g[1024];
int dis[1024];
bool v[1024];
int t, s, d;
int x, y, ti;
int mid, mm;

int main() {

	while (scanf("%d%d%d", &t, &s, &d) != EOF) {
		for (int i = 0; i <= 1000; ++ i)
			g[i].clear();
		while (t --) {
			scanf("%d%d%d", &x, &y, &ti);
			g[x].push_back(node(y, ti));
			g[y].push_back(node(x, ti));
		}
		while (s --) {
			scanf("%d", &x);
			g[0].push_back(node(x, 0));
		}
		D.clear();
		while (d --) {
			scanf("%d", &x);
			D.push_back(x);
		}
		memset(dis, 0x3f, sizeof(dis));
		memset(v, 0, sizeof(v));
		dis[0] = 0;
		while (true) {
			mm = dis[1022], mid = -1;
			for (int i = 0; i <= 1000; ++ i)
				if ((!v[i]) && (mm > dis[i])) mm = dis[i], mid = i;
			if (mid < 0) break;
			v[mid] = true;
			for (int i = 0; i < g[mid].size(); ++ i)
				dis[g[mid][i].yy] = min(dis[g[mid][i].yy], dis[mid] + g[mid][i].dd);
		}	
		int ans = dis[1022];
		for (int i = 0; i < D.size(); ++ i)
			ans = min(ans, dis[D[i]]);
		printf("%d\n", ans);
	}

    return 0;
}
