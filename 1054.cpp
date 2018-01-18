#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define getmin(x,y) ((x < y) ? (x) : (y))

using namespace std;

vector < int > G[2048];
int f[2048][2];
bool v[2048];
int n;

int gi() {
	int ts = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch)) {
		ts = ts * 10 + (ch - '0');
		ch = getchar();
	}
	return ts;
}

void dfs(int x) {
	v[x] = true;
	f[x][0] = 0;
	f[x][1] = 1;
	for (int i = 0;i < G[x].size();++ i)
		if (!v[G[x][i]]) {
			dfs(G[x][i]);
			f[x][0] += f[G[x][i]][1];
			f[x][1] += getmin(f[G[x][i]][0],f[G[x][i]][1]);
		}
}

int main() {

	while (scanf("%d",&n) == 1) {
		for (int i = 1;i <= n;++ i) 
			G[i].clear();
		int x,y,m;
		for (int i = 1;i <= n;++ i) {
			x = gi();
			++ x;
			m = gi();
			for (int j = 0;j < m;++ j) {
				y = gi();
				++ y;
				G[x].push_back(y);
				G[y].push_back(x);
			}
		}
		memset(v,0,sizeof(v));
		dfs(1);
		printf("%d\n",getmin(f[1][0],f[1][1]));
	}

    return 0;
}
