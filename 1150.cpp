#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m,k,a,b,c,ans;
bool g[512][512];
int link[512];
bool v[512];

bool dfs(int x) {
	if (v[x]) return false;
	v[x] = true;
	for (int i = 1;i <= m;++ i) 
		if (g[x][n + i]) {
			if ((link[n + i] == -1) || (dfs(link[n + i]))) {
				link[n + i] = x;
				return true;
			}
		}
	return false;
}

int main() {

    while (scanf("%d",&n) == 1) {
        if (n == 0) break;
        scanf("%d%d",&m,&k);
        memset(g,0,sizeof(g));
        memset(link,0xff,sizeof(link));
        while (k --) {
        	scanf("%d%d%d",&a,&b,&c);
        	if ((b == 0) || (c == 0)) continue;
        	g[b][c + n] = true;
        }
        ans = 0;
        for (int i = 1;i <= n;++ i) {
        	memset(v,0,sizeof(v));
        	if (dfs(i)) ans ++;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
