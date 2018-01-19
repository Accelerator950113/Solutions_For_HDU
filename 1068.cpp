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

int n,u,v,m;
bool vi[32768];
vector < int > G[32768];
int link[32768];

bool dfs(int x) {
	if (vi[x]) return false;
	vi[x] = true;
	for (int i = 0;i < G[x].size();++ i)
		if ((link[G[x][i]] == -1) || dfs(link[G[x][i]])) {
			link[G[x][i]] = x;
			return true;
		}
	return false;
}

int main() {

	while (scanf("%d",&n) == 1) {
		for (int i = 1;i <= n;++ i) {
			scanf("%d: (%d)",&u,&m);
			G[u].clear();
			while (m --) {
				scanf("%d",&v);
				G[u].push_back(v);
			}
		}
		memset(link,0xff,sizeof(int) * (n + 3));
		int ans = 0;
		for (int i = 0;i < n;++ i) {
			memset(vi,0,sizeof(bool) * (n + 3));
			if (dfs(i)) ans ++;
		}
		printf("%d\n",n - (ans >> 1));
	}
    
    return 0;
}
