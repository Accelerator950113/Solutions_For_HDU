#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int T,n,k,b,c,ans;
bool g[512][512];
int link[512];
bool v[512];

bool dfs(int x) {
	if (v[x]) return false;
	v[x] = true;
	for (int i = 1;i <= n;++ i) 
		if (g[x][n + i]) {
			if ((link[n + i] == -1) || (dfs(link[n + i]))) {
				link[n + i] = x;
				return true;
			}
		}
	return false;
}

int main() {

    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        scanf("%d",&k);
        memset(g,0,sizeof(g));
        memset(link,0xff,sizeof(link));
        while (k --) {
        	scanf("%d%d",&b,&c);
        	g[b][c + n] = true;
        }
        ans = 0;
        for (int i = 1;i <= n;++ i) {
        	memset(v,0,sizeof(v));
        	if (dfs(i)) ans ++;
        }
        printf("%d\n",n - ans);
    }
    
    return 0;
}
